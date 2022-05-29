#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
co0,                L)IN(L,
co1,                L)IN(L,
co2,                L)IN(L,
debugger,           L)IN(L,
dot,                L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
nar,                L)IN(L,
os_call_n,          L)IN(L,
os_queue_clear,     L)IN(L,
os_queue_n,         L)IN(L,
os_queue_soll,      L)IN(L,
os_soll,            L)IN(L,
os_soll_dup,        L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unsoll,          L)IN(L,
os_unsoll_free,     L)IN(L,
os_wordump,         L)IN(L,

and,                L)IN(L,
and2,               L)IN(L,
and2or,             L)IN(L,
and2or2,            L)IN(L,
and2or3,            L)IN(L,
and2or4,            L)IN(L,
and2or5,            L)IN(L,
and2or7,            L)IN(L,
and3,               L)IN(L,
and3or,             L)IN(L,
and3or3,            L)IN(L,
and3or4,            L)IN(L,
and4,               L)IN(L,
and4or,             L)IN(L,
and4or2,            L)IN(L,
and5,               L)IN(L,
and5or,             L)IN(L,
and5or3,            L)IN(L,
and5or4,            L)IN(L,
and6or4,            L)IN(L,
and7,               L)IN(L,
and7or,             L)IN(L,
andor,              L)IN(L,
andor2,             L)IN(L,
andor3,             L)IN(L,
andor4,             L)IN(L,
andor5,             L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)IN(L,
or4,                L)IN(L,
or5,          imports);
#define Var(Name, ...) N(Name) { Α(__VA_ARGS__,   Name, #Name, Ϋ) O; }
#define VarP(Name, ...) NP(Name) { Α(__VA_ARGS__, Name, #Name, Ϋ) O; }
#define VLog print("V "); PLog
  // A recognizer corresponding to a construct p | q in the grammar is built by combining recognizers
  // for p and q, using the parser combinator ‘orelse‘.
  // When the composite recognizer is applied to index j, it applies p to j, then it applies q to j,
  // and subsequently unites the resulting sets.:
  // (p ‘orelse‘ q) j = unite (p j) (q j)
  // e.g, assuming that the input is "ssss", then
  // (empty ‘orelse‘ term_s) 2 => {2, 3}
  // A composite recognizer corresponding to a sequence of recognizers p q on the right hand side of
  // a grammar rule, is built by combining those recognizers using the parser combinator ‘thenS‘.
  // When the composite recognizer is applied to an index j, it first applies p to j, then it applies
  // q to each index in the set of results returned by p. It returns the union of these applications of q.
  // (p ‘thenS‘ q) j = union (map q (p j))
  // e.g., assuming that the input is "ssss", then
  // (term_s ‘thenS‘ term_s) 1 => {3}
N(Ο         ){ VLog; O; }
N(Τn        ){ VLog; Α(os_soll_n, os_soll_free, and, dot, and) O; }
N(ε         ){ VLog; O; }
N(Ε         ){ VLog; α--, O; } 
N(Ϋ         ){ VLog; R(const char*, name); R(n_t, svar); print("%s %p\n", name, svar); O; }

N(Τ         ){ Α(1, Τn) O; }
N(Τ2        ){ Α(2, Τn) O; }
Var(o,                  "o", Ε)
Var(b,                  "b", Ε)
Var(B,                  "B", Ε)
Var(a,                  "a", Ε)
Var(s,                  "s", Ε)
Var(εΟaΟsoΤΟSbΤBΤΟSoΤ,  ε,
                    Ο,  a,
                    Ο,  s, o, Τ,
                    Ο,  εΟaΟsoΤΟSbΤBΤΟSoΤ, b, Τ, B, Τ,
                    Ο,  εΟaΟsoΤΟSbΤBΤΟSoΤ, o, Τ)
Var(εΟs,                ε, Ο, s)
Var(ssΤ,                s, s, Τ)
Var(bΟSaΤ,              b, Ο, bΟSaΤ, a, Τ)

N(pgod      ){ VLog; C(1); }
Nar(example )(pgod, εΟaΟsoΤΟSbΤBΤΟSoΤ)



Nar(მთავარი   )(example)
Nar(init)(god)
// clang-format off
EN(tail,
მთავარი,      exports);
