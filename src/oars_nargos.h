#pragma once
/*
const rs_Nargo_r = (a, i) =>
  a
    .slice(0, i)
    .reverse()
    .map((c) => `R(T${c}, P${c});`)
    .join("");
const args_Nargo_r = (a, i) =>
  a
    .slice(0, i)
    .map((c) => `P${c},T${c}`)
    .join(", ");
const define_Nargo_r = (v, i, a) =>
  `#define Nargo_r${i}(${args_Nargo_r(a, i)}) { ${rs_Nargo_r(a, i)} Nargo_s`;

const define_Narg = (v, i, a) => `#define Narg${i}(Name) N(Name) Nargo_r${i}`;
console.log(
  Array(7 + 7 + 7 + 1)
    .fill()
    .map((_, a) => String.fromCharCode(a + 0x61))
    .map((v, i, a) => define_Nargo_r(v, i, a) + "\n" + define_Narg(v, i, a))
    .join("\n")
);
*/
#define Nargo_s(...) Α(__VA_ARGS__) O; }
#define Nargo_r0() {  Nargo_s
#define Narg0(Name) N(Name) Nargo_r0
#define Nargo_r1(Pa,Ta) { R(Ta, Pa); Nargo_s
#define Narg1(Name) N(Name) Nargo_r1
#define Nargo_r2(Pa,Ta, Pb,Tb) { R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg2(Name) N(Name) Nargo_r2
#define Nargo_r3(Pa,Ta, Pb,Tb, Pc,Tc) { R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg3(Name) N(Name) Nargo_r3
#define Nargo_r4(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td) { R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg4(Name) N(Name) Nargo_r4
#define Nargo_r5(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te) { R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg5(Name) N(Name) Nargo_r5
#define Nargo_r6(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf) { R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg6(Name) N(Name) Nargo_r6
#define Nargo_r7(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg) { R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg7(Name) N(Name) Nargo_r7
#define Nargo_r8(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th) { R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg8(Name) N(Name) Nargo_r8
#define Nargo_r9(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti) { R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg9(Name) N(Name) Nargo_r9
#define Nargo_r10(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj) { R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg10(Name) N(Name) Nargo_r10
#define Nargo_r11(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk) { R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg11(Name) N(Name) Nargo_r11
#define Nargo_r12(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl) { R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg12(Name) N(Name) Nargo_r12
#define Nargo_r13(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm) { R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg13(Name) N(Name) Nargo_r13
#define Nargo_r14(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn) { R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg14(Name) N(Name) Nargo_r14
#define Nargo_r15(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To) { R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg15(Name) N(Name) Nargo_r15
#define Nargo_r16(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To, Pp,Tp) { R(Tp, Pp);R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg16(Name) N(Name) Nargo_r16
#define Nargo_r17(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To, Pp,Tp, Pq,Tq) { R(Tq, Pq);R(Tp, Pp);R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg17(Name) N(Name) Nargo_r17
#define Nargo_r18(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To, Pp,Tp, Pq,Tq, Pr,Tr) { R(Tr, Pr);R(Tq, Pq);R(Tp, Pp);R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg18(Name) N(Name) Nargo_r18
#define Nargo_r19(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To, Pp,Tp, Pq,Tq, Pr,Tr, Ps,Ts) { R(Ts, Ps);R(Tr, Pr);R(Tq, Pq);R(Tp, Pp);R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg19(Name) N(Name) Nargo_r19
#define Nargo_r20(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To, Pp,Tp, Pq,Tq, Pr,Tr, Ps,Ts, Pt,Tt) { R(Tt, Pt);R(Ts, Ps);R(Tr, Pr);R(Tq, Pq);R(Tp, Pp);R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg20(Name) N(Name) Nargo_r20
#define Nargo_r21(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg, Ph,Th, Pi,Ti, Pj,Tj, Pk,Tk, Pl,Tl, Pm,Tm, Pn,Tn, Po,To, Pp,Tp, Pq,Tq, Pr,Tr, Ps,Ts, Pt,Tt, Pu,Tu) { R(Tu, Pu);R(Tt, Pt);R(Ts, Ps);R(Tr, Pr);R(Tq, Pq);R(Tp, Pp);R(To, Po);R(Tn, Pn);R(Tm, Pm);R(Tl, Pl);R(Tk, Pk);R(Tj, Pj);R(Ti, Pi);R(Th, Ph);R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Narg21(Name) N(Name) Nargo_r21
