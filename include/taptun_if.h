//
// Created by yann on 18-5-9.
//

#ifndef YX_IP_TAPTUN_IF_H
#define YX_IP_TAPTUN_IF_H

void tun_init();

int tun_read(char *buf, int len);

int tun_write(char *buf, int len);

void free_tun();


#endif //YX_IP_TAPTUN_IF_H
