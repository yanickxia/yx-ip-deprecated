#include <stdio.h>
#include "arp.h"
#include "netdev.h"
#include "utils.h"



int main() {
    printf("it's sample for tcp-ip!\n");
    netdev_init();
    arp_request("10.211.55.18","10.211.55.1", netdev_get(parse_ipv4_string("10.211.55.18")));
    return 0;
}