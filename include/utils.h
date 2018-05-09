//
// Created by yann on 18-5-9.
//

#ifndef YX_IP_UTILS_H
#define YX_IP_UTILS_H

#include <stdint.h>

#define CMDBUFLEN 100

#define print_debug(str, ...)                       \
    printf(str" - %s:%u\n", ##__VA_ARGS__, __FILE__, __LINE__);

#define print_err(str, ...)                     \
    fprintf(stderr, str, ##__VA_ARGS__);

int run_cmd(char *cmd, ...);
uint32_t sum_every_16bits(void *addr, int count);
uint16_t checksum(void *addr, int count, int start_sum);
int get_address(char *host, char *port, struct sockaddr *addr);
uint32_t parse_ipv4_string(char *addr);
uint32_t min(uint32_t x, uint32_t y);

#endif //YX_IP_UTILS_H
