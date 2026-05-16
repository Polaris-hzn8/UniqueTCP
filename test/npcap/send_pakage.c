/**
 * @author: luochenhao
 * @email: lch2022fox@163.com
 * @time: Sun 10 May 2026 18:42:15 CST
 * @brief: 利用npcap操作网卡发送和接收数据包
*/

#include <stdio.h>
#include <platform/sys_plat.h>

int main() {
    pcap_t* pcap = pcap_device_open();


    printf("Hello world")
    return 0;
}

