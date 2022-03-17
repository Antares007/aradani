#pragma once
#include "os/queue.h"
#define Q_PREV(h)           (((p_t *)QUEUE_PREV((QUEUE*)(h - 3))) + 3)
#define Q_NEXT(h)           (((p_t *)QUEUE_NEXT((QUEUE*)(h - 3))) + 3)
#define Q_REMOVE(h)         QUEUE_REMOVE((QUEUE*)(h - 3))
#define Q_INSERT_TAIL(h, q) QUEUE_INSERT_TAIL((QUEUE*)(h - 3), (QUEUE*)(q - 3))
#define Q_INSERT_HEAD(h, q) QUEUE_INSERT_HEAD((QUEUE*)(h - 3), (QUEUE*)(q - 3))
