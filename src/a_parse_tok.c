#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_ls,              L)IN(L,
os_new,             L)IN(L,
os_queue,           L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and3or3,            L)IN(L,
and4,               L)IN(L,
and5,               L)IN(L,
and6,               L)IN(L,
and7,               L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor3,             L)IN(L,
not,                L)IN(L,
not2and,            L)IN(L,
not2and2or2,        L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)n_t la;I(L,

"lookahead", la,    L)IN(L,
lookahead_set,      L)IN(L,
parse,              L)IN(L,
shift,        imports);
// clang-format on
static N(Μ) {
  R(n_t, n);
  Α(n, n, Μ, god, and2or) O;
}
N(is_eq) {
  R(Q_t, cp);
  R(p_t *, cps);
  C(cps[0].Q == cp);
}
N(is_neq) {
  R(Q_t, cp);
  R(p_t *, cps);
  C(cps[0].Q != cp);
}
N(ncp) {
  R(Q_t, cp);
  Α(la, cp, is_neq, and2, shift, and) O;
}
N(cp) {
  R(Q_t, cp);
  Α(la, cp, is_eq, and2, shift, and) O;
}
static N(is_anyof) {
  R(const char *, chars);
  R(p_t *, cps);
  while (*chars)
    if (cps[0].Q == *chars++)
      return C(1);
  C(0);
}
static N(anyof) {
  R(const char *, chars);
  Α(la, chars, is_anyof, and2, shift, and) O;
}
static N(is_in_range) {
  R(Q_t, to);
  R(Q_t, from);
  R(p_t *, cps);
  C(from <= cps[0].Q && cps[0].Q <= to);
}
static N(range) {
  R(Q_t, to);
  R(Q_t, from);
  Α(la, from, to, is_in_range, and3, shift, and) O;
}

static N(reduce) {
  Q_t a = α;
  Α(a, os_soll_n) O;
}
static N(ws_cp) { Α(" \t", anyof, os_soll_free, and) O; }
static N(ws) { Α(ws_cp, Μ) O; }
static N(cprn_) { Α(')', cp, 'cprn', reduce, and2) O; }
static N(cprn) { Α(ws, cprn_, and) O; }
static N(oprn_) { Α('(', cp, 'oprn', reduce, and2) O; }
static N(oprn) { Α(ws, oprn_, and) O; }
static N(cmm_) { Α(',', cp, 'cmm', reduce, and2) O; }
static N(cmm) { Α(ws, cmm_, and) O; }
static N(smc_) { Α(';', cp, 'smc', reduce, and2) O; }
static N(smc) { Α(ws, smc_, and) O; }
static N(cln_) { Α(':', cp, 'cln', reduce, and2) O; }
static N(cln) { Α(ws, cln_, and) O; }
static N(nl_) { Α("\n\r", anyof, 'nl', reduce, and2) O; }
static N(nl) { Α(ws, nl_, and) O; }
static N(id_s_cp) { Α('a', 'z', range, 'A', 'Z', range, or3) O; }
static N(id_cp) { Α(id_s_cp, '0', '9', range, or3, '_', cp, or2) O; }
static N(id_n) { Α(id_cp, id_n, god, andor) O; }
static N(id) { Α(ws, id_s_cp, and, id_n, and, 'id', reduce, and2) O; }
static N(lookahead) {
  if (ο[7].p[3].Q == -1) {
    Α(id, nl, or, cln, or, cmm, or, oprn, or, cprn, or, smc, or, lookahead_set,
      and)
    O;
  } else
    A(ο[7].p[3].p) C(1);
}
static N(pos) { Α(ο[7].p[1].Q, god) O; }
static N(prn_a) { Α(pos, got, and, pos, god, and, pos, gor, and, 0333, nar) O; }
N(unsoll) {
  R(p_t *, so);
  Α(so, os_unsoll, so, os_soll_free, and2) O;
}
N(drop) {
  { α--, C(1); }
}
N(lash) { Α(lookahead, drop, and, shift, and) O; }
static N(testuni) { Α(lash, lash, and, lash, and, prn_a) O; }
static N(მთავარი) { Α(testuni, "aaa\r.", parse) O; }
static N(init) { Α(god) O; }

// clang-format off
EN(tail,
lookahead,          L)EN(L, 
lookahead_set,      L)EN(L, 
parse,              L)EN(L, 
prn_a,              L)EN(L, 
shift,              L)EN(L, 
მთავარი,      exports);
