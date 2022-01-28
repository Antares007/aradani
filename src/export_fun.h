#pragma once
/*
console.log(
  Array(7 + 7 + 7 + 1)
    .fill()
    .map((_, a) => String.fromCharCode(a + 0x61))
    .map(
      (v, i, a) =>
        `#define EVF${i}(${[
          "Tail",
          "Pref",
          "Name",
          ...a.slice(0, i).map((c) => `R${c},T${c},N${c}`),
          "Head",
        ].join(", ")}) N(Pref##Name) {${a
          .slice(0, i)
          .map((c) => `R##R${c}(T${c},N${c});`)
          .join("")}(Name(${a
          .slice(0, i)
          .map((c) => `V##R${c} N${c}`)
          .join(", ")}),C(1));}EN(Tail, Pref##Name, Head)`
    )
    .join("\n")
);
*/
#define RΣ Sr
#define VΣ *
#define RΫ R
#define VΫ 
// clang-format off
#define EVF0(Tail, Pref, Name, Head) N(Pref##Name) {(Name(),C(1));}EN(Tail, Pref##Name, Head)
#define EVF1(Tail, Pref, Name, Ra,Ta,Na, Head) N(Pref##Name) {R##Ra(Ta,Na);(Name(V##Ra Na),C(1));}EN(Tail, Pref##Name, Head)
#define EVF2(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);(Name(V##Ra Na, V##Rb Nb),C(1));}EN(Tail, Pref##Name, Head)
#define EVF3(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc),C(1));}EN(Tail, Pref##Name, Head)
#define EVF4(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd),C(1));}EN(Tail, Pref##Name, Head)
#define EVF5(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne),C(1));}EN(Tail, Pref##Name, Head)
#define EVF6(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf),C(1));}EN(Tail, Pref##Name, Head)
#define EVF7(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng),C(1));}EN(Tail, Pref##Name, Head)
#define EVF8(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh),C(1));}EN(Tail, Pref##Name, Head)
#define EVF9(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni),C(1));}EN(Tail, Pref##Name, Head)
#define EVF10(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj),C(1));}EN(Tail, Pref##Name, Head)
#define EVF11(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk),C(1));}EN(Tail, Pref##Name, Head)
#define EVF12(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl),C(1));}EN(Tail, Pref##Name, Head)
#define EVF13(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm),C(1));}EN(Tail, Pref##Name, Head)
#define EVF14(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn),C(1));}EN(Tail, Pref##Name, Head)
#define EVF15(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No),C(1));}EN(Tail, Pref##Name, Head)
#define EVF16(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);R##Rp(Tp,Np);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np),C(1));}EN(Tail, Pref##Name, Head)
#define EVF17(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);R##Rp(Tp,Np);R##Rq(Tq,Nq);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq),C(1));}EN(Tail, Pref##Name, Head)
#define EVF18(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);R##Rp(Tp,Np);R##Rq(Tq,Nq);R##Rr(Tr,Nr);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr),C(1));}EN(Tail, Pref##Name, Head)
#define EVF19(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);R##Rp(Tp,Np);R##Rq(Tq,Nq);R##Rr(Tr,Nr);R##Rs(Ts,Ns);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns),C(1));}EN(Tail, Pref##Name, Head)
#define EVF20(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);R##Rp(Tp,Np);R##Rq(Tq,Nq);R##Rr(Tr,Nr);R##Rs(Ts,Ns);R##Rt(Tt,Nt);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt),C(1));}EN(Tail, Pref##Name, Head)
#define EVF21(Tail, Pref, Name, Ra,Ta,Na, Rb,Tb,Nb, Rc,Tc,Nc, Rd,Td,Nd, Re,Te,Ne, Rf,Tf,Nf, Rg,Tg,Ng, Rh,Th,Nh, Ri,Ti,Ni, Rj,Tj,Nj, Rk,Tk,Nk, Rl,Tl,Nl, Rm,Tm,Nm, Rn,Tn,Nn, Ro,To,No, Rp,Tp,Np, Rq,Tq,Nq, Rr,Tr,Nr, Rs,Ts,Ns, Rt,Tt,Nt, Ru,Tu,Nu, Head) N(Pref##Name) {R##Ra(Ta,Na);R##Rb(Tb,Nb);R##Rc(Tc,Nc);R##Rd(Td,Nd);R##Re(Te,Ne);R##Rf(Tf,Nf);R##Rg(Tg,Ng);R##Rh(Th,Nh);R##Ri(Ti,Ni);R##Rj(Tj,Nj);R##Rk(Tk,Nk);R##Rl(Tl,Nl);R##Rm(Tm,Nm);R##Rn(Tn,Nn);R##Ro(To,No);R##Rp(Tp,Np);R##Rq(Tq,Nq);R##Rr(Tr,Nr);R##Rs(Ts,Ns);R##Rt(Tt,Nt);R##Ru(Tu,Nu);(Name(V##Ra Na, V##Rb Nb, V##Rc Nc, V##Rd Nd, V##Re Ne, V##Rf Nf, V##Rg Ng, V##Rh Nh, V##Ri Ni, V##Rj Nj, V##Rk Nk, V##Rl Nl, V##Rm Nm, V##Rn Nn, V##Ro No, V##Rp Np, V##Rq Nq, V##Rr Nr, V##Rs Ns, V##Rt Nt, V##Ru Nu),C(1));}EN(Tail, Pref##Name, Head)
