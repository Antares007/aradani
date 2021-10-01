#include "aradani.h"
#include "arsi.h"

N(fun1) { A('fun1') C(, 1); }
N(fun2) { A('fun2') C(, 1); }
N(fun3) { A('fun3') C(, 1); }

// n_t nars[] = {fun1, fun2, fun3};
// int names[] = {'fun1', 'fun2', 'fun3'};
// long length = sizeof(nars) / sizeof(*nars);

o_t uo;
b_t no = 0;
e_t ue;

// clang-format off
E(ue, fun1, L)E(L,
      fun2, L)E(L,
      fun3,
export);
// clang-format on

void mo(char *name, void *addr, void *next) {
  no = next;
  uo(name, addr, nextf);
}
void me() { export(uo, ue); }
Oars() {
  uo = o;
  ue = e;
  volatile b_t t = tail;
  t(mo, me);
}
void nextf(o_t o, e_t e) {
  uo = o;
  ue = e;
  volatile b_t t = no;
  t(mo, me);
}
// int main() {}
