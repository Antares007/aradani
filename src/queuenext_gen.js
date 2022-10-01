/*
const unroll = (i) =>
  Array(i)
    .fill(0)
    .map((_, i) => `ν[τ + ${i}].v = p[${1 + i}].v`)
    .join(";\n  ");
const roll = (i) =>
  Array(i)
    .fill(0)
    .map((_, i) => `p[${1 + i}].v = ν[τ + ${i}].v`)
    .join(";\n  ");
console.log('#include "oant.h"');
console.log('#include "oant_logn.h"');
console.log(`#define QPS 64
p_t qp[QPS][32];
W_t qw = 0, qr = 0;
static N(ο0) { qp[qr][0].c(T); }`)
for (let i = 0; i < 31; i++) {
  console.log(`
static N(unο${i + 1}) {
  p_t *p = qp[qr];
  qr = (qr + 1) % QPS;
  ${unroll(i + 1)};
  τ += ${i + 1};
  O;
}
static N(ο${i + 1}) {
  p_t *p = qp[qw];
  qw = (qw + 1) % QPS;
  p[0].v = unο${i + 1};
  τ -= ${i + 1};
  ${roll(i + 1)};
  O;
}`);
}
console.log(`
n_t ο[32] = {
  ο0,`);
for (let i = 0; i < 31; i++) {
  console.log(`  ο${i + 1},`)
}
console.log(`};`);
*/
