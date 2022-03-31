#pragma once
// clang-format off
#define ΑND                                                                    \
  static N(Δ4_C0)        { ρ += 4, C(0); };                                    \
  static N(Δ3_SO1_O)     { ρ += 3, Α(σ[ρ++].v) O; };                           \
  static N(Δ4_C2)        { ρ += 4, C(2); };                                    \
  static N(αnd) {                                                              \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].v = Δ4_C2, σ[--ρ].v = Δ3_SO1_O, σ[--ρ].v = Δ4_C0;                   \
    O;                                                                         \
  }
#define ΑNDOR3                                                                 \
  static N(Δ7_C2)        { ρ += 7, C(2); };                                    \
  static N(Δ3_SO1_D3_O)  { ρ += 3, Α(σ[ρ++].v) ρ += 3, O; };                   \
  static N(Δ4_SO3_O)     { ρ += 4, Α(σ[ρ++].v, σ[ρ++].v, σ[ρ++].v) O; };       \
  static N(αndor3) {                                                           \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].v = Δ7_C2, σ[--ρ].v = Δ3_SO1_D3_O, σ[--ρ].v = Δ4_SO3_O;             \
    O;                                                                         \
  }
