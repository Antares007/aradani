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
const inp = "baaaaaaaaaaaaaaa";

const a = (c, p) => {
  if (inp[p] === "a") c(p + 1);
};
const b = (c, p) => {
  if (inp[p] === "b") c(p + 1);
};
let i = 0;
const S = (c, p) => {
  if (i++ > 100) return;
  b(c, p);
  S((p1) => a(c, p1), p);
};

S(console.log.bind(console), 0);
