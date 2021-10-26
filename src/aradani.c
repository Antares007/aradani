#include "aradani.h"
static N(da_an) {
  ρ += 4;
  C(0);
}
static N(da_da) {
  ρ += 3;
  n_t n = σ[ρ++].c;
  n(T());
}
N(da) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = da_da;
  σ[--ρ].c = da_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(daa_an) {
  ρ += 5;
  C(0);
}
static N(daa_da) {
  ρ += 3;
  ο[α++].v = σ[ρ++].v;
  n_t n = σ[ρ++].c;
  n(T());
}
N(daa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = daa_da;
  σ[--ρ].c = daa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(daaa_an) {
  ρ += 6;
  C(0);
}
static N(daaa_da) {
  ρ += 3;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  n_t n = σ[ρ++].c;
  n(T());
}
N(daaa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = daaa_da;
  σ[--ρ].c = daaa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(daaaa_an) {
  ρ += 7;
  C(0);
}
static N(daaaa_da) {
  ρ += 3;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  n_t n = σ[ρ++].c;
  n(T());
}
N(daaaa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = daaaa_da;
  σ[--ρ].c = daaaa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(aradani_ara) {
  ρ += 6;
  n_t n = σ[ρ - 3].c;
  n(T());
}
static N(aradani_da) {
  ρ += 6;
  n_t n = σ[ρ - 2].c;
  n(T());
}
static N(aradani_an) {
  ρ += 6;
  n_t n = σ[ρ - 1].c;
  n(T());
}
N(aradani) {
  σ[--ρ].c = ο[--α].c; // an
  σ[--ρ].c = ο[--α].c; // da
  σ[--ρ].c = ο[--α].c; // ara
  σ[--ρ].c = aradani_ara;
  σ[--ρ].c = aradani_da;
  σ[--ρ].c = aradani_an;
  n_t sgadasabmeli = ο[--α].c;
  sgadasabmeli(T());
}
static N(an_an) {
  ρ += 3;
  n_t n = σ[ρ++].c;
  n(T());
}
static N(an_da) {
  ρ += 4;
  C(1);
}
N(an) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = an_da;
  σ[--ρ].c = an_an;
  n_t n = ο[--α].c;
  n(T());
}
