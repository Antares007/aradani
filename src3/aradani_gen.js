console.log(`#include "oars.h"`);
function rni(r, i) {
  const d = ["gor", "god", "got"];
  return i > 1 ? d[r] + i : d[r];
}
function gfun(i, ray, name) {
  console.log(
    `N(${rni(ray, i)}) { ο[ρ + ${i - 1} - σ * ${ray}].c(ο, α, ρ + ${i}, σ); }`
  );
}
function ufun(c, ray) {
  console.log(`N(u${rni(ray, c)}) {`);
  for (let i = 0; i < c - 1; i++)
    console.log(`ο[α++].v = ο[ρ++ - σ * ${ray}].v;`);
  console.log(`C(${ray});`);
  console.log(`}`);
}
for (let i = 1; i < 9; i++) {
  gfun(i, 0);
  gfun(i, 1);
  gfun(i, 2);
}
for (let i = 2; i < 8; i++) {
  ufun(i, 0),
  ufun(i, 1),
  ufun(i, 2);
}
for (let g = 01; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  const mc = ac < nc ? (nc < oc ? oc : nc) : ac < oc ? oc : ac;
  console.log(
    `N(${nc ? "ara" + nc : ""}${ac ? "da" + ac : ""}${oc ? "an" + oc : ""}) {`
  );
  if (mc === 1) {
    fun1(0, oc);
    fun1(1, ac);
    fun1(2, nc);
    console.log(`ο[α - 1].c(ο, α - 1, ρ - 1, σ);`);
  } else {
    fun(mc, 0, oc);
    fun(mc, 1, ac);
    fun(mc, 2, nc);
    console.log(`ο[α - 1].c(ο, α - 1, ρ - ${mc + 1}, σ);`);
  }
  console.log(`}`);
}
function fun(mc, ray, xc) {
  let i = 0;
  for (; i < xc; i++) console.log(`ο[ρ - ${i + 1} - σ * ${ray}].v = ο[--α].v;`);
  if (i > 1) console.log(`ο[ρ - ${i + 1} - σ * ${ray}].v = u${rni(ray, xc)};`);
  else i--;
  if (mc - i)
    console.log(`ο[ρ - ${mc + 1} - σ * ${ray}].v = ${rni(ray, mc - i)};`);
  console.log();
}
function fun1(ray, xc) {
  console.log(`ο[ρ - 1 - σ * ${ray}].v = ${xc ? `ο[--α].v` : rni(ray, 1)};`);
}
