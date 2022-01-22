#include <stdio.h>
typedef struct p_s {
  union {
    void (*c)(struct p_s *, unsigned long, long);
    void *v;
    char b;
    short w;
    int d;
    long q;
    unsigned char B;
    unsigned short W;
    unsigned int D;
    unsigned long Q;
  };
} p_t;
typedef unsigned long Q_t;
#define N(n) void n(p_t *ο, unsigned long α, long ρ)
#define A(a) ο[α++].v = (void *)(a),
#define R(T, n) T n = (T)ο[--α].v
#define C(r) ο[ρ + (r)].c(ο, α, ρ)
#define O ο[α - 1].c(ο, α - 1, ρ)
#include "a20.h"
N(ada_not) {
  ρ += 3;
  Q_t jun = ο[ρ++].Q, nc = (jun & 0700) >> 6, ac = (jun & 0070) >> 3,
      oc = (jun & 0007) >> 0;
  while (nc--)
    ο[α++].v = ο[ρ++].v;
  ρ += ac + oc, O;
}
N(ada_and) {
  ρ += 3;
  Q_t jun = ο[ρ++].Q, nc = (jun & 0700) >> 6, ac = (jun & 0070) >> 3,
      oc = (jun & 0007) >> 0;
  ρ += nc;
  while (ac--)
    ο[α++].v = ο[ρ++].v;
  ρ += oc;
  O;
}
N(ada_oor) {
  ρ += 3;
  Q_t jun = ο[ρ++].Q, nc = (jun & 0700) >> 6, ac = (jun & 0070) >> 3,
      oc = (jun & 0007) >> 0;
  ρ += nc + ac;
  while (oc--)
    ο[α++].v = ο[ρ++].v;
  O;
}
N(ada) {
  Q_t jun = ο[--α].Q,
      tc = ((jun & 0700) >> 6) + ((jun & 0070) >> 3) + ((jun & 0007) >> 0);
  // ρ -= tc, α -= tc, lookup[tc](&ο[ρ].v, &ο[α].v);
  while (tc--)
    ο[--ρ].v = ο[--α].v;
  ο[--ρ].Q = jun, ο[--ρ].c = ada_not, ο[--ρ].c = ada_and, ο[--ρ].c = ada_oor, O;
}
N(one) { A(1) C(1); }
N(add) {
  R(long, r);
  R(long, l);
  A(l + r) C(1);
}
N(jara) { ρ += 3, ρ += 1, C(2); }
N(da) { A(0010) ada(ο, α, ρ); }
N(two) { A5(one, 1, add, 0020, ada) O; }
N(seven) { A13(one, two, da, add, da, two, da, add, da, two, da, add, da) O; }
N(gcd) {
  R(long, y);
  R(long, x);
  if (x < y)
    A3(x, y - x, gcd) O;
  else if (y < x)
    A3(x - y, y, gcd) O;
  else
    A(x) C(1);
}
N(test_gcd) { A3(21, 14, gcd) O; }
N(ray_ara) {}
N(ray_da) {
  R(long, rez);
  printf("da: %ld\n", rez);
}
N(ray_an) {}
int main() {
  p_t o[64];
  long a = 0, r = sizeof(o) / sizeof(*o);
  o[--r].c = ray_ara;
  o[--r].c = ray_da;
  o[--r].c = ray_an;
  seven(o, a, r);
  test_gcd(o, a, r);
}
