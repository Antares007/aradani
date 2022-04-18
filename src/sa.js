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
let inp = "a+(a-a)basaa";
const log = (...args) => console.log(...args)
const a   = (ο, p) => { log("a", p); if (inp[p] === "a") ο(p + 1); };
const b   = (ο, p) => { log("b", p); if (inp[p] === "b") ο(p + 1); };
const s   = (ο, p) => { log("s", p); if (inp[p] === "s") ο(p + 1); };
const pls = (ο, p) => { log("+", p); if (inp[p] === "+") ο(p + 1); };
const mns = (ο, p) => { log("-", p); if (inp[p] === "-") ο(p + 1); };
const opr = (ο, p) => { log("(", p); if (inp[p] === "(") ο(p + 1); };
const cpr = (ο, p) => { log(")", p); if (inp[p] === ")") ο(p + 1); };
const ε = (ο, p) => { log("ε", p); ο(p); };
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
const E = M((o, p) => { log("E", p);
  a(o, p);
  const o2 = p => { cpr(o,  p) }
  const o1 = p => {   E(o2, p) }
  opr(o1, p);
  const o4 = p => {   E(o,  p) }
  const o3 = p => { pls(o4, p)
                    mns(o4, p) }
  E(o3, p)
})
const E2 = (o, p) => { if(i++ > 50) return; log("E", p);
  a(o, p);
  opr(p=>{
    E(p=>{
      cpr(o, p)
    },p)
  },p);
  E(p=>{
    pls(p=>{
      E(o, p)
    },p)
    mns(p=>{
      E(o, p)
    },p)
  },p)
}
//inp = "(a-a)+abasaa";
//E2(p => console.log(p + "\n"), 0);

const S = ((ο, p) => { if(i++ > 7) return; log("S", p);
  ((ο, p) => { log("b", p); if (inp[p] === "b") ο(p + 1); })(ο,  p);
  S(p => {//log("Sas", p)
    ((ο, p) => { log("a", p); if (inp[p] === "a") ο(p + 1); })(ο, p);
    //s(ο, p);
  }, p);
});

inp = "baaa";
S(p => console.log(p + "\n"), 0);
//      p0        p0     p1
//  S → term_b
//      term_a S thenS  orelse3 S var
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

