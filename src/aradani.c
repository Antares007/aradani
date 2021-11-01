#include "aradani.h"
#define D ρ += 1,
#define D2 ρ += 2,
#define D3 ρ += 3,
#define D4 ρ += 4,
#define D5 ρ += 5,
#define D6 ρ += 6,
#define D7 ρ += 7,
#define P ο[α++].v = σ[ρ++].v,
#define P2 P P
#define P3 P2 P
#define P4 P3 P
#define P5 P4 P
#define P6 P5 P
#define P7 P6 P
#define U σ[--ρ].c = ο[--α].c,
#define U2 U U
#define U3 U2 U
#define U4 U3 U
#define U5 U4 U
#define U6 U5 U
#define U7 U6 U
#define CONJ(NT, DA, AN)                                                       \
  n_t araarkhi = σ[ρ + 2].c;                                                   \
  NT σ[--ρ].c = araarkhi, σ[--ρ].c = DA, σ[--ρ].c = AN,

static N(D3_D_C0) { D3 D C(0); }
static N(D3_P_O) { D3 P O; }
N(da) { CONJ(U, D3_P_O, D3_D_C0) O; }
static N(D3_D2_C0) { D3 D2 C(0); }
static N(D3_P2_O) { D3 P2 O; }
N(daa) { CONJ(U2, D3_P2_O, D3_D2_C0) O; }
static N(D3_D3_C0) { D3 D3 C(0); }
static N(D3_P3_O) { D3 P3 O; }
N(daaa) { CONJ(U3, D3_P3_O, D3_D3_C0) O; }
static N(D3_D4_C0) { D3 D4 C(0); }
static N(D3_P4_O) { D3 P4 O; }
N(daaaa) { CONJ(U4, D3_P4_O, D3_D4_C0) O; }

static N(aradani_ara) { D3 P D D O; }
static N(aradani_da) { D3 D P D O; }
static N(aradani_an) { D3 D D P O; }
N(aradani) {
  σ[--ρ].c = ο[--α].c; // an
  σ[--ρ].c = ο[--α].c; // da
  σ[--ρ].c = ο[--α].c; // ara
  σ[--ρ].c = aradani_ara;
  σ[--ρ].c = aradani_da;
  σ[--ρ].c = aradani_an;
  O;
}
static N(D3_D_C1) { D3 D C(1); }
N(an) { CONJ(U, D3_D_C1, D3_P_O) O; }

static N(ara_an) { D4 C(0); }
static N(ara_da) { D4 C(1); }
static N(ara_ara) { D3 P O; }
N(ara) {
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ara_ara;
  σ[--ρ].c = ara_da;
  σ[--ρ].c = ara_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(arada_an) { D5 C(0); }
static N(arada_da) { D3 D P O; }
static N(arada_ara) { D3 P D O; }
N(arada) {
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = arada_ara;
  σ[--ρ].c = arada_da;
  σ[--ρ].c = arada_an;
  O;
}
static N(D3_P_D_O) { D3 P D3 O; }
static N(D3_D_P_O) { D3 D P3 O; }
N(anda) { CONJ(U U, D3_D_P_O, D3_P_D_O) O; }
static N(D3_P_D3_O) { D3 P D3 O; }
static N(D3_D_P3_O) { D3 D P3 O; }
N(andaaa) { CONJ(U3 U, D3_D_P3_O, D3_P_D3_O) O; }
static N(D3_P_D5_O) { D3 P D5 O; }
static N(D3_D_P5_O) { D3 D P5 O; }
N(andaaaaa) { CONJ(U5 U, D3_D_P5_O, D3_P_D5_O) O; }
static N(D3_P_D6_O) { D3 P D6 O; }
static N(D3_D_P6_O) { D3 D P6 O; }
N(andaaaaaa) { CONJ(U6 U, D3_D_P6_O, D3_P_D6_O) O; }

static N(D3_P2_D6_O) { D3 P2 D6 O; }
static N(D3_D2_P6_O) { D3 D2 P6 O; }
N(anndaaaaaa) { CONJ(U6 U2, D3_D2_P6_O, D3_P2_D6_O) O; }
