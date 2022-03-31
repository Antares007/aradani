#pragma once
#define Nargo_s(...)                                                           \
  Α(__VA_ARGS__) O;                                                            \
  }
#define N_s(...)                                                               \
  { __VA_ARGS__ }                                                              \
  }
#define Nargo(Name) Narg0(Name)()
#define No(Name) N0(Name)() // :)
#define Sargo(Name) static Nargo(Name)
#define So(Name) static No(Name)
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
const define_Narg = (v, i, a) =>
  `#define Narg${i}(Name) void Name(OARS) Nargo_r${i}`;
const define_N_r = (v, i, a) =>
  `#define N_r${i}(${Args(a, i)}) { ${RS(a, i)} N_s`;
const define_N = (v, i, a) => `#define N${i}(Name) void Name(OARS) N_r${i}`;
const define_Sarg = (v, i, a) => `#define Sarg${i}(Name) static Narg${i}(Name)`;
const define_S = (v, i, a) => `#define S${i}(Name) static N${i}(Name)`;
const alfa = Array(7 + 1)
  .fill()
  .map((_, a) => String.fromCharCode(a + 0x61));
console.log(alfa.map(define_Nargo_r).join("\n"));
console.log(alfa.map(define_N_r).join("\n"));
console.log(alfa.map(define_Narg).join("\n"));
console.log(alfa.map(define_N).join("\n"));
console.log(alfa.map(define_Sarg).join("\n"));
console.log(alfa.map(define_S).join("\n"));
*/
#define Nargo_r0()                                                             \
  {                                                                            \
    Nargo_s
#define Nargo_r1(Pa, Ta)                                                       \
  {                                                                            \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define Nargo_r2(Pa, Ta, Pb, Tb)                                               \
  {                                                                            \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define Nargo_r3(Pa, Ta, Pb, Tb, Pc, Tc)                                       \
  {                                                                            \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define Nargo_r4(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td)                               \
  {                                                                            \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define Nargo_r5(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td, Pe, Te)                       \
  {                                                                            \
    R(Te, Pe);                                                                 \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define Nargo_r6(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td, Pe, Te, Pf, Tf)               \
  {                                                                            \
    R(Tf, Pf);                                                                 \
    R(Te, Pe);                                                                 \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define Nargo_r7(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td, Pe, Te, Pf, Tf, Pg, Tg)       \
  {                                                                            \
    R(Tg, Pg);                                                                 \
    R(Tf, Pf);                                                                 \
    R(Te, Pe);                                                                 \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    Nargo_s
#define N_r0()                                                                 \
  {                                                                            \
    N_s
#define N_r1(Pa, Ta)                                                           \
  {                                                                            \
    R(Ta, Pa);                                                                 \
    N_s
#define N_r2(Pa, Ta, Pb, Tb)                                                   \
  {                                                                            \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    N_s
#define N_r3(Pa, Ta, Pb, Tb, Pc, Tc)                                           \
  {                                                                            \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    N_s
#define N_r4(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td)                                   \
  {                                                                            \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    N_s
#define N_r5(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td, Pe, Te)                           \
  {                                                                            \
    R(Te, Pe);                                                                 \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    N_s
#define N_r6(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td, Pe, Te, Pf, Tf)                   \
  {                                                                            \
    R(Tf, Pf);                                                                 \
    R(Te, Pe);                                                                 \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    N_s
#define N_r7(Pa, Ta, Pb, Tb, Pc, Tc, Pd, Td, Pe, Te, Pf, Tf, Pg, Tg)           \
  {                                                                            \
    R(Tg, Pg);                                                                 \
    R(Tf, Pf);                                                                 \
    R(Te, Pe);                                                                 \
    R(Td, Pd);                                                                 \
    R(Tc, Pc);                                                                 \
    R(Tb, Pb);                                                                 \
    R(Ta, Pa);                                                                 \
    N_s
#define Narg0(Name) void Name(OARS) Nargo_r0
#define Narg1(Name) void Name(OARS) Nargo_r1
#define Narg2(Name) void Name(OARS) Nargo_r2
#define Narg3(Name) void Name(OARS) Nargo_r3
#define Narg4(Name) void Name(OARS) Nargo_r4
#define Narg5(Name) void Name(OARS) Nargo_r5
#define Narg6(Name) void Name(OARS) Nargo_r6
#define Narg7(Name) void Name(OARS) Nargo_r7
#define N0(Name) void Name(OARS) N_r0
#define N1(Name) void Name(OARS) N_r1
#define N2(Name) void Name(OARS) N_r2
#define N3(Name) void Name(OARS) N_r3
#define N4(Name) void Name(OARS) N_r4
#define N5(Name) void Name(OARS) N_r5
#define N6(Name) void Name(OARS) N_r6
#define N7(Name) void Name(OARS) N_r7
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
