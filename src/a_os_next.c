#include "arsi.h"
#include "gotgod.h"
#include "queue.h"

// clang-format off
IBS(                L)IF(L,
printf, print,              L, int, const char*, ...)IN(L,
os_queue,     imports);
// clang-format on

static QUEUE main_queue;

SP(os_next) {
  QUEUE *q;
  QUEUE *temp_queue = (QUEUE *)&ο[2];
  if (temp_queue != (q = QUEUE_NEXT(temp_queue))) {
    QUEUE_PREV(q) = QUEUE_PREV(&main_queue);
    QUEUE_PREV_NEXT(temp_queue) = &main_queue;
    QUEUE_PREV_NEXT(&main_queue) = q;
    QUEUE_PREV(&main_queue) = QUEUE_PREV(temp_queue);
    QUEUE_INIT(temp_queue);
  }
  if (&main_queue == (q = QUEUE_NEXT(&main_queue)))
    return C(0);
  σ[0].Q = 0;
  QUEUE_REMOVE(q);
  p_t *b = ((p_t *)q);
  p_t *nσ = b[-3].p;
  Q_t nα = b[-2].Q;
  p_t *oο = b[-1].p;
  dot(nσ, nα, oο, oο[1].Q);
}
SP(ray_not) {}
SP(ray_oor) {
  //R(p_t *, oο);
  //A4(ο, gor, oο, os_queue) O;
}
static p_t ο[1024];
static void init_pith() {
  ο[0].v = ο;
  ο[1].Q = sizeof(ο) / sizeof(*ο);

  QUEUE_INIT((QUEUE *)&ο[2]);

  ο[--ο[1].Q].v = ray_not;
  ο[--ο[1].Q].v = os_next;
  ο[--ο[1].Q].v = ray_oor;
}
static void init() {
  print("%s\n", __FILE__);
  init_pith();
  QUEUE_INIT(&main_queue);
}
// clang-format off
EBS(                L)EN(L,
ο,            exports);
