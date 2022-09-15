log(`#include "oars.h"`);
log(`#include "oars_logn.h"`);
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
  log(
    `N(${nc ? "ara" + (nc > 1 ? nc : "") : ""}${
      ac ? "da" + (ac > 1 ? ac : "") : ""
    }${oc ? "an" + (oc > 1 ? oc : "") : ""}) {`
  );
  if (mc === 1) {
    roll1(0, oc);
    roll1(1, ac);
    roll1(2, nc);
    log(`  σ[α - 1].c(ο, α - 1, ρ - 3, σ);`);
  } else {
    roll(0, oc, mc);
    roll(1, ac, mc);
    roll(2, nc, mc);
    log(`  σ[α - 1].c(ο, α - 1, ρ - ${(mc + 1) * 3}, σ);`);
  }
  log(`}`);
}
log(`N(dot) { σ[α - 1].c(ο, α - 1, ρ, σ); }
n_t Τ[01000] = {
  dot,`);
for (let g = 01; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  log(
    `${nc ? "ara" + (nc > 1 ? nc : "") : ""}${
      ac ? "da" + (ac > 1 ? ac : "") : ""
    }${oc ? "an" + (oc > 1 ? oc : "") : ""},`
  );
}
log(`};`);
function roll(ray, xc, mc) {
  let i = 0;
  for (; i < xc; i++) log(`  ο[ρ - ${(i + 1) * 3 - ray}].v = σ[--α].v;`);
  if (i > 1) log(`  ο[ρ - ${(i + 1) * 3 - ray}].v = unroll${rni(ray, xc)};`);
  else i--;
  if (mc - i) log(`  ο[ρ - ${(mc + 1) * 3 - ray}].v = ${rni(ray, mc - i)};`);
  log();
}
function roll1(ray, xc) {
  log(`  ο[ρ - ${3 - ray}].v = ${xc ? `σ[--α].v` : rni(ray, 1)};`);
}
function rni(r, i) {
  const d = ["Gor", "God", "Got"];
  return i > 1 ? d[r] + i : d[r];
}
function GoNar(i, ray, name) {
  if (i > 1) log("static");
  log(
    `N(${rni(ray, i)}) { ο[ρ + ${(i - 1) * 3 + ray}].c(ο, α, ρ + ${
      i * 3
    }, σ); }`
  );
}
function UnrollNar(c, ray) {
  log("static");
  log(`N(unroll${rni(ray, c)}) {`);
  for (let i = 0; i < c - 1; i++) log(`  σ[α++].v = ο[ρ + ${ray}].v; ρ += 3;`);
  log(`  C(${ray});`);
  log(`}`);
}
function log(...args) {
  console.log(...args);
}
