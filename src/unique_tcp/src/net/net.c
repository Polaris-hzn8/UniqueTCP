
#include <unique_tcp/net/net.h>

#include <unique_tcp/net/arp.h>
#include <unique_tcp/net/dbg.h>
#include <unique_tcp/net/dns.h>
#include <unique_tcp/net/ether.h>
#include <unique_tcp/net/exmsg.h>
#include <unique_tcp/net/icmpv4.h>
#include <unique_tcp/net/ipv4.h>
#include <unique_tcp/net/loop.h>
#include <unique_tcp/net/netif.h>
#include <unique_tcp/net/pktbuf.h>
#include <unique_tcp/net/raw.h>
#include <unique_tcp/net/sock.h>
#include <unique_tcp/net/timer.h>
#include <unique_tcp/net/tools.h>
#include <unique_tcp/net/udp.h>
#include <unique_tcp/platform/net_plat.h>

net_err_t net_init(void) {
  dbg_info(DBG_INIT, "init net");

  net_plat_init();

  tools_init();

  exmsg_init();
  pktbuf_init();
  netif_init();

  net_timer_init();

  ether_init();
  arp_init();
  ipv4_init();
  icmpv4_init();

  socket_init();
  raw_init();
  udp_init();
  tcp_init();
  dns_init();

  loop_init();

  return NET_ERR_OK;
}

net_err_t net_start(void) {
  exmsg_start();

  dbg_info(DBG_INIT, "net is running");

  return NET_ERR_OK;
}
