#include "oars.h"
// In functional compositional style, meaning composing computation
// with functions, we don't have a clearly defined continuation line
// of process execution in time.
// So we use the brute-force algorithms on sets.
// In contrast, Aradani gives us a clearly defined execution line.

// A recognizer corresponding to a construct p | q in the grammar
// is built by combining recognizers for p and q, using the parser
// combinator ‘orelse‘.
// When the composite recognizer is applied to index j, it applies
// p to j, then it applies q to j, and subsequently unites the
// resulting sets.
// A composite recognizer corresponding to a sequence of recognizers
// p q on the right hand side of a grammar rule, is built by combining
// those recognizers using the parser combinator ‘thenS‘.
// When the composite recognizer is applied to an index j, it first
// applies p to j, then it applies q to each index in the set of
// results returned by p. It returns the union of these applications of q.

N(da);
N(da2);
// (p ‘thenS‘ q) j = union (map q (p j))
// e.g., assuming that the input is "ssss", then
// (term_s ‘thenS‘ term_s) 1 => {3}
N(thenS) {
  RN(n_t, rar);
  RN(n_t, lar);
  A2(lar, rar);
}
// (p ‘orelse‘ q) j = unite (p j) (q j)
// e.g, assuming that the input is "ssss", then
// (empty ‘orelse‘ term_s) 2 => {2, 3}
N(orelse) {}
N(term) {
  RN(Q_t, j);
  RN(Q_t, c);
}

N(Ta) {}
N(Tb) {}
N(ǒ) {

  O; 
}
N(BA1) {
  A2("b", term);
  A5("b", term, "a", term, da2);
}
N(BA2) { A10(
  "b", term, ǒ,
  "b", term, da2, "a", term, da2, ǒ
); }
N(S) {
  A1(Tb);
  A3(S, Ta, da);
}
