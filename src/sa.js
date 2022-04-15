const terminal = (word) => (ο, pos) => {
  if (pos[0] === word) ο(pos[1]);
};
const alt = (alt1, alt2) => (ο, pos) => {
  alt1(ο, pos);
  alt2(ο, pos);
};
const seq = (seq1, seq2) => (ο, pos) => seq1((pos1) => seq2(ο, pos1), pos);
//  VP → V NP | V S
const VP = (ο, pos) => {
  V((pos1) => NP(ο, pos1), pos);
  V((pos1) => S(ο, pos1), pos);
};
const inp = "a+(a-a)basaa"; const log = (...args) => 0; //console.log(...args)
const a = (ο, p) => { log("a", p); if (inp[p] === "a") ο(p + 1); };
const b = (ο, p) => { log("b", p); if (inp[p] === "b") ο(p + 1); };
const s = (ο, p) => { log("s", p); if (inp[p] === "s") ο(p + 1); };
const pls = (ο, p) => { log("+", p); if (inp[p] === "+") ο(p + 1); };
const mns = (ο, p) => { log("-", p); if (inp[p] === "-") ο(p + 1); };
const opr = (ο, p) => { log("(", p); if (inp[p] === "(") ο(p + 1); };
const cpr = (ο, p) => { log(")", p); if (inp[p] === ")") ο(p + 1); };
const ε = (ο, p) => { log("ε", p); ο(p); };
let i = 0;
const E = (o, p0) => {if (i++ > 17) return; log("S", p0);
  a(o, p0);
  const o2 = (p2) => { cpr(o, p2) }
  const o1 = (p1) => { E(o2, p1) }
  opr(o1, p0);
  const o4 = p2 => { E(o, p2) }
  const o5 = p2 => { E(o, p2) }
  const o3 = p1 => { pls(o4, p1); mns(o5, p1) }
  E(o3, p0)
}
E(p => console.log("\n" + p), 0);
const S = (ο, p0) => { if (i++ > 17) return; log("S", p0);
  b(ο,  p0);
  ε(ο,  p0);
  S(
      (p1) => { log("S & (a | s)",  p1);
        a(ο, p1);
        s(ο, p1);
      }
      ,
      p0
  );
};
//      p0        p0     p1
//  S → term_b
//      S term_a  thenS  orelse3
//      S term_s  thenS  orelse3 S var
//
const aaBa = (ο, p0) => {
  const c_aa = (p2) => {
    S(ο, p2);
  };
  const c_a = (p1) => {
    a(c_aa, p1);
  };
  a(c_a, p0);
};
//aaBa(p => console.log("\n" + p), 0);
