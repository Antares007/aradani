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
and3,               L)IN(L,
and3or,             L)IN(L,
and4,               L)IN(L,
andor,        imports);

N(init         ) { C(1); }

N(spop         ) { R(p_t *, sο); if (sο[Ǎ].Q) A(sο[--sο[Ǎ].Q].v) C(1); else C(2); }
N(spush        ) { R(p_t *, sο); R(void *, v); if ((sο[Ǎ].Q + 1) < sο[Σ].Q) sο[sο[Ǎ].Q++].v = v, C(1); else C(2); }
N(setο         ) { R(p_t *, oο); oο[Φ].p = ο; Α(oο) C(1); }
N(drop         ) { α -= 1, C(1); }
N(drop2        ) { α -= 2, C(1); }
N(drop3        ) { α -= 3, C(1); }
N(swap         ) { R(void *, b); R(void *, a); Α(b, a) C(1); }
N(dup_swap_drop) { Α(os_soll_dup, swap, and, drop, and) O; }
N(soll         ) { Α(os_soll, setο, and) O; }
N(soll_n       ) { Α(os_soll_n, setο, and) O; }
N(apply        ) {
  R(p_t *, pt);
  R(p_t *, oο);
  Α(pt, oο[oο[Ǎ].Q - 1].c, oο, 2, os_queue_n) O;
}
N(variable_ray); N(orelse_ray); N(thenS_ray ); N(empty_ray ); N(term_ray);
N(binary_unsoll_n) {
  R(p_t*, ps);
  R(p_t*, lhsoll);
  p_t *rhsoll = ο[ο[Ǎ].Q - 3].p; n_t ray = ο[ο[Ǎ].Q - 2].c;
  Α(rhsoll, os_unsoll, dot, and, lhsoll, ps, ray, and3) O;
}
N(binary_unsoll) {
  R(p_t *, ps);
  Α(ο, os_unsoll, drop, and, dot, and, ps, binary_unsoll_n, and2) O;
}
N(unary_unsoll) {
  R(p_t *, ps);
  n_t ray = ο[ο[Ǎ].Q - 2].c;
  Α(ο, os_unsoll, drop2, drop, and, soll, and, ps, ray, and2) O;
}
N(variable3) { Α(3, soll_n, variable_ray, binary_unsoll, soll, and3) O; }
N(variable2) { Α(2, soll_n, variable_ray, binary_unsoll, soll, and3) O; }
N(variable ) { Α(1, soll_n, variable_ray, binary_unsoll, soll, and3) O; }
N(orelse3  ) { Α(3, soll_n, orelse_ray,   binary_unsoll, soll, and3) O; }
N(orelse2  ) { Α(2, soll_n, orelse_ray,   binary_unsoll, soll, and3) O; }
N(orelse   ) { Α(1, soll_n, orelse_ray,   binary_unsoll, soll, and3) O; }
N(thenS3   ) { Α(3, soll_n, thenS_ray,    binary_unsoll, soll, and3) O; }
NP(thenS2  ) { Α(2, soll_n, thenS_ray,    binary_unsoll, soll, and3) O; }
N(thenS    ) { Α(1, soll_n, thenS_ray,    binary_unsoll, soll, and3) O; }
N(empty    ) { Α(        0, empty_ray,    unary_unsoll,  soll      ) O; }
N(term     ) { Α(        1, term_ray,     unary_unsoll,  soll      ) O; }

NP(pgod        ) { C(1); }
NP(example     ) { Α("a", term, pgod, variable, "sssss", apply, and2) O; }
NP(variable_ray) { 
}

N(orelse_ray) { }

N(thenS_ray_next) {
  //Α(add_right_simbol_to_nexts_list, and,
  //   continue_on_left_simbol, and) O;
}
// Make a choice, write it down, think like, u already
// have all the data available to make it;
// It is like monad thing, data is hidden behind words.
// Think abstactly at specification level.
NP(thenS_ray) {
  // stop_if_this_path_cant_parse_anything,
  //            2 add_to_counter and2,
  // set_counter_value_for_this_node, and
  //
  //Α(has_id,
  //   counter_add2, set_counter_value_for_id, and,
  //   thenS_ray_next, and3or) O;
  // left_rec_count, tokens_left_plus_1, and, grater_then, and,
  // curtail,
  // thenS_ray_next, andor
}
NP(term_ray ) {
  //Α(match_input, drop_paper, andor) O;
}
N(empty_ray) {
  //Α(goto_next) O;
}

N(dump_paper  );N(paper);
NP(exam_thenS ) { Α("thenS", "s", term, "s", term, thenS2) O; }

N(exam_orelse ) { Α(     empty, 's', term, orelse2) O; }

N(Sa          ) { Α(Sa,         'a', term, thenS2,
                                'b', term, orelse2) O; }


Q_t cslen(const char *cs);
N(მთავარი     ) { Α(example) O; }

// clang-format off
EN(tail,
მთავარი,      exports);

Q_t cslen(const char *cs) {
  Q_t len = 0;
  while (cs[len])
    len++;
  return len;
}
