#include "arsi.h"
Iε;
N(init) { C(1); }
/*
const set = Array(22).fill(0);
const pad = (x, v) => x.toString().padStart(2, v);
const funs = set
  .map(
    (x, i, a) =>
      `static void mc${pad(i, "0")}(OARS, n_t c, void**t, void**s){` +
      [...a.slice(0, i).map((x, j) => `t[${j}]=s[${j}]`), "c(T())"].join(",") +
      ";}"
  )
  .join("\n");
const initfun =
  "N(init_mc21){R(void **,b);" +
  set.map((x, i) => `b[${i}]=mc${pad(i, "0")}`).join(",") +
  ";C(1);}";
console.log(funs + "\n" + initfun);
*/
// clang-format off
static void mc00(OARS, n_t c, void**t, void**s){c(T());}
static void mc01(OARS, n_t c, void**t, void**s){t[0]=s[0],c(T());}
static void mc02(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],c(T());}
static void mc03(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],c(T());}
static void mc04(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],c(T());}
static void mc05(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],c(T());}
static void mc06(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],c(T());}
static void mc07(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],c(T());}
static void mc08(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],c(T());}
static void mc09(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],c(T());}
static void mc10(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],c(T());}
static void mc11(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],c(T());}
static void mc12(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],c(T());}
static void mc13(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],c(T());}
static void mc14(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],c(T());}
static void mc15(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],c(T());}
static void mc16(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],c(T());}
static void mc17(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],c(T());}
static void mc18(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],c(T());}
static void mc19(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],t[18]=s[18],c(T());}
static void mc20(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],t[18]=s[18],t[19]=s[19],c(T());}
static void mc21(OARS, n_t c, void**t, void**s){t[0]=s[0],t[1]=s[1],t[2]=s[2],t[3]=s[3],t[4]=s[4],t[5]=s[5],t[6]=s[6],t[7]=s[7],t[8]=s[8],t[9]=s[9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],t[18]=s[18],t[19]=s[19],t[20]=s[20],c(T());}
N(init_mc21){R(void **,b);b[0]=mc00,b[1]=mc01,b[2]=mc02,b[3]=mc03,b[4]=mc04,b[5]=mc05,b[6]=mc06,b[7]=mc07,b[8]=mc08,b[9]=mc09,b[10]=mc10,b[11]=mc11,b[12]=mc12,b[13]=mc13,b[14]=mc14,b[15]=mc15,b[16]=mc16,b[17]=mc17,b[18]=mc18,b[19]=mc19,b[20]=mc20,b[21]=mc21;C(1);}
// clang-format on
EN(tail, init_mc21, exports)
