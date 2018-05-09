//
// Created by yann on 18-5-9.
//

#include "arp.h"
#include "netdev.h"
#include "skbuff.h"
#include "list.h"

static uint8_t broadcast_hw[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };


static struct sk_buff *arp_alloc_skb() {
    struct sk_buff *skb = alloc_skb(ETH_HDR_LEN + ARP_HDR_LEN + ARP_DATA_LEN);
    skb_reserve(skb, ETH_HDR_LEN + ARP_HDR_LEN + ARP_DATA_LEN);
    skb->protocol = htons(ETH_P_ARP);

    return skb;
}

int arp_request(uint32_t sip, uint32_t dip, struct netdev *netdev) {
    struct sk_buff *skb;
    struct arp_hdr *arp;
    struct arp_ipv4 *payload;
    int rc = 0;

    skb = arp_alloc_skb();
    if (!skb) {
        return -1;
    }

    skb->dev = netdev;
    payload = (struct arp_ipv4 *) skb_push(skb, ARP_DATA_LEN);
    // 1.source mac address
    memcpy(payload->smac, netdev->hwaddr, netdev->addr_len);
    // 2.source ip address
    payload->sip = sip;
    // 3.target mac address is broadcast address
    memcpy(payload->dmac, broadcast_hw, netdev->addr_len);
    // 4.target ip address
    payload->dip = dip;

    arp = (struct arp_hdr *) skb_push(skb, ARP_HDR_LEN);
    arp_dbg("req", arp);
    // 1. HW type
    arp->hwtype = htons(ARP_ETHERNET);
    // 2. Protype type is ip
    arp->protype = htons(ETH_P_IP);
    // 3. operation code
    arp->opcode = htons(ARP_REQUEST);
    // 4. hw size
    arp->hwsize = netdev->addr_len;
    // 5. Protype size
    arp->prosize = 4;

    //htol ip
    arpdata_dbg("req", payload);
    payload->sip = htonl(payload->sip);
    payload->dip = htonl(payload->dip);

    rc = netdev_transmit(skb, broadcast_hw, ETH_P_ARP);
    free_skb(skb);
    return rc;

}