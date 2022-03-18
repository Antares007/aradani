#pragma once

#define Q_PREV(h)           QUEUE2SOLL(QUEUE_PREV(SOLL2QUEUE(h)))
#define Q_NEXT(h)           QUEUE2SOLL(QUEUE_NEXT(SOLL2QUEUE(h)))
#define Q_REMOVE(h)                  QUEUE_REMOVE(SOLL2QUEUE(h))
#define Q_INSERT_TAIL(h, q)     QUEUE_INSERT_TAIL(SOLL2QUEUE(h), SOLL2QUEUE(q))
#define Q_INSERT_HEAD(h, q)     QUEUE_INSERT_HEAD(SOLL2QUEUE(h), SOLL2QUEUE(q))
