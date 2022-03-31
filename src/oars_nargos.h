#pragma once
#include "oars_nars.h"
#define Nargo_s(...) Α(__VA_ARGS__) O; }
#define N_s(...) {__VA_ARGS__} }

#define Nargo(Name) Narg0(Name)()
#define No(Name) N0(Name)()
#define Sargo(Name) static Nargo(Name)
#define So(Name) static No(Name) // :)

#define NargoP(Name) Narg0P(Name)()
#define NoP(Name) N0P(Name)()
#define SargoP(Name) static Nargo(Name)
#define SoP(Name) static No(Name)
/*
const RS = (a, i) =>
  a
    .slice(0, i)
    .reverse()
    .map((c) => `R(T${c}, P${c});`)
    .join("");
const Args = (a, i) =>
  a
    .slice(0, i)
    .map((c) => `P${c},T${c}`)
    .join(", ");
const define_Nargo_r = (v, i, a) =>
  `#define Nargo_r${i}(${Args(a, i)}) { ${RS(a, i)} Nargo_s`;
const define_Narg = (p) => (v, i, a) =>
  `#define Narg${i}${p}(Name) N${p}(Name) Nargo_r${i}`;
const define_N_r = (v, i, a) =>
  `#define N_r${i}(${Args(a, i)}) { ${RS(a, i)} N_s`;
const define_N = (p) => (v, i, a) =>
  `#define N${i}${p}(Name) N${p}(Name) N_r${i}`;
const define_Sarg = (p) => (v, i, a) =>
  `#define Sarg${i}${p}(Name) static Narg${i}${p}(Name)`;
const define_S = (p) => (v, i, a) =>
  `#define S${i}${p}(Name) static N${i}${p}(Name)`;
const alfa = Array(7 + 1)
  .fill()
  .map((_, a) => String.fromCharCode(a + 0x61));
console.log(alfa.map(define_Nargo_r).join("\n"));
console.log(alfa.map(define_N_r).join("\n"));
console.log(alfa.map(define_Narg("")).join("\n"));
console.log(alfa.map(define_N("")).join("\n"));
console.log(alfa.map(define_Sarg("")).join("\n"));
console.log(alfa.map(define_S("")).join("\n"));
console.log(alfa.map(define_Narg("P")).join("\n"));
console.log(alfa.map(define_N("P")).join("\n"));
console.log(alfa.map(define_Sarg("P")).join("\n"));
console.log(alfa.map(define_S("P")).join("\n"));*/
#define Nargo_r0() {  Nargo_s
#define Nargo_r1(Pa,Ta) { R(Ta, Pa); Nargo_s
#define Nargo_r2(Pa,Ta, Pb,Tb) { R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Nargo_r3(Pa,Ta, Pb,Tb, Pc,Tc) { R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Nargo_r4(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td) { R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Nargo_r5(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te) { R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Nargo_r6(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf) { R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define Nargo_r7(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg) { R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); Nargo_s
#define N_r0() {  N_s
#define N_r1(Pa,Ta) { R(Ta, Pa); N_s
#define N_r2(Pa,Ta, Pb,Tb) { R(Tb, Pb);R(Ta, Pa); N_s
#define N_r3(Pa,Ta, Pb,Tb, Pc,Tc) { R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); N_s
#define N_r4(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td) { R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); N_s
#define N_r5(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te) { R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); N_s
#define N_r6(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf) { R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); N_s
#define N_r7(Pa,Ta, Pb,Tb, Pc,Tc, Pd,Td, Pe,Te, Pf,Tf, Pg,Tg) { R(Tg, Pg);R(Tf, Pf);R(Te, Pe);R(Td, Pd);R(Tc, Pc);R(Tb, Pb);R(Ta, Pa); N_s
#define Narg0(Name) N(Name) Nargo_r0
#define Narg1(Name) N(Name) Nargo_r1
#define Narg2(Name) N(Name) Nargo_r2
#define Narg3(Name) N(Name) Nargo_r3
#define Narg4(Name) N(Name) Nargo_r4
#define Narg5(Name) N(Name) Nargo_r5
#define Narg6(Name) N(Name) Nargo_r6
#define Narg7(Name) N(Name) Nargo_r7
#define N0(Name) N(Name) N_r0
#define N1(Name) N(Name) N_r1
#define N2(Name) N(Name) N_r2
#define N3(Name) N(Name) N_r3
#define N4(Name) N(Name) N_r4
#define N5(Name) N(Name) N_r5
#define N6(Name) N(Name) N_r6
#define N7(Name) N(Name) N_r7
#define Sarg0(Name) static Narg0(Name)
#define Sarg1(Name) static Narg1(Name)
#define Sarg2(Name) static Narg2(Name)
#define Sarg3(Name) static Narg3(Name)
#define Sarg4(Name) static Narg4(Name)
#define Sarg5(Name) static Narg5(Name)
#define Sarg6(Name) static Narg6(Name)
#define Sarg7(Name) static Narg7(Name)
#define S0(Name) static N0(Name)
#define S1(Name) static N1(Name)
#define S2(Name) static N2(Name)
#define S3(Name) static N3(Name)
#define S4(Name) static N4(Name)
#define S5(Name) static N5(Name)
#define S6(Name) static N6(Name)
#define S7(Name) static N7(Name)
#define Narg0P(Name) NP(Name) Nargo_r0
#define Narg1P(Name) NP(Name) Nargo_r1
#define Narg2P(Name) NP(Name) Nargo_r2
#define Narg3P(Name) NP(Name) Nargo_r3
#define Narg4P(Name) NP(Name) Nargo_r4
#define Narg5P(Name) NP(Name) Nargo_r5
#define Narg6P(Name) NP(Name) Nargo_r6
#define Narg7P(Name) NP(Name) Nargo_r7
#define N0P(Name) NP(Name) N_r0
#define N1P(Name) NP(Name) N_r1
#define N2P(Name) NP(Name) N_r2
#define N3P(Name) NP(Name) N_r3
#define N4P(Name) NP(Name) N_r4
#define N5P(Name) NP(Name) N_r5
#define N6P(Name) NP(Name) N_r6
#define N7P(Name) NP(Name) N_r7
#define Sarg0P(Name) static Narg0P(Name)
#define Sarg1P(Name) static Narg1P(Name)
#define Sarg2P(Name) static Narg2P(Name)
#define Sarg3P(Name) static Narg3P(Name)
#define Sarg4P(Name) static Narg4P(Name)
#define Sarg5P(Name) static Narg5P(Name)
#define Sarg6P(Name) static Narg6P(Name)
#define Sarg7P(Name) static Narg7P(Name)
#define S0P(Name) static N0P(Name)
#define S1P(Name) static N1P(Name)
#define S2P(Name) static N2P(Name)
#define S3P(Name) static N3P(Name)
#define S4P(Name) static N4P(Name)
#define S5P(Name) static N5P(Name)
#define S6P(Name) static N6P(Name)
#define S7P(Name) static N7P(Name)
