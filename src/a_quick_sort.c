#include "arsi.h"
// clang-format off
IBS(                L)IN(L,
debugger,           L)IN(L,
god,                L)IN(L,
gor,                L)IN(L,
got,                L)IN(L,
os_wordump,         L)IN(L, //
and,          imports);
SarP(init)(god)
N(qsort);

void swap(long *a, long *b) {
  long t = *a;
  *a = *b;
  *b = t;
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
long partition(long arr[], long low, long high) {
  long pivot = arr[high]; // pivot
  long i = (low - 1);     // Index of smaller element and indicates the right
                          // position of pivot found so far
  for (long j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
N(qsort_next) {
  R(long, e);
  R(long *, a);
  if (e < α) {
    R(long, hi);
    R(long, lo);
    if (lo < hi) {
      long pivot = partition(a, lo, hi);
      A7(lo, pivot - 1, pivot + 1, hi, a, e, qsort) O;
    } else
      A3(a, e, qsort) O;
  } else
    C(1);
}
N(qsort) { A3(os_wordump, qsort_next, and) O; }
N(მთავარი) {
  void *b = &σ[α];
  long e;
  A9(6, 3, 4, 2, 8, 9, 7, 3, 9) e = α;
  A7(0, 8, b, e, qsort, os_wordump, and) O;
}
N(deb) { Α(debugger, მთავარი, and) O; }

EN(tail,          
deb,          exports);
