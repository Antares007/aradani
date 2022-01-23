const nao = ["", "or", "and", "not"];
const s = [];
const fixN = (x) => (x > 1 ? x : "");
for (let i = 1; i < 01000; i++) {
  const nc = (i & 0700) >> 6;
  const ac = (i & 0070) >> 3;
  const oc = (i & 0007) >> 0;
  s.push([
    (nc ? "not" + fixN(nc) : "") +
      (ac ? "and" + fixN(ac) : "") +
      (oc ? "or" + fixN(oc) : ""),
    i,
  ]);
}
console.log(
  s
    .sort()
    .map(
      ([name, jun]) =>
        `JUN(L,\n${name.padEnd(11, " ")}, ${jun
          .toString(8)
          .padStart(4, "0")}, L)`
    )
    .join(""),
  s.length
);
