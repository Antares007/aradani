#include "arsi.h"
// clang-format off
int(*print)(const char*, ...);I(0,
printf, print,          L)IN(L,
//
os_next,                L)IN(L,
//
and,                    L)IN(L,
s_pith,            import);

N(os_wordump) {
  print("ο:%p α:%02ld               ρ: %02ld σ: %p\n", ο, α, ρ, σ);
  long i = 0;
  while (i < α) {
    print("%016lx ", ο[i].Q);
    if (++i < α)
      print("%016lx\n", ο[i].Q);
    else
      print("\n");
    i++;
  }
  C(1);
}

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
  void *b = &ο[α];
  long e;
  A9(6, 3, 4, 2, 8, 9, 7, 3, 9) e = α;
  A7(0, 8, b, e, qsort, os_wordump, and) O;
  // A2(6, 9) C(1);
}

void init() { 
  p_t *σ = (void*)s_pith, *ο = σ[0].v;
  q_t α = σ[1].q, ρ = σ[2].q;
  ο[α++].v = მთავარი;
  ο[α++].v = and;
  σ[1].q = α;
  σ[2].q = ρ;
}

// clang-format off
EN(tail,          
s_pith,           export);
