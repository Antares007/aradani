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
os_queue,           L)IN(L,
os_queue_n,         L)IN(L,
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
and7or,             L)IN(L,
andor,              L)IN(L,
andor4,             L)IN(L,
andor5,             L)IN(L,
or,                 L)IN(L,
or2,                L)IN(L,
or3,                L)IN(L,
or4,                L)IN(L,
or5,          imports);
typedef struct lp_t {
  n_t orelse, thenS, empty, term, variable;
  const char* input;
  Q_t len;
  Q_t pos;
  n_t start_var;
  q_t visited_pos;
  Q_t lrc;
  p_t* solls;
} lp_t;
#define TS(T) T*o=(T*)ο;(void)o
#define Var_(...) {TS(lp_t);Α(__VA_ARGS__) O;}
#define Var(Name) N(Name) Var_
#define VarP(Name) NP(Name) Var_
N(init  ) { C(1); }
N(ps    ){ R(const char*, str); print("%s", str), C(1); }
N(plu   ){ R(Q_t, v); print("%lu", v), C(1); }
N(pld   ){ R(q_t, v); print("%ld", v), C(1); }
N(pnl   ){                      print("\n"     ), C(1); }
N(ppar  ){ R(n_t, n); Α("(", ps, n, and, ")", ps, and2) O; }
Nar(por )(" || ", ps)
Nar(pand)(" && ", ps)
Nar(quot)("\"", ps)
N(drop_n){ R(Q_t, wc); α -= wc; C(1); }
N(drop  ){ α -= 1; C(1); }
N(coll) {
  R(p_t*, oο);
  R(n_t, nar);
  nar(oο, α, ρ, σ);
}
N(soll_pop) {
  R(p_t *, sο);
  if (sο[Ǎ].Q)
    A(sο[--sο[Ǎ].Q].v) C(1);
  else
    C(0);
}
N(soll_push) {
  R(p_t *, sο);
  R(void *, v);
  if ((sο[Ǎ].Q + 1) < sο[Σ].Q)
    sο[sο[Ǎ].Q++].v = v, C(1);
  else
    C(0);
}
N(soll_contains) {
  R(p_t *, sο);
  for (Q_t i = 0; i < sο[Ǎ].Q; i++)
    if (sο[i].v == σ[α - 1].v)
      return C(1);
  C(0);
}
Var(orelse5)(5, o->orelse)
Var(orelse4)(4, o->orelse)
Var(orelse3)(3, o->orelse)
Var(orelse2)(2, o->orelse)
Var(orelse )(1, o->orelse)
Var(thenS5 )(5, o->thenS)
Var(thenS4 )(4, o->thenS)
Var(thenS3 )(3, o->thenS)
Var(thenS2 )(2, o->thenS)
Var(thenS  )(1, o->thenS)
Var(empty  )(o->empty)
Var(term   )(o->term)
Var(var    )(o->variable)

Var(pls    )("+", term)
Var(mns    )("-", term)
Var(mul    )("*", term)
Var(div    )("/", term)
Var(id     )("i", term)
Var(opr    )("(", term)
Var(cpr    )(")", term)
Var(Exp    )(
  Exp, pls, thenS, Exp, thenS,
  Exp, mns, thenS, Exp, thenS, orelse5,
  Exp, div, thenS, Exp, thenS, orelse5,
  Exp, mul, thenS, Exp, thenS, orelse5,
  opr, Exp, thenS, cpr, thenS, orelse5,
                           id, orelse,
  Exp,  var)
Var(term_a )("a", term)
Var(term_b )("b", term)
Var(term_o )("o", term)
Var(term_s )("s", term)
Var(Sa     )(
  Sa, term_a, thenS,
      term_b,        orelse,
                         Sa, var)
Var(sS     )(term_s, sS, thenS, sS, thenS,
              empty, orelse, sS, var)


Var(sTs    )(term_a, term_s, thenS, term_a, thenS, sTs, var)
Var(sOs    )(term_a, empty, orelse, sOs, var)

NP(match_input ) { TS(lp_t);
  R(const char*, str);
  R(Q_t, pos);
  Α(pos) C(pos < o->len && (Q_t)o->input[pos] == (Q_t)str[0]);
}
NP(inc_pos     ) { TS(lp_t);
  R(Q_t, pos);
  Α(pos + 1) C(1);
}
//  CPS recognizers
//  VP → V NP |
//       V S
//  (define (VP continuation pos)
//    (begin
//      (V (lambda (pos1) (NP continuation pos1)) pos)
//      (V (lambda (pos1) (S continuation pos1)) pos)))
//  (define (VP continuation pos result)
//    (V (lambda (pos1 result1) (NP continuation pos1 result1)) pos
//      (V (lambda (pos1 result1) (S continuation pos1 result1)) pos result)))
//  (define (terminal word)
//    (lambda (continuation pos)
//      (if (and (pair? pos) (eq? (car pos) word))
//        (continuation (cdr pos)))))
//  (define (alt alt1 alt2)
//    (lambda (continuation pos)
//      (begin
//        (alt1 continuation pos)
//        (alt2 continuation pos))))
//  (define (seq seq1 seq2)
//    (lambda (cont pos)
//      (seq1 (lambda (pos1) (seq2 cont pos1)) pos)))

N(or_r_n      ) { TS(lp_t);
  R(p_t*, rhs);
  Α(dot,
    rhs, os_unsoll_free, dot, and,
    rhs,   os_soll_free, gor, and,                            044, nar) O; }
VarP(or_r  )(os_soll_n, or_r_n, and)

N(ts_r_n      ) { TS(lp_t);
  R(p_t*, rhs);
  Α(dot,
    rhs, os_unsoll_free, dot, and,
    rhs,   os_soll_free, gor, and,                            044, nar) O; }
VarP(ts_r  )(os_soll_n, ts_r_n, and)

//(p ‘orelse‘ q) j = unite (p j) (q j)
VarP(em_r  )(god)
VarP(tr_r  )(match_input, inc_pos, and)
VarP(va_r  )(drop, dot, and)

N(parser_pith);N(parse);
Nar(example)(0, sTs, "asas", 0, parser_pith, parse, and, os_wordump, and)

Q_t cslen(const char *cs);

N(parser_pith) {
  R(Q_t,    pos);
  R(char *, input);
  // n_tx6 input len pos start_var visited_pos lrc solls
  Α(or_r, ts_r, em_r, tr_r, va_r,
    input, cslen(input), pos, 0, -1, 0,
    0,  os_soll_n,
    12, os_soll_n, and2) O;
}
N(print_pith) { R(lp_t*, pp); print("pos: %lu\n", pp->pos), C(1); }
N(parse) {
  R(lp_t *, pp);
  R(n_t, start_var);
  Α(start_var, pp, coll, pp, print_pith, and2) O;
}

N(მთავარი  ) { Α(example) O; }

// clang-format off
EN(tail,
მთავარი,      exports);
Q_t cslen(const char *cs) { Q_t len = 0; while (cs[len]) len++; return len; }

//N(np);N(pp);N(vp);N(det);N(verb);N(prep);N(noun);
//Var(s   )(np, vp, s, pp);
//Var(np  )(noun, det, noun, np, pp)
//Var(pp  )(prep, np)
//Var(vp  )(verb, np)
//Var(det )('a', o->ο, 't')
//Var(noun)('i', o->ο, 'm', o->ο, 'p', o->ο, 'b')
//Var(verb)('s')