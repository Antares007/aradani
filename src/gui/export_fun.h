#pragma once
/*
const abc_set = Array(7 + 7 + 7 + 1) .fill() .map((_, a) => String.fromCharCode(a + 0x61));
const genMacroParams = (i, a) => [ "Tail", "Pref", "Name", ...a.slice(0, i).map((c) => `R${c},T${c},N${c}`), "Head", ].join(", ");
const genParams = (i, a) => a .slice(0, i) .reverse() .map((c) => `R##R${c}(T${c},N${c});`) .join("");
const genArgs = (i, a) => a .slice(0, i) .map((c) => `V##R${c} N${c}`) .join(", ");
const EVFs = abc_set.map( (v, i, a) => `#define EVF${i}(${genMacroParams(i, a)}) N(Pref##Name) {${genParams( i, a)}(Name(${genArgs(i, a)}),C(1));}EN(Tail, Pref##Name, Head)`);
const EBFs = abc_set.map( (v, i, a) => `#define EBF${i}(${genMacroParams(i, a)}) N(Pref##Name) {${genParams( i, a)}C(Name(${genArgs(i, a)}));}EN(Tail, Pref##Name, Head)`);
const ERFs = abc_set.map( (v, i, a) => `#define ERF${i}(${genMacroParams(i, a)}) N(Pref##Name) {${genParams( i, a)}A(Name(${genArgs(i, a)})) C(1);}EN(Tail, Pref##Name, Head)`);
console.log( "// EVFs *********************************************************");
console.log(EVFs.join("\n"));
console.log( "// EBFs *********************************************************");
console.log(EBFs.join("\n"));
console.log( "// ERFs *********************************************************");
console.log(ERFs.join("\n"));
*/
#define RΣ Sr
#define VΣ *
#define RΫ R
#define VΫ 
// clang-format off
// EVFs *********************************************************
#define EVF0(Tail, Pref, Name, Head) N(Pref##Name) {(Name(),C(1));}EN(Tail, Pref##Name, Head)
#define EVF1(Tail, Pref, Name, Ra,Ta,Na, Head) N(Pref##Name) {R##Ra(Ta,Na);(Name(V##Ra Na),C(1));}EN(Tail, Pref##Name, Head)
#define EVF2(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Head) N(Pref##Name) {R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb),C(1));}EN(Tail, Pref##Name, Head)
#define EVF3(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Head) N(Pref##Name) {R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc),C(1));}EN(Tail, Pref##Name, Head)
#define EVF4(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Head) N(Pref##Name) {R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd),C(1));}EN(Tail, Pref##Name, Head)
#define EVF5(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Head) N(Pref##Name) {R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne),C(1));}EN(Tail, Pref##Name, Head)
#define EVF6(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Head) N(Pref##Name) {R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf),C(1));}EN(Tail, Pref##Name, Head)
#define EVF7(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Head) N(Pref##Name) {R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng),C(1));}EN(Tail, Pref##Name, Head)
#define EVF8(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Head) N(Pref##Name) {R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh),C(1));}EN(Tail, Pref##Name, Head)
#define EVF9(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Head) N(Pref##Name) {R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni),C(1));}EN(Tail, Pref##Name, Head)
#define EVF10(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Head) N(Pref##Name) {R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj),C(1));}EN(Tail, Pref##Name, Head)
#define EVF11(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Head) N(Pref##Name) {R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk),C(1));}EN(Tail, Pref##Name, Head)
#define EVF12(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Head) N(Pref##Name) {R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl),C(1));}EN(Tail, Pref##Name, Head)
#define EVF13(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Head) N(Pref##Name) {R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm),C(1));}EN(Tail, Pref##Name, Head)
#define EVF14(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Head) N(Pref##Name) {R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn),C(1));}EN(Tail, Pref##Name, Head)
#define EVF15(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Head) N(Pref##Name) {R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No),C(1));}EN(Tail, Pref##Name, Head)
#define EVF16(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Head) N(Pref##Name) {R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np),C(1));}EN(Tail, Pref##Name, Head)
#define EVF17(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Head) N(Pref##Name) {R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq),C(1));}EN(Tail, Pref##Name, Head)
#define EVF18(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Head) N(Pref##Name) {R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr),C(1));}EN(Tail, Pref##Name, Head)
#define EVF19(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Head) N(Pref##Name) {R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns),C(1));}EN(Tail, Pref##Name, Head)
#define EVF20(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Head) N(Pref##Name) {R##Rt(Tt,Nt);R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt),C(1));}EN(Tail, Pref##Name, Head)
#define EVF21(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Ru,Tu,Nu, Head) N(Pref##Name) {R##Ru(Tu,Nu);R##Rt(Tt,Nt);R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt, V##Ru Nu),C(1));}EN(Tail, Pref##Name, Head)
// EBFs *********************************************************
#define EBF0(Tail, Pref, Name, Head) N(Pref##Name) {C(Name());}EN(Tail, Pref##Name, Head)
#define EBF1(Tail, Pref, Name, Ra,Ta,Na, Head) N(Pref##Name) {R##Ra(Ta,Na);C(Name(V##Ra Na));}EN(Tail, Pref##Name, Head)
#define EBF2(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Head) N(Pref##Name) {R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb));}EN(Tail, Pref##Name, Head)
#define EBF3(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Head) N(Pref##Name) {R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc));}EN(Tail, Pref##Name, Head)
#define EBF4(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Head) N(Pref##Name) {R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd));}EN(Tail, Pref##Name, Head)
#define EBF5(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Head) N(Pref##Name) {R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne));}EN(Tail, Pref##Name, Head)
#define EBF6(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Head) N(Pref##Name) {R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf));}EN(Tail, Pref##Name, Head)
#define EBF7(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Head) N(Pref##Name) {R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng));}EN(Tail, Pref##Name, Head)
#define EBF8(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Head) N(Pref##Name) {R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh));}EN(Tail, Pref##Name, Head)
#define EBF9(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Head) N(Pref##Name) {R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni));}EN(Tail, Pref##Name, Head)
#define EBF10(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Head) N(Pref##Name) {R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj));}EN(Tail, Pref##Name, Head)
#define EBF11(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Head) N(Pref##Name) {R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk));}EN(Tail, Pref##Name, Head)
#define EBF12(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Head) N(Pref##Name) {R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl));}EN(Tail, Pref##Name, Head)
#define EBF13(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Head) N(Pref##Name) {R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm));}EN(Tail, Pref##Name, Head)
#define EBF14(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Head) N(Pref##Name) {R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn));}EN(Tail, Pref##Name, Head)
#define EBF15(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Head) N(Pref##Name) {R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No));}EN(Tail, Pref##Name, Head)
#define EBF16(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Head) N(Pref##Name) {R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np));}EN(Tail, Pref##Name, Head)
#define EBF17(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Head) N(Pref##Name) {R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq));}EN(Tail, Pref##Name, Head)
#define EBF18(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Head) N(Pref##Name) {R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr));}EN(Tail, Pref##Name, Head)
#define EBF19(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Head) N(Pref##Name) {R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns));}EN(Tail, Pref##Name, Head)
#define EBF20(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Head) N(Pref##Name) {R##Rt(Tt,Nt);R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt));}EN(Tail, Pref##Name, Head)
#define EBF21(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Ru,Tu,Nu, Head) N(Pref##Name) {R##Ru(Tu,Nu);R##Rt(Tt,Nt);R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);C(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt, V##Ru Nu));}EN(Tail, Pref##Name, Head)
// ERFs *********************************************************
#define ERF0(Tail, Pref, Name, Head) N(Pref##Name) {A(Name()) C(1);}EN(Tail, Pref##Name, Head)
#define ERF1(Tail, Pref, Name, Ra,Ta,Na, Head) N(Pref##Name) {R##Ra(Ta,Na);A(Name(V##Ra Na)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF2(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Head) N(Pref##Name) {R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF3(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Head) N(Pref##Name) {R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF4(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Head) N(Pref##Name) {R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF5(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Head) N(Pref##Name) {R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF6(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Head) N(Pref##Name) {R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF7(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Head) N(Pref##Name) {R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF8(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Head) N(Pref##Name) {R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF9(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Head) N(Pref##Name) {R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF10(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Head) N(Pref##Name) {R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF11(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Head) N(Pref##Name) {R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF12(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Head) N(Pref##Name) {R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF13(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Head) N(Pref##Name) {R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF14(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Head) N(Pref##Name) {R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF15(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Head) N(Pref##Name) {R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF16(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Head) N(Pref##Name) {R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF17(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Head) N(Pref##Name) {R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF18(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Head) N(Pref##Name) {R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF19(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Head) N(Pref##Name) {R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF20(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Head) N(Pref##Name) {R##Rt(Tt,Nt);R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt)) C(1);}EN(Tail, Pref##Name, Head)
#define ERF21(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Ru,Tu,Nu, Head) N(Pref##Name) {R##Ru(Tu,Nu);R##Rt(Tt,Nt);R##Rs(Ts,Ns);R##Rr(Tr,Nr);R##Rq(Tq,Nq);R##Rp(Tp,Np);R##Ro(To,No);R##Rn(Tn,Nn);R##Rm(Tm,Nm);R##Rl(Tl,Nl);R##Rk(Tk,Nk);R##Rj(Tj,Nj);R##Ri(Ti,Ni);R##Rh(Th,Nh);R##Rg(Tg,Ng);R##Rf(Tf,Nf);R##Re(Te,Ne);R##Rd(Td,Nd);R##Rc(Tc,Nc);R##Rb(Tb,Nb);R##Ra(Ta,Na);A(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt, V##Ru Nu)) C(1);}EN(Tail, Pref##Name, Head)