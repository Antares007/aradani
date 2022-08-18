#include "oars2.h"
N(got) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc; i++)
    σ[α++].v = ο[ρ++].v;
  ρ += ac + oc;
  nc ? O : got(T);
}
N(god) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc;
  for (Q_t i = 0; i < ac; i++)
    σ[α++].v = ο[ρ++].v;
  ρ += oc;
  ac ? O : god(T);
}
N(gor) {
  Q_t g = ο[ρ++].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  ρ += nc + ac;
  for (Q_t i = 0; i < oc; i++)
    σ[α++].v = ο[ρ++].v;
  oc ? O : gor(T);
}
N(notandor) {
  Q_t g = σ[--α].Q, nc = g >> 6 & 7, ac = g >> 3 & 7, oc = g >> 0 & 7;
  for (Q_t i = 0; i < nc + ac + oc; i++)
    ο[--ρ].v = σ[--α].v;
  ο[--ρ].Q = g;
  O;
}

N(and) { A(010, notandor) O; }
N(and2) { A(020, notandor) O; }
N(and3) { A(030, notandor) O; }
N(and4) { A(040, notandor) O; }
N(and5) { A(050, notandor) O; }
N(or) { A(001, notandor) O; }
N(or3) { A(003, notandor) O; }
N(or4) { A(004, notandor) O; }
