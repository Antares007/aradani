const terminal = (word) => (o, pos) => {
  if (pos[0] === word) o(pos[1]);
};
const alt = (alt1, alt2) => (o, pos) => {
  alt1(o, pos);
  alt2(o, pos);
};
const seq = (seq1, seq2) => (o, pos) => seq1((pos1) => seq2(o, pos1), pos);
//  VP → V NP | V S
const VP = (o, pos) => {
  V((pos1) => NP(o, pos1), pos);
  V((pos1) => S(o, pos1), pos);
};
let inp = "a+(a-a)basaa";
const log = (...args) => console.log(...args)
const a   = (o, p) => { log("a", p); if (inp[p] === "a") o(p + 1); };
const b   = (o, p) => { log("b", p); if (inp[p] === "b") o(p + 1); };
const s   = (o, p) => { log("s", p); if (inp[p] === "s") o(p + 1); };
const pls = (o, p) => { log("+", p); if (inp[p] === "+") o(p + 1); };
const mns = (o, p) => { log("-", p); if (inp[p] === "-") o(p + 1); };
const mul = (o, p) => { log("*", p); if (inp[p] === "*") o(p + 1); };
const div = (o, p) => { log("/", p); if (inp[p] === "/") o(p + 1); };
const opr = (o, p) => { log("(", p); if (inp[p] === "(") o(p + 1); };
const cpr = (o, p) => { log(")", p); if (inp[p] === ")") o(p + 1); };
const ε = (o, p) => { log("ε", p); o(p); };
let i = 0;
const M = f => {
  const dict = {}
  return (o, p) => {
    if(dict[p]) return dict[p].forEach(o)
    dict[p] = []
    f((np) => {
      if (dict[p].indexOf(np) < 0) dict[p].push(np)
      o(np);
    }, p) 
  }
}
const E = (o, p) => { if(i++>17) return; log("E", p);
  a(o, p);
  opr(p => { E(p => { cpr(o,  p) }, p) }, p);
  E(p => {
    pls(p => { E(o,  p) }, p)
    mns(p => { E(o,  p) }, p)
    mul(p => { E(o,  p) }, p)
    div(p => { E(o,  p) }, p)
  }, p)
}
inp = "a-a*a*a/a*a/a";
E(p => console.log(p + "\n"), 0);
const SorA = (o, p) => { s(o, p); a(o, p); }
const S = ((o, p) => { if(i++ > 17) return;
  b(o, p);
  S(p => { SorA(o, p) }, p);
});
//inp = "bsss";
//S(p => console.log(p + "\n"), 0);
//      p0        p0     p1
//  S → term_b
//      term_a S thenS  orelse3 S var
const ABS = (o, p) => {
  a(p => {
    b(p => {
      s(o, p)
    }, p)
  }, p);
};
//inp = "abs"
//ABS(p => console.log("\n" + p), 0);
