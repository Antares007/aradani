/*
let set = Array(3).fill(0);
let pad = (x, v) => x.toString().padStart(2, v);
let funs = set
  .map(
    (x, i, a) =>
      `static void mc${pad(i, "0")}(void**t,void**s){` +
      a
        .slice(0, i)
        .map((x, j) => `t[${pad(j, " ")}]=s[${pad(j, " ")}]`)
        .join(",") +
      ";}"
  )
  .join("\n");
let initfun =
  "void init_mc21(void **b){" +
  set.map((x, i) => `b[${pad(i, " ")}]=mc${pad(i, "0")}`).join(",") +
  ";}";
console.log(funs + "\n" + initfun);
*/
// clang-format off
static void mc00(void**t,void**s){;}
static void mc01(void**t,void**s){t[ 0]=s[ 0];}
static void mc02(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1];}
static void mc03(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2];}
static void mc04(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3];}
static void mc05(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4];}
static void mc06(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5];}
static void mc07(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6];}
static void mc08(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7];}
static void mc09(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8];}
static void mc10(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9];}
static void mc11(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10];}
static void mc12(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11];}
static void mc13(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12];}
static void mc14(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13];}
static void mc15(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14];}
static void mc16(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15];}
static void mc17(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16];}
static void mc18(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17];}
static void mc19(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],t[18]=s[18];}
static void mc20(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],t[18]=s[18],t[19]=s[19];}
static void mc21(void**t,void**s){t[ 0]=s[ 0],t[ 1]=s[ 1],t[ 2]=s[ 2],t[ 3]=s[ 3],t[ 4]=s[ 4],t[ 5]=s[ 5],t[ 6]=s[ 6],t[ 7]=s[ 7],t[ 8]=s[ 8],t[ 9]=s[ 9],t[10]=s[10],t[11]=s[11],t[12]=s[12],t[13]=s[13],t[14]=s[14],t[15]=s[15],t[16]=s[16],t[17]=s[17],t[18]=s[18],t[19]=s[19],t[20]=s[20];}
void init_mc21(void **b){b[ 0]=mc00,b[ 1]=mc01,b[ 2]=mc02,b[ 3]=mc03,b[ 4]=mc04,b[ 5]=mc05,b[ 6]=mc06,b[ 7]=mc07,b[ 8]=mc08,b[ 9]=mc09,b[10]=mc10,b[11]=mc11,b[12]=mc12,b[13]=mc13,b[14]=mc14,b[15]=mc15,b[16]=mc16,b[17]=mc17,b[18]=mc18,b[19]=mc19,b[20]=mc20,b[21]=mc21;}
