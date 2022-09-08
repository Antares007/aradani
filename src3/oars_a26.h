#pragma once
/*
console.log(
  Array(2.7 * 10)
    .fill()
    .map((_, a) => String.fromCharCode(a + 0x61))
    .map(
      (v, i, a) =>
        `#define A${i}(${a.slice(0, i)}) ${a
          .slice(0, i - 1)
          .map((v) => `A(${v})`)
          .join("")} ${a[i - 1]}(T)`
    )
    .slice(1)
    .join("\n")
);
*/
// clang-format off
#define A1(a)  a(T)
#define A2(a,b) A(a) b(T)
#define A3(a,b,c) A(a)A(b) c(T)
#define A4(a,b,c,d) A(a)A(b)A(c) d(T)
#define A5(a,b,c,d,e) A(a)A(b)A(c)A(d) e(T)
#define A6(a,b,c,d,e,f) A(a)A(b)A(c)A(d)A(e) f(T)
#define A7(a,b,c,d,e,f,g) A(a)A(b)A(c)A(d)A(e)A(f) g(T)
#define A8(a,b,c,d,e,f,g,h) A(a)A(b)A(c)A(d)A(e)A(f)A(g) h(T)
#define A9(a,b,c,d,e,f,g,h,i) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h) i(T)
#define A10(a,b,c,d,e,f,g,h,i,j) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i) j(T)
#define A11(a,b,c,d,e,f,g,h,i,j,k) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j) k(T)
#define A12(a,b,c,d,e,f,g,h,i,j,k,l) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k) l(T)
#define A13(a,b,c,d,e,f,g,h,i,j,k,l,m) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l) m(T)
#define A14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m) n(T)
#define A15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n) o(T)
#define A16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o) p(T)
#define A17(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p) q(T)
#define A18(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q) r(T)
#define A19(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r) s(T)
#define A20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s) t(T)
#define A21(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t) u(T)
#define A22(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)A(u) v(T)
#define A23(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)A(u)A(v) w(T)
#define A24(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)A(u)A(v)A(w) x(T)
#define A25(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)A(u)A(v)A(w)A(x) y(T)
#define A26(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z) A(a)A(b)A(c)A(d)A(e)A(f)A(g)A(h)A(i)A(j)A(k)A(l)A(m)A(n)A(o)A(p)A(q)A(r)A(s)A(t)A(u)A(v)A(w)A(x)A(y) z(T)
