#pragma once
// clang-format off

#define D1 ρ += 1,
#define D2 ρ += 2,
#define D3 ρ += 3,
#define D4 ρ += 4,
#define D5 ρ += 5,
#define D6 ρ += 6,
#define D7 ρ += 7,
#define SO1 ο[α++].v = ο[ρ++].v,
#define SO2 SO1 SO1
#define SO3 SO2 SO1
#define SO4 SO3 SO1
#define SO5 SO4 SO1
#define SO6 SO5 SO1
#define SO7 SO6 SO1
#define OS1 ο[--ρ].c = ο[--α].c,
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
  static N(a##_##b##_##c) { a b c; }
#define Ray4(a, b, c, d)                                                       \
  static N(a##_##b##_##c##_##d) { a b c d; }
#define Ray5(a, b, c, d, e)                                                    \
  static N(a##_##b##_##c##_##d##_##e) { a b c d e; }
#define Junction(a, b, c, d, e)                                                \
  N(a) { b ο[--ρ].v = c, ο[--ρ].v = d, ο[--ρ].v = e, O; }

#define AND(Tail, Name, Pc, Head)                                              \
  Ray3(D3, D##Pc, C0);                                                         \
  Ray3(D3, SO##Pc, O);                                                         \
  Ray3(D3, D##Pc, C2);                                                         \
  Junction(Name, OS##Pc, D3_D##Pc##_C2, D3_SO##Pc##_O, D3_D##Pc##_C0);         \
  EN(Tail, Name, Head)
#define ANDOR(Tail, Name, PcAnd, PcOr, Head)                                   \
  Ray4(D3, D##PcAnd, D##PcOr, C2);                                             \
  Ray4(D3, SO##PcAnd, D##PcOr, O);                                             \
  Ray4(D3, D##PcAnd, SO##PcOr, O);                                             \
  Junction(Name, OS##PcOr OS##PcAnd, D3_D##PcAnd##_D##PcOr##_C2,               \
           D3_SO##PcAnd##_D##PcOr##_O, D3_D##PcAnd##_SO##PcOr##_O);            \
  EN(Tail, Name, Head)
#define NOT(Tail, Name, Pc, Head)                                              \
  Ray3(D3, D##Pc, C1);                                                         \
  Junction(Name, OS##Pc, D3_SO##Pc##_O, D3_D##Pc##_C1, D3_D##Pc##_C0);         \
  EN(Tail, Name, Head)
#define NOTAND(Tail, Name, PcNot, PcAnd, Head)                                 \
  Ray4(D3, D##PcNot, D##PcAnd, C0);                                            \
  Junction(Name, OS##PcAnd OS##PcNot, D3_SO##PcNot##_D##PcAnd##_O,             \
           D3_D##PcNot##_SO##PcAnd##_O, D3_D##PcNot##_D##PcAnd##_C0);          \
  EN(Tail, Name, Head)
#define NOTOR(Tail, Name, PcNot, PcOr, Head)                                   \
  Ray4(D3, D##PcNot, D##PcOr, C1);                                             \
  Junction(Name, OS##PcNot OS##PcOr, D3_SO##PcNot##_D##PcOr##_O,               \
           D3_D##PcNot##_D##PcOr##_C1, D3_D##PcNot##_SO##PcOr##_O);            \
  EN(Tail, Name, Head)
#define OR(Tail, Name, Pc, Head)                                               \
  Junction(Name, OS##Pc, D3_D##Pc##_C2, D3_D##Pc##_C1, D3_SO##Pc##_O);         \
  EN(Tail, Name, Head)
#define NOTANDOR(Tail, Name, PcNot, PcAnd, PcOr, Head)                         \
  Ray5(D3, SO##PcNot,  D##PcAnd,  D##PcOr, O);                                 \
  Ray5(D3,  D##PcNot, SO##PcAnd,  D##PcOr, O);                                 \
  Ray5(D3,  D##PcNot,  D##PcAnd, SO##PcOr, O);                                 \
  Junction(Name, OS##PcOr OS##PcAnd OS##PcNot,                                 \
           D3_SO##PcNot##_D##PcAnd##_D##PcOr##_O,                              \
           D3_D##PcNot##_SO##PcAnd##_D##PcOr##_O,                              \
           D3_D##PcNot##_D##PcAnd##_SO##PcOr##_O);                             \
  EN(Tail, Name, Head)
