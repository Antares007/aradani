#include "oars.h"
#define Head                                                                   \
  static N(imports);                                                           \
  static N(exports);                                                           \
  void tail() __attribute__((section(".text.end")));                           \
  N(tail) {}                                                                   \
  N(head) {                                                                    \
    R(n_t, cb);                                                                \
    A4(imports, exports, tail, cb) O;                                          \
  }
#define Imports()                                                              \
  Head static N(imports) { C(, 1); }
#define Exports()                                                              \
  static N(exports) { C(, 1); }
// clang-format off
/*var alfabet = Array(21).fill().map((_, a) => String.fromCharCode(a+0x61))
  console.log(alfabet.map((v, i) => 
  `#define Imports${i}(${alfabet.slice(0,i)}) \
  \tHead struct ο_s { n_t ${alfabet.slice(0, i)}; }; \
  \tstruct ο_s o; \
  \tstatic N(imports) {${ alfabet.slice(0, i).map(v=>`A2(#${v},${i})`).join("") } A(&o) C(, 1); }`
  ).slice(1).join('\n'))*/
#define Imports1(a) 	Head struct ο_s { n_t a; }; 	struct ο_s o; 	static N(imports) {A2(#a,1) A(&o) C(, 1); }
#define Imports2(a,b) 	Head struct ο_s { n_t a,b; }; 	struct ο_s o; 	static N(imports) {A2(#a,2)A2(#b,2) A(&o) C(, 1); }
#define Imports3(a,b,c) 	Head struct ο_s { n_t a,b,c; }; 	struct ο_s o; 	static N(imports) {A2(#a,3)A2(#b,3)A2(#c,3) A(&o) C(, 1); }
#define Imports4(a,b,c,d) 	Head struct ο_s { n_t a,b,c,d; }; 	struct ο_s o; 	static N(imports) {A2(#a,4)A2(#b,4)A2(#c,4)A2(#d,4) A(&o) C(, 1); }
#define Imports5(a,b,c,d,e) 	Head struct ο_s { n_t a,b,c,d,e; }; 	struct ο_s o; 	static N(imports) {A2(#a,5)A2(#b,5)A2(#c,5)A2(#d,5)A2(#e,5) A(&o) C(, 1); }
#define Imports6(a,b,c,d,e,f) 	Head struct ο_s { n_t a,b,c,d,e,f; }; 	struct ο_s o; 	static N(imports) {A2(#a,6)A2(#b,6)A2(#c,6)A2(#d,6)A2(#e,6)A2(#f,6) A(&o) C(, 1); }
#define Imports7(a,b,c,d,e,f,g) 	Head struct ο_s { n_t a,b,c,d,e,f,g; }; 	struct ο_s o; 	static N(imports) {A2(#a,7)A2(#b,7)A2(#c,7)A2(#d,7)A2(#e,7)A2(#f,7)A2(#g,7) A(&o) C(, 1); }
#define Imports8(a,b,c,d,e,f,g,h) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h; }; 	struct ο_s o; 	static N(imports) {A2(#a,8)A2(#b,8)A2(#c,8)A2(#d,8)A2(#e,8)A2(#f,8)A2(#g,8)A2(#h,8) A(&o) C(, 1); }
#define Imports9(a,b,c,d,e,f,g,h,i) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i; }; 	struct ο_s o; 	static N(imports) {A2(#a,9)A2(#b,9)A2(#c,9)A2(#d,9)A2(#e,9)A2(#f,9)A2(#g,9)A2(#h,9)A2(#i,9) A(&o) C(, 1); }
#define Imports10(a,b,c,d,e,f,g,h,i,j) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j; }; 	struct ο_s o; 	static N(imports) {A2(#a,10)A2(#b,10)A2(#c,10)A2(#d,10)A2(#e,10)A2(#f,10)A2(#g,10)A2(#h,10)A2(#i,10)A2(#j,10) A(&o) C(, 1); }
#define Imports11(a,b,c,d,e,f,g,h,i,j,k) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k; }; 	struct ο_s o; 	static N(imports) {A2(#a,11)A2(#b,11)A2(#c,11)A2(#d,11)A2(#e,11)A2(#f,11)A2(#g,11)A2(#h,11)A2(#i,11)A2(#j,11)A2(#k,11) A(&o) C(, 1); }
#define Imports12(a,b,c,d,e,f,g,h,i,j,k,l) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l; }; 	struct ο_s o; 	static N(imports) {A2(#a,12)A2(#b,12)A2(#c,12)A2(#d,12)A2(#e,12)A2(#f,12)A2(#g,12)A2(#h,12)A2(#i,12)A2(#j,12)A2(#k,12)A2(#l,12) A(&o) C(, 1); }
#define Imports13(a,b,c,d,e,f,g,h,i,j,k,l,m) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m; }; 	struct ο_s o; 	static N(imports) {A2(#a,13)A2(#b,13)A2(#c,13)A2(#d,13)A2(#e,13)A2(#f,13)A2(#g,13)A2(#h,13)A2(#i,13)A2(#j,13)A2(#k,13)A2(#l,13)A2(#m,13) A(&o) C(, 1); }
#define Imports14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n; }; 	struct ο_s o; 	static N(imports) {A2(#a,14)A2(#b,14)A2(#c,14)A2(#d,14)A2(#e,14)A2(#f,14)A2(#g,14)A2(#h,14)A2(#i,14)A2(#j,14)A2(#k,14)A2(#l,14)A2(#m,14)A2(#n,14) A(&o) C(, 1); }
#define Imports15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o; }; 	struct ο_s o; 	static N(imports) {A2(#a,15)A2(#b,15)A2(#c,15)A2(#d,15)A2(#e,15)A2(#f,15)A2(#g,15)A2(#h,15)A2(#i,15)A2(#j,15)A2(#k,15)A2(#l,15)A2(#m,15)A2(#n,15)A2(#o,15) A(&o) C(, 1); }
#define Imports16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p; }; 	struct ο_s o; 	static N(imports) {A2(#a,16)A2(#b,16)A2(#c,16)A2(#d,16)A2(#e,16)A2(#f,16)A2(#g,16)A2(#h,16)A2(#i,16)A2(#j,16)A2(#k,16)A2(#l,16)A2(#m,16)A2(#n,16)A2(#o,16)A2(#p,16) A(&o) C(, 1); }
#define Imports17(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q; }; 	struct ο_s o; 	static N(imports) {A2(#a,17)A2(#b,17)A2(#c,17)A2(#d,17)A2(#e,17)A2(#f,17)A2(#g,17)A2(#h,17)A2(#i,17)A2(#j,17)A2(#k,17)A2(#l,17)A2(#m,17)A2(#n,17)A2(#o,17)A2(#p,17)A2(#q,17) A(&o) C(, 1); }
#define Imports18(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r; }; 	struct ο_s o; 	static N(imports) {A2(#a,18)A2(#b,18)A2(#c,18)A2(#d,18)A2(#e,18)A2(#f,18)A2(#g,18)A2(#h,18)A2(#i,18)A2(#j,18)A2(#k,18)A2(#l,18)A2(#m,18)A2(#n,18)A2(#o,18)A2(#p,18)A2(#q,18)A2(#r,18) A(&o) C(, 1); }
#define Imports19(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s; }; 	struct ο_s o; 	static N(imports) {A2(#a,19)A2(#b,19)A2(#c,19)A2(#d,19)A2(#e,19)A2(#f,19)A2(#g,19)A2(#h,19)A2(#i,19)A2(#j,19)A2(#k,19)A2(#l,19)A2(#m,19)A2(#n,19)A2(#o,19)A2(#p,19)A2(#q,19)A2(#r,19)A2(#s,19) A(&o) C(, 1); }
#define Imports20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) 	Head struct ο_s { n_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t; }; 	struct ο_s o; 	static N(imports) {A2(#a,20)A2(#b,20)A2(#c,20)A2(#d,20)A2(#e,20)A2(#f,20)A2(#g,20)A2(#h,20)A2(#i,20)A2(#j,20)A2(#k,20)A2(#l,20)A2(#m,20)A2(#n,20)A2(#o,20)A2(#p,20)A2(#q,20)A2(#r,20)A2(#s,20)A2(#t,20) A(&o) C(, 1); }
/*var alfabet = Array(21).fill().map((_, a) => String.fromCharCode(a+0x61))
  console.log(alfabet.map((v, i) => 
  `#define Exports${i}(${alfabet.slice(0,i)}) \
  \tstatic N(exports) {${ alfabet.slice(0, i).map(v=>`A2(#${v},${v})`).join("") } C(, 1); }`
  ).slice(1).join('\n'))*/
#define Exports1(a) static N(exports) {A2(#a,a) C(, 1); }
#define Exports2(a,b) static N(exports) {A2(#a,a)A2(#b,b) C(, 1); }
#define Exports3(a,b,c)	static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c) C(, 1); }
#define Exports4(a,b,c,d) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d) C(, 1); }
#define Exports5(a,b,c,d,e) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e) C(, 1); }
#define Exports6(a,b,c,d,e,f)	static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f) C(, 1); }
#define Exports7(a,b,c,d,e,f,g)	static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g) C(, 1); }
#define Exports8(a,b,c,d,e,f,g,h)	static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h) C(, 1); }
#define Exports9(a,b,c,d,e,f,g,h,i) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i) C(, 1); }
#define Exports10(a,b,c,d,e,f,g,h,i,j) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j) C(, 1); }
#define Exports11(a,b,c,d,e,f,g,h,i,j,k) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k) C(, 1); }
#define Exports12(a,b,c,d,e,f,g,h,i,j,k,l) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l) C(, 1); }
#define Exports13(a,b,c,d,e,f,g,h,i,j,k,l,m) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m) C(, 1); }
#define Exports14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n) C(, 1); }
#define Exports15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n)A2(#o,o) C(, 1); }
#define Exports16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n)A2(#o,o)A2(#p,p) C(, 1); }
#define Exports17(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n)A2(#o,o)A2(#p,p)A2(#q,q) C(, 1); }
#define Exports18(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n)A2(#o,o)A2(#p,p)A2(#q,q)A2(#r,r) C(, 1); }
#define Exports19(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n)A2(#o,o)A2(#p,p)A2(#q,q)A2(#r,r)A2(#s,s) C(, 1); }
#define Exports20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t)static N(exports) {A2(#a,a)A2(#b,b)A2(#c,c)A2(#d,d)A2(#e,e)A2(#f,f)A2(#g,g)A2(#h,h)A2(#i,i)A2(#j,j)A2(#k,k)A2(#l,l)A2(#m,m)A2(#n,n)A2(#o,o)A2(#p,p)A2(#q,q)A2(#r,r)A2(#s,s)A2(#t,t) C(, 1); }
// clang-format on

#include "oars.h"
Imports2(fun1, fun2);
N(e1) {}
N(e2) {}
N(e3) {}
Exports3(e1, e2, e3);
