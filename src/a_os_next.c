#include "arsi.h"
#include "gotgod.h"
#include "os/queue.h"

// clang-format off
IBS(                L)IN(L,
os_next,      imports);
// clang-format on

SP(ray_not) {}

static p_t ο[1024];

static void init() {
  ο[0].v = ο;
  ο[1].Q = sizeof(ο) / sizeof(*ο);
  QUEUE_INIT((QUEUE *)&ο[2]);

  ο[--ο[1].Q].v = ray_not;
  ο[--ο[1].Q].v = os_next;
  ο[--ο[1].Q].v = os_next;
}
// clang-format off
EBS(                L)EN(L,
ο,            exports);
