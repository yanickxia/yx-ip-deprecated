cmake_minimum_required(VERSION 3.10)
project(yx_ip C)

set(CMAKE_C_STANDARD 99)

include_directories(include)


add_executable(yx_ip main.c
        include/basic.h include/syshead.h include/taptun_if.h src/taptun_if.c include/utils.h src/utils.c include/netdev.h include/skbuff.h include/route.h include/list.h include/ethernet.h src/skbuff.c include/arp.h)