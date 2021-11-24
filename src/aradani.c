#include "importexportmacros.h"
#include "oars.h"
#define D1 ρ += 1,
#define D2 ρ += 2,
#define D3 ρ += 3,
#define D4 ρ += 4,
#define D5 ρ += 5,
#define D6 ρ += 6,
#define D7 ρ += 7,
#define SO1 ο[α++].v = σ[ρ++].v,
#define SO2 SO1 SO1
#define SO3 SO2 SO1
#define SO4 SO3 SO1
#define SO5 SO4 SO1
#define SO6 SO5 SO1
#define SO7 SO6 SO1
#define OS1 σ[--ρ].c = ο[--α].c,
#define OS2 OS1 OS1
#define OS3 OS2 OS1
#define OS4 OS3 OS1
#define OS5 OS4 OS1
#define OS6 OS5 OS1
#define OS7 OS6 OS1

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
#define Junction(a, b, c, d, e)                                                \
  N(a) { b σ[--ρ].v = c, σ[--ρ].v = d, σ[--ρ].v = e, O; }
#define AN(Tail, Name, Pc, Next)                                               \
  Ray3(D3, SO##Pc, O);                                                         \
  Ray3(D3, D##Pc, C1);                                                         \
  Ray3(D3, D##Pc, C2);                                                         \
  Junction(Name, OS##Pc, D3_D##Pc##_C2, D3_D##Pc##_C1, D3_SO##Pc##_O);         \
  EN(Tail, Name, Next)
#define DA(Tail, Name, Pc, Next)                                               \
  Junction(Name, OS##Pc, D3_D##Pc##_C2, D3_SO##Pc##_O, D3_D##Pc##_C0);         \
  EN(Tail, Name, Next)
#define ANDA(Tail, Name, Pcan, Pcda, Next)                                     \
  Ray4(D3, D##Pcan, D##Pcda, C2);                                              \
  Ray4(D3, SO##Pcan, D##Pcda, O);                                              \
  Ray4(D3, D##Pcan, SO##Pcda, O);                                              \
  Junction(Name, OS##Pcda OS##Pcan, D3_D##Pcan##_D##Pcda##_C2,                 \
           D3_D##Pcan##_SO##Pcda##_O, D3_SO##Pcan##_D##Pcda##_O);              \
  EN(Tail, Name, Next)
#define ARA(Tail, Name, Pc, Head)                                              \
  Ray3(D3, D##Pc, C0);                                                         \
  Junction(Name, OS##Pc, D3_SO##Pc##_O, D3_D##Pc##_C1, D3_D##Pc##_C0);         \
  EN(Tail, Name, Head)
#define ARADA(Tail, Name, Pcara, Pcda, Head)                                   \
  Ray4(D3, D##Pcara, D##Pcda, C0);                                             \
  Junction(Name, OS##Pcara OS##Pcda, D3_SO##Pcara##_D##Pcda##_O,               \
           D3_D##Pcara##_SO##Pcda##_O, D3_D##Pcara##_D##Pcda##_C0);            \
  EN(Tail, Name, Head)
#define ARADANI(Name, Para, Pda, Pan)                                          \
  Ray5(D3, D##Pan, D##Pda, SO##Para, O);                                       \
  Ray5(D3, D##Pan, SO##Pda, D##Para, O);                                       \
  Ray5(D3, SO##Pan, D##Pda, D##Para, O);                                       \
  N(Name) {                                                                    \
    OS3 σ[--ρ].c = D3_D##Pan##_D##Pda##_SO##Para##_O;                          \
    σ[--ρ].c = D3_D##Pan##_SO##Pda##_D##Para##_O;                              \
    σ[--ρ].c = D3_SO##Pan##_D##Pda##_D##Para##_O;                              \
    O;                                                                         \
  }
#define END(Tail, Name, Head)                                                  \
  N(Name);                                                                     \
  EN(Tail, Name, Head)

// clang-format off
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
l_address,            L)END(L,
l_bind,               L)END(L,
l_epoll_create,       L)END(L,
l_epoll_ctl,          L)END(L,
l_epoll_wait,         L)END(L,
l_setnoblock,         L)END(L,
l_socket,             L)END(L,
la_stdin,             L)END(L,
ls_export,            L)END(L,
os_delete,            L)END(L,
os_new,               L)END(L,
os_next,              L)END(L,
os_queue,             L)END(L,
os_wordump,           L)E(L,
printf, printf,  os_exports);











ARADANI(aradani,  1, 1, 1);
ARADANI(aradani2, 1, 1, 2);
