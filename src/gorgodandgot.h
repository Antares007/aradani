#pragma once
#include "oars.h"
static N(gor) { C(0); }
static N(god) { C(1); }
static N(got);
static N(ρ4ξ2) { ρ += 4, C(2); }
static N(ρ3α1) { ρ += 3, A(ο[ρ++].v) O; }
static N(ρ4ξ0) { ρ += 4, C(0); }
static N(anδ) {
  (void)got;
  (void)gor;
  (void)god;
  ο[--ρ].c = ο[--α].c, ο[--ρ].v = ρ4ξ2, ο[--ρ].v = ρ3α1, ο[--ρ].v = ρ4ξ0, O;
}
static N(got) {(void)anδ; C(2); }

