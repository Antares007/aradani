#include "aradani.h"

N(fun1) { A('fun1') C(, 1); }
N(fun2) { A('fun2') C(, 1); }
N(fun3) { A('fun3') C(, 1); }

n_t nars[] = {fun1, fun2, fun3};
int names[] = {'fun1', 'fun2', 'fun3'};

Oars(z2) {
  volatile n_t t = tail;
  t(T());
}
// int main() {}
