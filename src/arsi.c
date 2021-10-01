#include "arsi.h"
#include "aradani.h"

N(fun1) { A('fun1') C(, 1); }
N(fun2) { A('fun2') C(, 1); }
N(fun3) { A('fun3') C(, 1); }

void head(o_t o, e_t e, r_t r);
void nextf(o_t o, e_t e, r_t r);
static o_t uo = 0;
static b_t no = 0;
static e_t ue = 0;
static r_t ur = 0;
// clang-format off
E(ue, fun1, L)E(L,
      fun2, L)E(L,
      fun3,
export);
// clang-format on
char *imports[] = {};
struct i_s {
  n_t fun1;
};
struct i_s im = {};
int cmp(char *a, char *b) { return 0; }
void tail() __attribute__((section(".text.end")));
void tail(o_t o, e_t e, r_t r) {}
void mo(char *name, void *addr, void *next) {
  no = next;
  for (long i = 0; i < sizeof(imports); i++)
    if (cmp(name, imports[i]))
      ((p_t *)&im)[i].v = addr;
  uo(name, addr, nextf);
}
void me() {
  for (long i = 0; i < sizeof(imports); i++)
    if (((p_t *)&im)[i].v == 0) {
      return ur();
    }
  export(uo, ue);
}
void head() __attribute__((section(".text.begin")));
void head(o_t o, e_t e, r_t r) {
  uo = o;
  ue = e;
  ur = r;
  volatile b_t t = tail;
  t(mo, me, r);
}
void nextf(o_t o, e_t e, r_t r) {
  uo = o;
  ue = e;
  ur = r;
  volatile b_t t = no;
  t(mo, me, r);
}
// int main() {}
