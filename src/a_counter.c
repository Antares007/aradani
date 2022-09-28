#include "arsi.h"
N(div);
N(text);
N(da);
N(da2);
N(term);
N(async_nar) {
  //
}
N(s0) {

  A18(
    div,     "+", text, da2, div, s0, da,
    div, da, "-", text, da2, div, s0, da,
    "0", text, da2
  ) O;

}
N(S) {
     A2("b", term) O;
  A4(S, "a", term, da2) O;
  A4(S, "x", term, da2) O;
}
/*
 w w an w an w da
function counter(d) {
  return o => {
    o.button(o => { o.text('+'); if (d > 0) o.div(counter(d - 1)) })
    o.button(o => { o.text('-'); if (d > 0) o.div(counter(d - 1)) })
    o.text('0')
  }
}
function pith(o) {
  o(1)
  o(2)
 }
function bark(p){
  var a = 0
  p(function o(r){
    a=a+r
  })
  return a
}
alert( 1 + 2)
*/
