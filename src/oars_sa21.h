#pragma once
#define ξ ,
/*
console.log(
  Array(7 + 7 + 7 + 1)
    .fill()
    .map((_, a) => String.fromCharCode(a + 0x61))
    .map(
      (v, i, a) =>
        `#define Sa${i}(${a.slice(0, i).map((c) => `T${c},V${c}`)}) ${a
          .slice(0, i)
          .map((v) => `Sa(T${v},V${v})`)
          .join("")}`
    )
    .slice(2)
    .join("\n")
);
*/
#define Sa2(Ta,Va,Tb,Vb) Sa(Ta,Va)Sa(Tb,Vb)
#define Sa3(Ta,Va,Tb,Vb,Tc,Vc) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)
#define Sa4(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)
#define Sa5(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)
#define Sa6(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)
#define Sa7(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)
#define Sa8(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)
#define Sa9(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)
#define Sa10(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)
#define Sa11(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)
#define Sa12(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)
#define Sa13(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)
#define Sa14(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)
#define Sa15(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)
#define Sa16(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo,Tp,Vp) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)Sa(Tp,Vp)
#define Sa17(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo,Tp,Vp,Tq,Vq) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)Sa(Tp,Vp)Sa(Tq,Vq)
#define Sa18(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo,Tp,Vp,Tq,Vq,Tr,Vr) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)Sa(Tp,Vp)Sa(Tq,Vq)Sa(Tr,Vr)
#define Sa19(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo,Tp,Vp,Tq,Vq,Tr,Vr,Ts,Vs) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)Sa(Tp,Vp)Sa(Tq,Vq)Sa(Tr,Vr)Sa(Ts,Vs)
#define Sa20(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo,Tp,Vp,Tq,Vq,Tr,Vr,Ts,Vs,Tt,Vt) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)Sa(Tp,Vp)Sa(Tq,Vq)Sa(Tr,Vr)Sa(Ts,Vs)Sa(Tt,Vt)
#define Sa21(Ta,Va,Tb,Vb,Tc,Vc,Td,Vd,Te,Ve,Tf,Vf,Tg,Vg,Th,Vh,Ti,Vi,Tj,Vj,Tk,Vk,Tl,Vl,Tm,Vm,Tn,Vn,To,Vo,Tp,Vp,Tq,Vq,Tr,Vr,Ts,Vs,Tt,Vt,Tu,Vu) Sa(Ta,Va)Sa(Tb,Vb)Sa(Tc,Vc)Sa(Td,Vd)Sa(Te,Ve)Sa(Tf,Vf)Sa(Tg,Vg)Sa(Th,Vh)Sa(Ti,Vi)Sa(Tj,Vj)Sa(Tk,Vk)Sa(Tl,Vl)Sa(Tm,Vm)Sa(Tn,Vn)Sa(To,Vo)Sa(Tp,Vp)Sa(Tq,Vq)Sa(Tr,Vr)Sa(Ts,Vs)Sa(Tt,Vt)Sa(Tu,Vu)
