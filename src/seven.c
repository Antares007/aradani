#include "oars.h"
#include <stdio.h>
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
  ρ += 3, A(σ[ρ++].v) O;
}
N(jan) {
  ρ += 3, ρ += 1, C(0);
}
N(da) {
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].v = jara;
  σ[--ρ].v = cda;
  σ[--ρ].v = jan;
  O;
};
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
  p_t o[64], *s = o + (sizeof(o) / sizeof(*o));
  long a = 0, r = 0;
  s[--r].c = ray_ara;
  s[--r].c = ray_da;
  s[--r].c = ray_an;
  two(o, a, r, s);
  seven(o, a, r, s);
  test_gcd(o, a, r, s);
}
