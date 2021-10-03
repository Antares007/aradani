#include "aradani.h"

void tail() __attribute__((section(".text.end")));
N(tail) {}
n_t წერტილი;

N(ან_გადასვლა) { σ[ρ + 0].c(T()); }
N(და_გადასვლა) { σ[ρ + 1].c(T()); }
N(არა_გადასვლა) { σ[ρ + 2].c(T()); }

n_t სიტყვა;
n_t სიტყვა2;
char *names[] = {"სიტყვა"};
struct os {
  n_t სიტყვა;
};
struct os o = {0};
N(შემდეგი) {
  R(void *, addr);
  R(char *, name);
  for (long i = 0; i < sizeof(names) / sizeof(*names); i++)
    if (cmp(names[i], name))
      ((n_t *)&o)[i] = addr;
  A6(name, addr, და_გადასვლა, σ[-2].v, 3, წერტილი) O;
}

N(ჩიხი) {
  if (α)
    A4(არა_გადასვლა, σ[-2].v, 1, წერტილი) O;
  else{
    for (long i = 0; i < sizeof(names) / sizeof(*names); i++)
      if (((n_t *)&o)[i] == 0)
        return A5(names[i], არა_გადასვლა, σ[-2].v, 2, წერტილი) O;
    // დავაექსპორტოთ
  }
}

void head() __attribute__((section(".text.begin")));
N(head) {
  R(n_t, წერტილი_);
  R(n_t, იმპორტექპორტი_);
  წერტილი = წერტილი_;
  A4(შემდეგი, ჩიხი, tail, იმპორტექპორტი_) O;
}

// N(გამარჯობა) {
//  R(p_t *, kσ);
//  if (σ[-1].v != kσ) { // გამარჯობა
//    σ[-2].v = kσ;
//    A5(σ, ან_გადასვლა, σ[-1].v, 2, წერტილი) O;
//  } else { // გაგიმარჯოს
//    A5(σ, ან_გადასვლა, σ[-2].v, 2, წერტილი) O;
//  }
//}
//
