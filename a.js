console.log(`#include "src3/oars.h"`);
function rni(r, i) {
  const d = ["gor", "god", "got"];
  return i ? d[r] + i : d[r];
}
function sfun(i, ray, name) {
  console.log(
    `N(s${rni(ray, i)}) { ο[ρ + ${i - 1} - σ * ${ray}].c(ο, α, ρ + ${i}, σ); }`
  );
}
function ufun(i, ray) {
  console.log(`N(u${rni(ray, i)}) {}`);
}
for (let i = 1; i < 9; i++) {
  sfun(i, 0);
  sfun(i, 1);
  sfun(i, 2);
  ufun(i, 0);
  ufun(i, 1);
  ufun(i, 2);
}
for (let g = 01; g < 01000; g++) {
  const nc = (g >> 6) & 7;
  const ac = (g >> 3) & 7;
  const oc = (g >> 0) & 7;
  const mc = ac < nc ? (nc < oc ? oc : nc) : ac < oc ? oc : ac;
  if (mc > 3) continue;
  console.log(
    `N(${nc ? "ara" + nc : ""}${ac ? "da" + ac : ""}${oc ? "an" + oc : ""}) {`
  );
  if (mc === 1) {
    fun1(0, oc, "sgor1");
    fun1(1, ac, "sgod1");
    fun1(2, nc, "sgot1");
    console.log(`ο[α - 1].c(ο, α - 1, ρ - 1, σ);`);
  } else {
    fun(mc, 0, oc, "gor");
    fun(mc, 1, ac, "god");
    fun(mc, 2, nc, "got");
    console.log(`ο[α - 1].c(ο, α - 1, ρ - ${mc + 1}, σ);`);
  }
  console.log(`}`);
}
function fun(mc, ray, xc, name) {
  let i = 0;
  for (; i < xc; i++) console.log(`ο[ρ - ${i + 1} - σ * ${ray}].v = ο[--α].v;`);
  if (i > 1) console.log(`ο[ρ - ${i + 1} - σ * ${ray}].v = u${name + xc};`);
  else i--;
  if (mc - i)
    console.log(`ο[ρ - ${mc + 1} - σ * ${ray}].v = s${name + (mc - i)};`);
  console.log();
}
function fun1(ray, xc, name) {
  console.log(`ο[ρ - 1 - σ * ${ray}].v = ${xc ? `ο[--α].v` : name};`);
}
