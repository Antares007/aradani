#pragma once
/*
console.log(
  Array(7 + 7 + 7 + 1)
    .fill()
    .map((_, a) => String.fromCharCode(a + 0x61))
    .map(
      (v, i, a) =>
        `#define A${i}(${a.slice(0, i)}) ${a
          .slice(0, i)
          .map((v) => `A(${v})`)
          .join("")}`
    )
    .slice(2)
    .join("\n")
);
*/
// clang-format off
#define A2(a,b) A(a)A(b)
#define A3(a,b,c) A(a)A(b)A(c)
#define A4(a,b,c,d) A(a)A(b)A(c)A(d)
#define A5(a,b,c,d,e) A(a)A(b)A(c)A(d)A(e)
#define A6(a,b,c,d,e,f) A(a)A(b)A(c)A(d)A(e)A(f)
#define A7(a,b,c,d,e,f,g) A(a)A(b)A(c)A(d)A(e)A(f)A(g)
#define A8(a,b,c,d,e,f,g,h) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)
#define A9(a,b,c,d,e,f,g,h,i) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)
#define A10(a,b,c,d,e,f,g,h,i,j) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)
#define A11(a,b,c,d,e,f,g,h,i,j,k) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)
#define A12(a,b,c,d,e,f,g,h,i,j,k,l) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)
#define A13(a,b,c,d,e,f,g,h,i,j,k,l,m) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)
#define A14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)
#define A15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)
#define A16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)
#define A17(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)
#define A18(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)
#define A19(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)
#define A20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)
#define A21(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)A(u)
