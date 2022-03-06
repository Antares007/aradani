#pragma once
#define Nar_Sar_(...) {Α(__VA_ARGS__) O;}
#define Sar(Name) S(Name) Nar_Sar_
#define Nar(Name) N(Name) Nar_Sar_
#define SarP(Name) SP(Name) Nar_Sar_
#define NarP(Name) NP(Name) Nar_Sar_

#define NS_(...) {__VA_ARGS__}}
#define NarS_(...) Α(__VA_ARGS__) O; }
#define NS(Name, T) N(Name) { T*s = ο[7].v; NS_
#define NSP(Name, T) NP(Name) { T*s = ο[7].v; NS_
#define NarS(Name, T) N(Name) { T*s = ο[7].v; NarS_
#define NarSP(Name, T) NP(Name) { T*s = ο[7].v; NarS_
#define SS(Name, T) S(Name) { T*s = ο[7].v; NS_
#define SSP(Name, T) SP(Name) { T*s = ο[7].v; NS_
#define SarS(Name, T) S(Name) { T*s = ο[7].v; NarS_
#define SarSP(Name, T) SP(Name) { T*s = ο[7].v; NarS_

