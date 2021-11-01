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
static N(ara_an) {
  ρ += 4;
  C(0);
}
static N(ara_da) {
  ρ += 4;
  C(1);
}
static N(ara_ara) {
  ρ += 3;
  n_t n = σ[ρ++].c;
  n(T());
}
N(ara) {
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ara_ara;
  σ[--ρ].c = ara_da;
  σ[--ρ].c = ara_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(arada_an) {
  ρ += 5;
  C(0);
}
static N(arada_da) {
  ρ += 5;
  n_t n = σ[ρ - 1].c;
  n(T());
}
static N(arada_ara) {
  ρ += 5;
  n_t n = σ[ρ - 2].c;
  n(T());
}
N(arada) {
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = arada_ara;
  σ[--ρ].c = arada_da;
  σ[--ρ].c = arada_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(anda_an) {
  ρ += 5;
  n_t n = σ[ρ - 2].c;
  n(T());
}
static N(anda_da) {
  ρ += 5;
  n_t n = σ[ρ - 1].c;
  n(T());
}
N(anda) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = anda_da;
  σ[--ρ].c = anda_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(andaaa_an) {
  ρ += 7;
  n_t n = σ[ρ - 4].c;
  n(T());
}
static N(andaaa_da) {
  ρ += 4;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  O;
}
N(andaaa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = andaaa_da;
  σ[--ρ].c = andaaa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(andaaaaa_an) {
  ρ += 9;
  n_t n = σ[ρ - 6].c;
  n(T());
}
static N(andaaaaa_da) {
  ρ += 4;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  O;
}
N(andaaaaa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = andaaaaa_da;
  σ[--ρ].c = andaaaaa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(andaaaaaa_an) {
  ρ += 10;
  n_t n = σ[ρ - 7].c;
  n(T());
}
static N(andaaaaaa_da) {
  ρ += 4;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  O;
}
N(andaaaaaa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = andaaaaaa_da;
  σ[--ρ].c = andaaaaaa_an;
  n_t n = ο[--α].c;
  n(T());
}
static N(anndaaaaaa_an) {
  ρ += 3;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ρ += 6;
  O;
}
static N(anndaaaaaa_da) {
  ρ += 5;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  ο[α++].v = σ[ρ++].v;
  O;
}
N(anndaaaaaa) {
  n_t araarkhi = σ[ρ + 2].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = ο[--α].c;
  σ[--ρ].c = araarkhi;
  σ[--ρ].c = anndaaaaaa_da;
  σ[--ρ].c = anndaaaaaa_an;
  n_t n = ο[--α].c;
  n(T());
}
