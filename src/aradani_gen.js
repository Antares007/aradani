log(`#include "oant.h"`);
log(`#include "oant_logn.h"`);
for (let i = 1; i < 9; i++) {
  GoNar(i, 0);
  GoNar(i, 1);
  GoNar(i, 2);
}
for (let i = 2; i < 8; i++) {
  UnrollNar(i, 0), UnrollNar(i, 1), UnrollNar(i, 2);
}
for (let g = 01; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  const mc = ac < nc ? (nc < oc ? oc : nc) : ac < oc ? oc : ac;
  log(`N(ψ${g.toString(8)}) {`);
  if (mc === 1) {
    roll1(0, oc);
    roll1(1, ac);
    roll1(2, nc);
    log(`  ν[τ - 1].c(ω, α - 3, ν, τ - 1);`);
  } else {
    roll(0, oc, mc);
    roll(1, ac, mc);
    roll(2, nc, mc);
    log(`  ν[τ - 1].c(ω, α - ${(mc + 1) * 3}, ν, τ - 1);`);
  }
  log(`}`);
}
log(`N(ψ0) { ν[τ - 1].c(ω, α, ν, τ - 1); }
n_t ψ[01000] = {
  ψ0,`);
for (let g = 01; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  log(`  ψ${g.toString(8)},`);
}
log(`};`);
function roll(ray, xc, mc) {
  let i = 0;
  for (; i < xc; i++) log(`  ω[α - ${(i + 1) * 3 - ray}].v = ν[--τ].v;`);
  if (i > 1) log(`  ω[α - ${(i + 1) * 3 - ray}].v = un${rni(ray, xc)};`);
  else i--;
  if (mc - i) log(`  ω[α - ${(mc + 1) * 3 - ray}].v = ${rni(ray, mc - i)};`);
  log();
}
function roll1(ray, xc) {
  log(`  ω[α - ${3 - ray}].v = ${xc ? `ν[--τ].v` : rni(ray, 1)};`);
}
function rni(r, i) {
  const d = ["Gor", "God", "Got"];
  return i > 1 ? d[r] + i : d[r];
}
function GoNar(i, ray, name) {
  if (i > 1) log("static");
  log(
    `N(${rni(ray, i)}) { ω[α + ${(i - 1) * 3 + ray}].c(ω, α + ${
      i * 3
    }, ν, τ); }`
  );
}
function UnrollNar(c, ray) {
  log("static");
  log(`N(un${rni(ray, c)}) {`);
  for (let i = 0; i < c - 1; i++) log(`  ν[τ++].v = ω[α + ${ray}].v; α += 3;`);
  log(`  C(${ray});`);
  log(`}`);
}
function log(...args) {
  console.log(...args);
}
