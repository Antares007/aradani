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
#define N(n) void n(p_t *ο, unsigned long α, long ρ)
#define A(a) ο[α++].v = (void *)(a),
#define R(T, n) T n = (T)ο[--α].v
#define C(r) ο[ρ + (r)].c(ο, α, ρ)
#define O ο[α - 1].c(ο, α - 1, ρ)
#include "a20.h"
// clang-format off
N(one) {
  A(1) C(1);
}
N(add) {
  R(long, r);
  R(long, l);
  A(l + r) C(1);
}
N(jara) {
  ρ += 3, ρ += 1, C(2);
}
N(cda) {
  ρ += 3, A(ο[ρ++].v) O;
}
N(jan) {
  ρ += 3, ρ += 1, C(0);
}
N(da) {
  ο[--ρ].c = ο[--α].c;
  ο[--ρ].v = jara;
  ο[--ρ].v = cda;
  ο[--ρ].v = jan;
  O;
}
N(two) {
  A5(one, one, da, add, da) O;
}
N(seven) {
  A13(one, two, da, add, da, two, da, add, da, two, da, add, da) O;
}
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
N(test_gcd) {
  A3(18, 12, gcd) O;
}
N(ray_ara) {
}
N(ray_da) {
  R(long, rez);
  printf("da: %ld\n", rez);
}
N(ray_an) {
}
int main() {
  p_t o[64];
  long a = 0, r = sizeof(o) / sizeof(*o);
  o[--r].c = ray_ara;
  o[--r].c = ray_da;
  o[--r].c = ray_an;
  two(o, a, r);
  seven(o, a, r);
  test_gcd(o, a, r);
}
