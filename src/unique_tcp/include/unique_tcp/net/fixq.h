#ifndef FIX_H
#define FIX_H

#include <unique_tcp/net/sys.h>
#include <unique_tcp/net/nlocker.h>

typedef struct _fixq_t {
  int size;
  int in, out, cnt;
  void** buf;

  nlocker_t locker;
  sys_sem_t recv_sem;
  sys_sem_t send_sem;
} fixq_t;

net_err_t fixq_init(fixq_t* q, void** buf, int size, nlocker_type_t type);
net_err_t fixq_send(fixq_t* q, void* msg, int tmo);
void* fixq_recv(fixq_t* q, int tmo);
void fixq_destroy(fixq_t* q);
int fixq_count(fixq_t* q);

#endif