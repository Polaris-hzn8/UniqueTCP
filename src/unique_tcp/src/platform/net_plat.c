
#include <unique_tcp/net/dbg.h>
#include <unique_tcp/platform/net_plat.h>

net_err_t net_plat_init(void) {
  dbg_info(DBG_PLAT, "init plat...");
  dbg_info(DBG_PLAT, "init done");
  return NET_ERR_OK;
}
