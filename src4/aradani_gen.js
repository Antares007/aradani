console.log(`#include "oars.h"`);
function rni(r, i) {
  const d = ["Gor", "God", "Got"];
  return i > 1 ? d[r] + i : d[r];
}
function gfun(i, ray, name) {
  console.log(
    `N(${rni(ray, i)}) { ο[ρ + ${(i - 1) * 3 + ray}].c(ο, α, ρ + ${
      i * 3
    }, σ); }`
  );
}
function ufun(c, ray) {
  console.log(`N(unroll${rni(ray, c)}) {`);
  for (let i = 0; i < c - 1; i++)
    console.log(`  ο[α++].v = ο[ρ + ${ray}].v; ρ += 3;`);
  console.log(`  C(${ray});`);
  console.log(`}`);
}
for (let i = 1; i < 9; i++) {
  gfun(i, 0);
  gfun(i, 1);
  gfun(i, 2);
}
for (let i = 2; i < 8; i++) {
  ufun(i, 0), ufun(i, 1), ufun(i, 2);
}
for (let g = 01; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  const mc = ac < nc ? (nc < oc ? oc : nc) : ac < oc ? oc : ac;
  console.log(
    `N(${nc ? "ara" + (nc > 1 ? nc : "") : ""}${
      ac ? "da" + (ac > 1 ? ac : "") : ""
    }${oc ? "an" + (oc > 1 ? oc : "") : ""}) {`
  );
  if (mc === 1) {
    roll1(0, oc);
    roll1(1, ac);
    roll1(2, nc);
    console.log(`  ο[α - 1].c(ο, α - 1, ρ - 3, σ);`);
  } else {
    roll(0, oc, mc);
    roll(1, ac, mc);
    roll(2, nc, mc);
    console.log(`  ο[α - 1].c(ο, α - 1, ρ - ${(mc + 1) * 3}, σ);`);
  }
  console.log(`}`);
}
function roll(ray, xc, mc) {
  let i = 0;
  for (; i < xc; i++)
    console.log(`  ο[ρ - ${(i + 1) * 3 - ray}].v = ο[--α].v;`);
  if (i > 1)
    console.log(`  ο[ρ - ${(i + 1) * 3 - ray}].v = unroll${rni(ray, xc)};`);
  else i--;
  if (mc - i)
    console.log(`  ο[ρ - ${(mc + 1) * 3 - ray}].v = ${rni(ray, mc - i)};`);
  console.log();
}
function roll1(ray, xc) {
  console.log(`  ο[ρ - ${3 - ray}].v = ${xc ? `ο[--α].v` : rni(ray, 1)};`);
}
