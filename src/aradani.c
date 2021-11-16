#include "importexportmacros.h"
#include "oars.h"
#define Moakhie1 ρ += 1,
#define Moakhie2 ρ += 2,
#define Moakhie3 ρ += 3,
#define Moakhie4 ρ += 4,
#define Moakhie5 ρ += 5,
#define Moakhie6 ρ += 6,
#define Moakhie7 ρ += 7,
#define Amoakhe1 ο[α++].v = σ[ρ++].v,
#define Amoakhe2 Amoakhe1 Amoakhe1
#define Amoakhe3 Amoakhe2 Amoakhe1
#define Amoakhe4 Amoakhe3 Amoakhe1
#define Amoakhe5 Amoakhe4 Amoakhe1
#define Amoakhe6 Amoakhe5 Amoakhe1
#define Amoakhe7 Amoakhe6 Amoakhe1
#define Chaakhvie1 σ[--ρ].c = ο[--α].c,
#define Chaakhvie2 Chaakhvie1 Chaakhvie1
#define Chaakhvie3 Chaakhvie2 Chaakhvie1
#define Chaakhvie4 Chaakhvie3 Chaakhvie1
#define Chaakhvie5 Chaakhvie4 Chaakhvie1
#define Chaakhvie6 Chaakhvie5 Chaakhvie1
#define Chaakhvie7 Chaakhvie6 Chaakhvie1

#define C0 C(0)
#define C1 C(1)
#define C2 C(2)

#define Ray3(a, b, c)                                                          \
  N(a##_##b##_##c) { a b c; }
#define Ray4(a, b, c, d)                                                       \
  N(a##_##b##_##c##_##d) { a b c d; }
#define Ray5(a, b, c, d, e)                                                    \
  N(a##_##b##_##c##_##d##_##e) { a b c d e; }

static N(got) { C(2); }
// clang-format off
#define AN(Tail, Name, Pc, Next)                                               \
  Ray3(Moakhie3, Amoakhe##Pc, O);                                              \
  Ray3(Moakhie3, Moakhie##Pc, C1);                                             \
  Ray3(Moakhie3, Moakhie##Pc, C2);                                             \
  N(Name) {                                                                    \
    Chaakhvie##Pc                                                              \
    σ[--ρ].c = Moakhie3_Moakhie##Pc##_C2;                                      \
    σ[--ρ].c = Moakhie3_Moakhie##Pc##_C1;                                      \
    σ[--ρ].c = Moakhie3_Amoakhe##Pc##_O;                                       \
    O;                                                                         \
  }                                                                            \
  EN(Tail, Name, Next)
#define DA(Tail, Name, Pc, Next)                                               \
  N(Name) {                                                                    \
    Chaakhvie##Pc                                                              \
    σ[--ρ].c = Moakhie3_Moakhie##Pc##_C2;                                      \
    σ[--ρ].c = Moakhie3_Amoakhe##Pc##_O;                                       \
    σ[--ρ].c = Moakhie3_Moakhie##Pc##_C0;                                      \
    O;                                                                         \
  }                                                                            \
  EN(Tail, Name, Next)
#define ANDA(Tail, Name, Pcan, Pcda, Next)                                     \
  Ray4(Moakhie3, Moakhie##Pcan, Moakhie##Pcda, C2);                            \
  Ray4(Moakhie3, Amoakhe##Pcan, Moakhie##Pcda, O);                             \
  Ray4(Moakhie3, Moakhie##Pcan, Amoakhe##Pcda, O);                             \
  N(Name) {                                                                    \
    Chaakhvie##Pcda                                                            \
    Chaakhvie##Pcan                                                            \
    σ[--ρ].c = Moakhie3_Moakhie##Pcan##_Moakhie##Pcda##_C2;                    \
    σ[--ρ].c = Moakhie3_Moakhie##Pcan##_Amoakhe##Pcda##_O;                     \
    σ[--ρ].c = Moakhie3_Amoakhe##Pcan##_Moakhie##Pcda##_O;                     \
    O;                                                                         \
  }                                                                            \
  EN(Tail, Name, Next)
#define ARA(Tail, Name, Pc, Head)                                              \
  Ray3(Moakhie3, Moakhie##Pc, C0);                                             \
  N(Name) {                                                                    \
    Chaakhvie##Pc                                                              \
    σ[--ρ].c = Moakhie3_Amoakhe##Pc##_O;                                       \
    σ[--ρ].c = Moakhie3_Moakhie##Pc##_C1;                                      \
    σ[--ρ].c = Moakhie3_Moakhie##Pc##_C0;                                      \
    O;                                                                         \
  }                                                                            \
  EN(Tail, Name, Head)
#define ARADA(Tail, Name, Pcara, Pcda, Head)                                   \
  Ray4(Moakhie3, Moakhie##Pcara, Moakhie##Pcda, C0);                           \
  N(Name) {                                                                    \
    Chaakhvie##Pcara                                                           \
    Chaakhvie##Pcda                                                            \
    σ[--ρ].c = Moakhie3_Amoakhe##Pcara##_Moakhie##Pcda##_O;                    \
    σ[--ρ].c = Moakhie3_Moakhie##Pcara##_Amoakhe##Pcda##_O;                    \
    σ[--ρ].c = Moakhie3_Moakhie##Pcara##_Moakhie##Pcda##_C0;                   \
    O;                                                                         \
  }                                                                            \
  EN(Tail, Name, Head)
#define ARADANI(Name, Para, Pda, Pan)                                          \
  Ray5(Moakhie3, Moakhie##Pan, Moakhie##Pda, Amoakhe##Para, O);                \
  Ray5(Moakhie3, Moakhie##Pan, Amoakhe##Pda, Moakhie##Para, O);                \
  Ray5(Moakhie3, Amoakhe##Pan, Moakhie##Pda, Moakhie##Para, O);                \
  N(Name) {                                                                    \
    Chaakhvie3                                                                 \
    σ[--ρ].c = Moakhie3_Moakhie##Pan##_Moakhie##Pda##_Amoakhe##Para##_O;       \
    σ[--ρ].c = Moakhie3_Moakhie##Pan##_Amoakhe##Pda##_Moakhie##Para##_O;       \
    σ[--ρ].c = Moakhie3_Amoakhe##Pan##_Moakhie##Pda##_Moakhie##Para##_O;       \
    O;                                                                         \
  }
#define END(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)
#define ENDT(Tail, Name, T, Head)                                                  \
  T export_##Name = (void*)(Name);                                                                     \
  E(Tail, #Name, export_##Name, Head)

AN(got,
an,           1,      L)AN(L,
an2,          2,      L)ANDA(L,
an2da,        2, 1,   L)ANDA(L,
an2da2,       2, 2,   L)ANDA(L,
an2da3,       2, 3,   L)ANDA(L,
an2da4,       2, 4,   L)ANDA(L,
an2da5,       2, 5,   L)ANDA(L,
an2da6,       2, 6,   L)ANDA(L,
an2da7,       2, 7,   L)AN(L,
an3,          3,      L)ANDA(L,
an3da,        3, 1,   L)ANDA(L,
an3da2,       3, 2,   L)ANDA(L,
an3da3,       3, 3,   L)ANDA(L,
an3da4,       3, 4,   L)ANDA(L,
an3da5,       3, 5,   L)ANDA(L,
an3da6,       3, 6,   L)ANDA(L,
an3da7,       3, 7,   L)AN(L,
an4,          4,      L)ANDA(L,
an4da,        4, 1,   L)ANDA(L,
an4da2,       4, 2,   L)ANDA(L,
an4da3,       4, 3,   L)ANDA(L,
an4da4,       4, 4,   L)ANDA(L,
an4da5,       4, 5,   L)ANDA(L,
an4da6,       4, 6,   L)ANDA(L,
an4da7,       4, 7,   L)AN(L,
an5,          5,      L)ANDA(L,
an5da,        5, 1,   L)ANDA(L,
an5da2,       5, 2,   L)ANDA(L,
an5da3,       5, 3,   L)ANDA(L,
an5da4,       5, 4,   L)ANDA(L,
an5da5,       5, 5,   L)ANDA(L,
an5da6,       5, 6,   L)ANDA(L,
an5da7,       5, 7,   L)AN(L,
an6,          6,      L)ANDA(L,
an6da,        6, 1,   L)ANDA(L,
an6da2,       6, 2,   L)ANDA(L,
an6da3,       6, 3,   L)ANDA(L,
an6da4,       6, 4,   L)ANDA(L,
an6da5,       6, 5,   L)ANDA(L,
an6da6,       6, 6,   L)ANDA(L,
an6da7,       6, 7,   L)AN(L,
an7,          7,      L)ANDA(L,
an7da,        7, 1,   L)ANDA(L,
an7da2,       7, 2,   L)ANDA(L,
an7da3,       7, 3,   L)ANDA(L,
an7da4,       7, 4,   L)ANDA(L,
an7da5,       7, 5,   L)ANDA(L,
an7da6,       7, 6,   L)ANDA(L,
an7da7,       7, 7,   L)ANDA(L,
anda,         1, 1,   L)ANDA(L,
anda2,        1, 2,   L)ANDA(L,
anda3,        1, 3,   L)ANDA(L,
anda4,        1, 4,   L)ANDA(L,
anda5,        1, 5,   L)ANDA(L,
anda6,        1, 6,   L)ANDA(L,
anda7,        1, 7,   L)ARA(L,
ara,          1,      L)ARA(L,
ara2,         2,      L)ARADA(L,
ara2da1,      2, 1,   L)ARADA(L,
ara2da2,      2, 2,   L)ARADA(L,
ara2da3,      2, 3,   L)ARADA(L,
ara2da4,      2, 4,   L)ARADA(L,
ara2da5,      2, 5,   L)ARADA(L,
ara2da6,      2, 6,   L)ARADA(L,
ara2da7,      2, 7,   L)ARA(L,
ara3,         3,      L)ARADA(L,
ara3da1,      3, 1,   L)ARADA(L,
ara3da2,      3, 2,   L)ARADA(L,
ara3da3,      3, 3,   L)ARADA(L,
ara3da4,      3, 4,   L)ARADA(L,
ara3da5,      3, 5,   L)ARADA(L,
ara3da6,      3, 6,   L)ARADA(L,
ara3da7,      3, 7,   L)ARA(L,
ara4,         4,      L)ARADA(L,
ara4da1,      4, 1,   L)ARADA(L,
ara4da2,      4, 2,   L)ARADA(L,
ara4da3,      4, 3,   L)ARADA(L,
ara4da4,      4, 4,   L)ARADA(L,
ara4da5,      4, 5,   L)ARADA(L,
ara4da6,      4, 6,   L)ARADA(L,
ara4da7,      4, 7,   L)ARA(L,
ara5,         5,      L)ARADA(L,
ara5da1,      5, 1,   L)ARADA(L,
ara5da2,      5, 2,   L)ARADA(L,
ara5da3,      5, 3,   L)ARADA(L,
ara5da4,      5, 4,   L)ARADA(L,
ara5da5,      5, 5,   L)ARADA(L,
ara5da6,      5, 6,   L)ARADA(L,
ara5da7,      5, 7,   L)ARA(L,
ara6,         6,      L)ARADA(L,
ara6da1,      6, 1,   L)ARADA(L,
ara6da2,      6, 2,   L)ARADA(L,
ara6da3,      6, 3,   L)ARADA(L,
ara6da4,      6, 4,   L)ARADA(L,
ara6da5,      6, 5,   L)ARADA(L,
ara6da6,      6, 6,   L)ARADA(L,
ara6da7,      6, 7,   L)ARA(L,
ara7,         7,      L)ARADA(L,
ara7da1,      7, 1,   L)ARADA(L,
ara7da2,      7, 2,   L)ARADA(L,
ara7da3,      7, 3,   L)ARADA(L,
ara7da4,      7, 4,   L)ARADA(L,
ara7da5,      7, 5,   L)ARADA(L,
ara7da6,      7, 6,   L)ARADA(L,
ara7da7,      7, 7,   L)ARADA(L,
arada,        1, 1,   L)ARADA(L,
arada2,       1, 2,   L)ARADA(L,
arada3,       1, 3,   L)ARADA(L,
arada4,       1, 4,   L)ARADA(L,
arada5,       1, 5,   L)ARADA(L,
arada6,       1, 6,   L)ARADA(L,
arada7,       1, 7,   L)DA(L,
da,           1,      L)DA(L,
da2,          2,      L)DA(L,
da3,          3,      L)DA(L,
da4,          4,      L)DA(L,
da5,          5,      L)DA(L,
da6,          6,      L)DA(L,
da7,          7,      junctions)

#include <stdio.h>
// os_next exports
END(junctions,
la_stdin,             L)END(L,
os_delete,            L)END(L,
os_new,               L)END(L,
os_next,              L)END(L,
os_queue,             L)END(L,
os_wordump,           L)E(L,
printf, printf,  os_exports);

ARADANI(aradani,  1, 1, 1);
ARADANI(aradani2, 1, 1, 2);
