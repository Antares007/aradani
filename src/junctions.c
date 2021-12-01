#include "importexportmacros.h"
#include "oars.h"
#define D1 ρ += 1,
#define D2 ρ += 2,
#define D3 ρ += 3,
#define D4 ρ += 4,
#define D5 ρ += 5,
#define D6 ρ += 6,
#define D7 ρ += 7,
#define SO1 ο[α++].v = σ[ρ++].v,
#define SO2 SO1 SO1
#define SO3 SO2 SO1
#define SO4 SO3 SO1
#define SO5 SO4 SO1
#define SO6 SO5 SO1
#define SO7 SO6 SO1
#define OS1 σ[--ρ].c = ο[--α].c,
#define OS2 OS1 OS1
#define OS3 OS2 OS1
#define OS4 OS3 OS1
#define OS5 OS4 OS1
#define OS6 OS5 OS1
#define OS7 OS6 OS1
#define C0 C(0)
#define C1 C(1)
#define C2 C(2)
#define Ray3(a, b, c)                                                          \
  static N(a##_##b##_##c) { a b c; }
#define Ray4(a, b, c, d)                                                       \
  static N(a##_##b##_##c##_##d) { a b c d; }
#define Ray5(a, b, c, d, e)                                                    \
  static N(a##_##b##_##c##_##d##_##e) { a b c d e; }
#define Junction(a, b, c, d, e)                                                \
  N(a) { b σ[--ρ].v = c, σ[--ρ].v = d, σ[--ρ].v = e, O; }
#define AND(Tail, Name, Pc, Head)                                              \
  Ray3(D3, D##Pc, C0);                                                         \
  Ray3(D3, SO##Pc, O);                                                         \
  Ray3(D3, D##Pc, C2);                                                         \
  Junction(Name, OS##Pc, D3_D##Pc##_C2, D3_SO##Pc##_O, D3_D##Pc##_C0);         \
  EN(Tail, Name, Head)
#define ANDOR(Tail, Name, PcAnd, PcOr, Head)                                   \
  Ray4(D3, D##PcAnd, D##PcOr, C2);                                             \
  Ray4(D3, SO##PcAnd, D##PcOr, O);                                             \
  Ray4(D3, D##PcAnd, SO##PcOr, O);                                             \
  Junction(Name, OS##PcOr OS##PcAnd, D3_D##PcAnd##_D##PcOr##_C2,               \
           D3_SO##PcAnd##_D##PcOr##_O, D3_D##PcAnd##_SO##PcOr##_O);            \
  EN(Tail, Name, Head)
#define NOT(Tail, Name, Pc, Head)                                              \
  Ray3(D3, D##Pc, C1);                                                         \
  Junction(Name, OS##Pc, D3_SO##Pc##_O, D3_D##Pc##_C1, D3_D##Pc##_C0);         \
  EN(Tail, Name, Head)
#define NOTAND(Tail, Name, PcNot, PcAnd, Head)                                 \
  Ray4(D3, D##PcNot, D##PcAnd, C0);                                            \
  Junction(Name, OS##PcAnd OS##PcNot, D3_SO##PcNot##_D##PcAnd##_O,             \
           D3_D##PcNot##_SO##PcAnd##_O, D3_D##PcNot##_D##PcAnd##_C0);          \
  EN(Tail, Name, Head)
#define NOTOR(Tail, Name, PcNot, PcOr, Head)                                   \
  Ray4(D3, D##PcNot, D##PcOr, C1);                                             \
  Junction(Name, OS##PcOr OS##PcNot, D3_SO##PcNot##_D##PcOr##_O,               \
           D3_D##PcNot##_D##PcOr##_C1, D3_D##PcNot##_SO##PcOr##_O);            \
  EN(Tail, Name, Head)
#define OR(Tail, Name, Pc, Head)                                               \
  Junction(Name, OS##Pc, D3_D##Pc##_C2, D3_D##Pc##_C1, D3_SO##Pc##_O);         \
  EN(Tail, Name, Head)
#define NOTANDOR(Tail, Name, PcNot, PcAnd, PcOr, Head)                         \
  Ray5(D3, D##PcOr, D##PcAnd, SO##PcNot, O);                                   \
  Ray5(D3, D##PcOr, SO##PcAnd, D##PcNot, O);                                   \
  Ray5(D3, SO##PcOr, D##PcAnd, D##PcNot, O);                                   \
  N(Name) {                                                                    \
    OS3 σ[--ρ].c = D3_D##PcOr##_D##PcAnd##_SO##PcNot##_O;                      \
    σ[--ρ].c = D3_D##PcOr##_SO##PcAnd##_D##PcNot##_O;                          \
    σ[--ρ].c = D3_SO##PcOr##_D##PcAnd##_D##PcNot##_O;                          \
    O;                                                                         \
  }                                                                            \
  EN(Tail, Name, Head)
static N(got) { C(2); }
// clang-format off
AND(got,
and,              1,                  L)     AND(L,
and2,             2,                  L)   ANDOR(L,
and2or,           2,1,                L)   ANDOR(L,
and2or2,          2,2,                L)   ANDOR(L,
and2or3,          2,3,                L)   ANDOR(L,
and2or4,          2,4,                L)   ANDOR(L,
and2or5,          2,5,                L)   ANDOR(L,
and2or6,          2,6,                L)   ANDOR(L,
and2or7,          2,7,                L)     AND(L,
and3,             3,                  L)   ANDOR(L,
and3or,           3,1,                L)   ANDOR(L,
and3or2,          3,2,                L)   ANDOR(L,
and3or3,          3,3,                L)   ANDOR(L,
and3or4,          3,4,                L)   ANDOR(L,
and3or5,          3,5,                L)   ANDOR(L,
and3or6,          3,6,                L)   ANDOR(L,
and3or7,          3,7,                L)     AND(L,
and4,             4,                  L)   ANDOR(L,
and4or,           4,1,                L)   ANDOR(L,
and4or2,          4,2,                L)   ANDOR(L,
and4or3,          4,3,                L)   ANDOR(L,
and4or4,          4,4,                L)   ANDOR(L,
and4or5,          4,5,                L)   ANDOR(L,
and4or6,          4,6,                L)   ANDOR(L,
and4or7,          4,7,                L)     AND(L,
and5,             5,                  L)   ANDOR(L,
and5or,           5,1,                L)   ANDOR(L,
and5or2,          5,2,                L)   ANDOR(L,
and5or3,          5,3,                L)   ANDOR(L,
and5or4,          5,4,                L)   ANDOR(L,
and5or5,          5,5,                L)   ANDOR(L,
and5or6,          5,6,                L)   ANDOR(L,
and5or7,          5,7,                L)     AND(L,
and6,             6,                  L)   ANDOR(L,
and6or,           6,1,                L)   ANDOR(L,
and6or2,          6,2,                L)   ANDOR(L,
and6or3,          6,3,                L)   ANDOR(L,
and6or4,          6,4,                L)   ANDOR(L,
and6or5,          6,5,                L)   ANDOR(L,
and6or6,          6,6,                L)   ANDOR(L,
and6or7,          6,7,                L)     AND(L,
and7,             7,                  L)   ANDOR(L,
and7or,           7,1,                L)   ANDOR(L,
and7or2,          7,2,                L)   ANDOR(L,
and7or3,          7,3,                L)   ANDOR(L,
and7or4,          7,4,                L)   ANDOR(L,
and7or5,          7,5,                L)   ANDOR(L,
and7or6,          7,6,                L)   ANDOR(L,
and7or7,          7,7,                L)   ANDOR(L,
andor,            1,1,                L)   ANDOR(L,
andor2,           1,2,                L)   ANDOR(L,
andor3,           1,3,                L)   ANDOR(L,
andor4,           1,4,                L)   ANDOR(L,
andor5,           1,5,                L)   ANDOR(L,
andor6,           1,6,                L)   ANDOR(L,
andor7,           1,7,                L)     NOT(L,
not,              1,                  L)     NOT(L,
not2,             2,                  L)  NOTAND(L,
not2and,          2,1,                L)  NOTAND(L,
not2and2,         2,2,                L)NOTANDOR(L,
not2and2or,       2,2,1,              L)NOTANDOR(L,
not2and2or2,      2,2,2,              L)NOTANDOR(L,
not2and2or3,      2,2,3,              L)  NOTAND(L,
not2and3,         2,3,                L)NOTANDOR(L,
not2and3or,       2,3,1,              L)NOTANDOR(L,
not2and3or2,      2,3,2,              L)NOTANDOR(L,
not2and3or3,      2,3,3,              L)  NOTAND(L,
not2and4,         2,4,                L)  NOTAND(L,
not2and5,         2,5,                L)  NOTAND(L,
not2and6,         2,6,                L)  NOTAND(L,
not2and7,         2,7,                L)NOTANDOR(L,
not2andor,        2,1,1,              L)NOTANDOR(L,
not2andor2,       2,1,2,              L)NOTANDOR(L,
not2andor3,       2,1,3,              L)   NOTOR(L,
not2or,           2,1,                L)   NOTOR(L,
not2or2,          2,2,                L)   NOTOR(L,
not2or3,          2,3,                L)   NOTOR(L,
not2or4,          2,4,                L)   NOTOR(L,
not2or5,          2,5,                L)   NOTOR(L,
not2or6,          2,6,                L)   NOTOR(L,
not2or7,          2,7,                L)     NOT(L,
not3,             3,                  L)  NOTAND(L,
not3and,          3,1,                L)  NOTAND(L,
not3and2,         3,2,                L)NOTANDOR(L,
not3and2or,       3,2,1,              L)NOTANDOR(L,
not3and2or2,      3,2,2,              L)NOTANDOR(L,
not3and2or3,      3,2,3,              L)  NOTAND(L,
not3and3,         3,3,                L)NOTANDOR(L,
not3and3or,       3,3,1,              L)NOTANDOR(L,
not3and3or2,      3,3,2,              L)NOTANDOR(L,
not3and3or3,      3,3,3,              L)  NOTAND(L,
not3and4,         3,4,                L)  NOTAND(L,
not3and5,         3,5,                L)  NOTAND(L,
not3and6,         3,6,                L)  NOTAND(L,
not3and7,         3,7,                L)NOTANDOR(L,
not3andor,        3,1,1,              L)NOTANDOR(L,
not3andor2,       3,1,2,              L)NOTANDOR(L,
not3andor3,       3,1,3,              L)   NOTOR(L,
not3or,           3,1,                L)   NOTOR(L,
not3or2,          3,2,                L)   NOTOR(L,
not3or3,          3,3,                L)   NOTOR(L,
not3or4,          3,4,                L)   NOTOR(L,
not3or5,          3,5,                L)   NOTOR(L,
not3or6,          3,6,                L)   NOTOR(L,
not3or7,          3,7,                L)     NOT(L,
not4,             4,                  L)  NOTAND(L,
not4and,          4,1,                L)  NOTAND(L,
not4and2,         4,2,                L)  NOTAND(L,
not4and3,         4,3,                L)  NOTAND(L,
not4and4,         4,4,                L)  NOTAND(L,
not4and5,         4,5,                L)  NOTAND(L,
not4and6,         4,6,                L)  NOTAND(L,
not4and7,         4,7,                L)   NOTOR(L,
not4or,           4,1,                L)   NOTOR(L,
not4or2,          4,2,                L)   NOTOR(L,
not4or3,          4,3,                L)   NOTOR(L,
not4or4,          4,4,                L)   NOTOR(L,
not4or5,          4,5,                L)   NOTOR(L,
not4or6,          4,6,                L)   NOTOR(L,
not4or7,          4,7,                L)     NOT(L,
not5,             5,                  L)  NOTAND(L,
not5and,          5,1,                L)  NOTAND(L,
not5and2,         5,2,                L)  NOTAND(L,
not5and3,         5,3,                L)  NOTAND(L,
not5and4,         5,4,                L)  NOTAND(L,
not5and5,         5,5,                L)  NOTAND(L,
not5and6,         5,6,                L)  NOTAND(L,
not5and7,         5,7,                L)   NOTOR(L,
not5or,           5,1,                L)   NOTOR(L,
not5or2,          5,2,                L)   NOTOR(L,
not5or3,          5,3,                L)   NOTOR(L,
not5or4,          5,4,                L)   NOTOR(L,
not5or5,          5,5,                L)   NOTOR(L,
not5or6,          5,6,                L)   NOTOR(L,
not5or7,          5,7,                L)     NOT(L,
not6,             6,                  L)  NOTAND(L,
not6and,          6,1,                L)  NOTAND(L,
not6and2,         6,2,                L)  NOTAND(L,
not6and3,         6,3,                L)  NOTAND(L,
not6and4,         6,4,                L)  NOTAND(L,
not6and5,         6,5,                L)  NOTAND(L,
not6and6,         6,6,                L)  NOTAND(L,
not6and7,         6,7,                L)   NOTOR(L,
not6or,           6,1,                L)   NOTOR(L,
not6or2,          6,2,                L)   NOTOR(L,
not6or3,          6,3,                L)   NOTOR(L,
not6or4,          6,4,                L)   NOTOR(L,
not6or5,          6,5,                L)   NOTOR(L,
not6or6,          6,6,                L)   NOTOR(L,
not6or7,          6,7,                L)     NOT(L,
not7,             7,                  L)  NOTAND(L,
not7and,          7,1,                L)  NOTAND(L,
not7and2,         7,2,                L)  NOTAND(L,
not7and3,         7,3,                L)  NOTAND(L,
not7and4,         7,4,                L)  NOTAND(L,
not7and5,         7,5,                L)  NOTAND(L,
not7and6,         7,6,                L)  NOTAND(L,
not7and7,         7,7,                L)   NOTOR(L,
not7or,           7,1,                L)   NOTOR(L,
not7or2,          7,2,                L)   NOTOR(L,
not7or3,          7,3,                L)   NOTOR(L,
not7or4,          7,4,                L)   NOTOR(L,
not7or5,          7,5,                L)   NOTOR(L,
not7or6,          7,6,                L)   NOTOR(L,
not7or7,          7,7,                L)  NOTAND(L,
notand,           1,1,                L)  NOTAND(L,
notand2,          1,2,                L)NOTANDOR(L,
notand2or,        1,2,1,              L)NOTANDOR(L,
notand2or2,       1,2,2,              L)NOTANDOR(L,
notand2or3,       1,2,3,              L)  NOTAND(L,
notand3,          1,3,                L)NOTANDOR(L,
notand3or,        1,3,1,              L)NOTANDOR(L,
notand3or2,       1,3,2,              L)NOTANDOR(L,
notand3or3,       1,3,3,              L)  NOTAND(L,
notand4,          1,4,                L)  NOTAND(L,
notand5,          1,5,                L)  NOTAND(L,
notand6,          1,6,                L)  NOTAND(L,
notand7,          1,7,                L)NOTANDOR(L,
notandor,         1,1,1,              L)NOTANDOR(L,
notandor2,        1,1,2,              L)NOTANDOR(L,
notandor3,        1,1,3,              L)   NOTOR(L,
notor,            1,1,                L)   NOTOR(L,
notor2,           1,2,                L)   NOTOR(L,
notor3,           1,3,                L)   NOTOR(L,
notor4,           1,4,                L)   NOTOR(L,
notor5,           1,5,                L)   NOTOR(L,
notor6,           1,6,                L)   NOTOR(L,
notor7,           1,7,                L)      OR(L,
or,               1,                  L)      OR(L,
or2,              2,                  L)      OR(L,
or3,              3,                  L)      OR(L,
or4,              4,                  L)      OR(L,
or5,              5,                  L)      OR(L,
or6,              6,                  L)      OR(L,
or7,              7, notandor_junctions);
