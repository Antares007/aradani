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
os_roll,            L)IN(L,
os_soll,            L)IN(L,
os_soll_dup,        L)IN(L,
os_soll_free,       L)IN(L,
os_soll_n,          L)IN(L,
os_unroll,          L)IN(L,
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
N(ps        ){ R(const char*, str); print("%s", str), C(1); }
N(pnl       ){ print("\n"), C(1); }
N(drop      ){ VLog; α--, C(1); }
N(Ο         ){ VLog; O; }
N(Τnn       ){ VLog; R(p_t*, rhsoll); Α( dot,rhsoll, os_soll_free, and2) O; }
N(Τn        ){ VLog; Α(os_soll_n, Τnn, and) O; }
N(ε         ){ VLog; Α("ε", ps, pnl, and,
                                dot, and,
                                god, and,
                                god, and,
                                god, and) O; }
N(Ξ         ){ VLog; Α(ps, pnl, and, dot, and) O; } 
N(Ϋ         ){ VLog; R(const char*, name); R(n_t, svar); print("\t%s %p\n", name, svar); O; }
N(Τ         ){ Α(1, Τn) O; }
N(Τ2        ){ Α(2, Τn) O; }
Var(o,                "o", Ξ)
Var(b,                "b", Ξ)
Var(B,                "B", Ξ)
Var(a,                "a", Ξ)
Var(s,                "s", Ξ)
Var(εΟaΟsoΤΟSoΤΟSbΤBΤ,  ε,
                    Ο,  a,
                    Ο,  s, o, Τ,
                    Ο,  εΟaΟsoΤΟSoΤΟSbΤBΤ, o, Τ,
                    Ο,  εΟaΟsoΤΟSoΤΟSbΤBΤ, b, Τ, B, Τ)
Var(εΟs,                ε, Ο, s)
Var(ssΤ,                s, s, Τ)
Var(bΟSaΤ,              b, Ο, bΟSaΤ, a, Τ)

N(pgod      ){ VLog; print("---->%lu\n", ο[0].Q), C(1); }
N(prn       ){ VLog; R(p_t*, s); Α(s[Ǎ].Q, os_wordump) O; }
Nar(example )(pgod, εΟs)

Nar(მთავარი   )(example)
Nar(init)(god)
// clang-format off
EN(tail,
მთავარი,      exports);
