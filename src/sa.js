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
const inp = "aabaaa";
const a = (c, p) => { console.log("a", p);
  if (inp[p] === "a") c(p + 1);
};
const b = (c, p) => { console.log("b", p);
  if (inp[p] === "b") c(p + 1);
};
let i = 0;
const S = (c, p2) => { if (i++ > 10) return; console.log("S", p2);
  const c1 = (p3) => { console.log("Sa", p3);
    a(c, p3);
  };
  b(c, p2);
  S(c1, p2);
};
const aaBa = (c, p0) => {
  const c_aa = (p2) => {
    S(c, p2);
  };
  const c_a = (p1) => {
    a(c_aa, p1);
  };
  a(c_a, p0);
};
aaBa(console.log.bind(console), 0);
