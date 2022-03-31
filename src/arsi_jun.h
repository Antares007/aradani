#pragma once
// clang-format off
#define ΑND                                                                    \
  S(Δ4_C0)        { ρ += 4, C(0); };                                           \
  S(Δ3_SO1_O)     { ρ += 3, Α(σ[ρ++].v) CO; };                                 \
  S(Δ4_C2)        { ρ += 4, C(2); };                                           \
  S(αnd) {                                                                     \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].v = Δ4_C2, σ[--ρ].v = Δ3_SO1_O, σ[--ρ].v = Δ4_C0;                   \
    CO;                                                                        \
  }
#define ΑNDOR3                                                                 \
  S(Δ7_C2)        { ρ += 7, C(2); };                                           \
  S(Δ3_SO1_D3_O)  { ρ += 3, Α(σ[ρ++].v) ρ += 3, CO; };                         \
  S(Δ4_SO3_O)     { ρ += 4, Α(σ[ρ++].v, σ[ρ++].v, σ[ρ++].v) CO; };             \
  S(αndor3) {                                                                  \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].c = σ[--α].c;                                                       \
    σ[--ρ].v = Δ7_C2, σ[--ρ].v = Δ3_SO1_D3_O, σ[--ρ].v = Δ4_SO3_O;             \
    CO;                                                                        \
  }
