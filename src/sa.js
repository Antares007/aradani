const terminal = (word) => (c, pos) => {
  if (pos[0] === word) c(pos[1]);
};
const alt = (alt1, alt2) => (c, pos) => {
  alt1(c, pos);
  alt2(c, pos);
};
const seq = (seq1, seq2) => (c, pos) => seq1((pos1) => seq2(c, pos1), pos);
//  VP → V NP | V S
const VP = (c, pos) => {
  V((pos1) => NP(c, pos1), pos);
  V((pos1) => S(c, pos1), pos);
};
const inp = "aabasaa";const log = (...args) => console.log(...args)
const a = (c, p) => { log("a", p); if (inp[p] === "a") c(p + 1); };
const b = (c, p) => { log("b", p); if (inp[p] === "b") c(p + 1); };
const s = (c, p) => { log("s", p); if (inp[p] === "s") c(p + 1); };
let i = 0;
const S = (c, p0) => { if (i++ > 17) return; log("S", p0);
  b(c,  p0);
  S((p1) => {
    log("Sa", p1); a(c, p1);
    log("Ss", p1); s(c, p1);
  }, p0);
};
//       p0       p0 p1
//   S → term_b   S  term_a thenS orelse3     S var
const aaBa = (c, p0) => {
  const c_aa = (p2) => {
    S(c, p2);
  };
  const c_a = (p1) => {
    a(c_aa, p1);
  };
  a(c_a, p0);
};
aaBa(p => console.log("\n" + p), 0);
