#include "oars.h"
#include <stdio.h>
N(ada);

N(one) { A(1) C(1); }
N(add) {
  R(long, r);
  R(long, l);
  A(l + r) C(1);
}
N(jara) { ρ += 3, ρ += 1, C(2); }
N(da) { A(0010) ada(ο, α, ρ); }
N(two) { A7(one, one, 0010, ada, add, 0010, ada) O; }
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

N(gor) { C(0); }
N(god) { C(1); }
N(got) { C(2); }

N(seven2) { A12(gor, 3, 3, one, 0003, ada, add, 0010, ada, add, 0010, ada) O; }
int main() {
  p_t o[64];
  long a = 0, r = sizeof(o) / sizeof(*o);
  o[--r].c = ray_ara;
  o[--r].c = ray_da;
  o[--r].c = ray_an;
  seven(o, a, r);
  seven2(o, a, r);
  test_gcd(o, a, r);
}
