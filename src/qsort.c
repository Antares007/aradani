#include "oars.h"
/*
algorithm partition(A, lo, hi) is
  pivot := A[hi]
  i := lo - 1
  for j := lo to hi do
    if A[j] <= pivot then
      i := i + 1
      swap A[i] with A[j]
  return i
*/
