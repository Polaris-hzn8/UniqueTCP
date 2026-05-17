/**
 * @author: luochenhao
 * @email: lch2022fox@163.com
 * @time: Sun 10 May 2026 18:42:15 CST
 * @brief: 利用npcap操作网卡发送和接收数据包
 */

#include <stdio.h>
#include <platform/sys_plat.h>

int main(void) {
  pcap_t* pcap = pcap_device_open(netdev0_ip, netdev0_hwaddr);
  if (!pcap) {
    printf("pcap_device_open failed\n");
    return 1;
  }
  printf("Hello world\n");
  (void)pcap;
  return 0;
}
