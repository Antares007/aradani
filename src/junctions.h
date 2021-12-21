#pragma once
#include "oars.h"
#include "exportmacros.h"
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
  static N(a##_##b##_##c) { a b c; }
#define Ray4(a, b, c, d)                                                       \
  static N(a##_##b##_##c##_##d) { a b c d; }
#define Ray5(a, b, c, d, e)                                                    \
  static N(a##_##b##_##c##_##d##_##e) { a b c d e; }
#define Junction(a, b, c, d, e)                                                \
  N(a) { b σ[--ρ].v = c, σ[--ρ].v = d, σ[--ρ].v = e, O; }
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
N(and);        
N(and2);       
N(and2or);     
N(and2or2);    
N(and2or3);    
N(and2or4);    
N(and2or5);    
N(and2or6);    
N(and2or7);    
N(and3);       
N(and3or);     
N(and3or2);    
N(and3or3);    
N(and3or4);    
N(and3or5);    
N(and3or6);    
N(and3or7);    
N(and4);       
N(and4or);     
N(and4or2);    
N(and4or3);    
N(and4or4);    
N(and4or5);    
N(and4or6);    
N(and4or7);    
N(and5);       
N(and5or);     
N(and5or2);    
N(and5or3);    
N(and5or4);    
N(and5or5);    
N(and5or6);    
N(and5or7);    
N(and6);       
N(and6or);     
N(and6or2);    
N(and6or3);    
N(and6or4);    
N(and6or5);    
N(and6or6);    
N(and6or7);    
N(and7);       
N(and7or);     
N(and7or2);    
N(and7or3);    
N(and7or4);    
N(and7or5);    
N(and7or6);    
N(and7or7);    
N(andor);      
N(andor2);     
N(andor3);     
N(andor4);     
N(andor5);     
N(andor6);     
N(andor7);     
N(not);        
N(not2);       
N(not2and);    
N(not2and2);   
N(not2and2or); 
N(not2and2or2);
N(not2and2or3);
N(not2and3);   
N(not2and3or); 
N(not2and3or2);
N(not2and3or3);
N(not2and4);   
N(not2and5);   
N(not2and6);   
N(not2and7);   
N(not2andor);  
N(not2andor2); 
N(not2andor3); 
N(not2or);     
N(not2or2);    
N(not2or3);    
N(not2or4);    
N(not2or5);    
N(not2or6);    
N(not2or7);    
N(not3);       
N(not3and);    
N(not3and2);   
N(not3and2or); 
N(not3and2or2);
N(not3and2or3);
N(not3and3);   
N(not3and3or); 
N(not3and3or2);
N(not3and3or3);
N(not3and4);   
N(not3and5);   
N(not3and6);   
N(not3and7);   
N(not3andor);  
N(not3andor2); 
N(not3andor3); 
N(not3or);     
N(not3or2);    
N(not3or3);    
N(not3or4);    
N(not3or5);    
N(not3or6);    
N(not3or7);    
N(not4);       
N(not4and);    
N(not4and2);   
N(not4and3);   
N(not4and4);   
N(not4and5);   
N(not4and6);   
N(not4and7);   
N(not4or);     
N(not4or2);    
N(not4or3);    
N(not4or4);    
N(not4or5);    
N(not4or6);    
N(not4or7);    
N(not5);       
N(not5and);    
N(not5and2);   
N(not5and3);   
N(not5and4);   
N(not5and5);   
N(not5and6);   
N(not5and7);   
N(not5or);     
N(not5or2);    
N(not5or3);    
N(not5or4);    
N(not5or5);    
N(not5or6);    
N(not5or7);    
N(not6);       
N(not6and);    
N(not6and2);   
N(not6and3);   
N(not6and4);   
N(not6and5);   
N(not6and6);   
N(not6and7);   
N(not6or);     
N(not6or2);    
N(not6or3);    
N(not6or4);    
N(not6or5);    
N(not6or6);    
N(not6or7);    
N(not7);       
N(not7and);    
N(not7and2);   
N(not7and3);   
N(not7and4);   
N(not7and5);   
N(not7and6);   
N(not7and7);   
N(not7or);     
N(not7or2);    
N(not7or3);    
N(not7or4);    
N(not7or5);    
N(not7or6);    
N(not7or7);    
N(notand);     
N(notand2);    
N(notand2or);  
N(notand2or2); 
N(notand2or3); 
N(notand3);    
N(notand3or);  
N(notand3or2); 
N(notand3or3); 
N(notand4);    
N(notand5);    
N(notand6);    
N(notand7);    
N(notandor);   
N(notandor2);  
N(notandor3);  
N(notor);      
N(notor2);     
N(notor3);     
N(notor4);     
N(notor5);     
N(notor6);     
N(notor7);     
N(or);         
N(or2);        
N(or3);        
N(or4);        
N(or5);        
N(or6);        
N(or7);        
