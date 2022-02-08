#include "arsi.h"
#include "gotgod.h"
#include "os/queue.h"

// clang-format off
IBS(                L)IF(L,
printf, print,      L, int, const char*, ...)IN(L,
os_next,            L)IN(L,
os_queue,     imports);
// clang-format on

SP(ray_not) {}
SP(ray_oor) {
  //R(p_t *, oο);
  //A4(ο, gor, oο, os_queue) O;
}
static p_t ο[1024];
static void init() {
  print("%s\n", __FILE__);
  ο[0].v = ο;
  ο[1].Q = sizeof(ο) / sizeof(*ο);

  QUEUE_INIT((QUEUE*)&ο[2]);

  ο[--ο[1].Q].v = ray_not;
  ο[--ο[1].Q].v = os_next;
  ο[--ο[1].Q].v = ray_oor;
}
// clang-format off
EBS(                L)EN(L,
ο,            exports);
