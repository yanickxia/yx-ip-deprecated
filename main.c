#include <stdio.h>
#include "arp.h"
#include "netdev.h"
#include "utils.h"
#include "taptun_if.h"



int main() {
    printf("it's sample for tcp-ip!\n");
    tun_init();
    netdev_init();
    arp_request(parse_ipv4_string("10.211.55.18"),
                parse_ipv4_string("10.211.55.33"),
                netdev_get(parse_ipv4_string("10.211.55.18")));
    return 0;
}