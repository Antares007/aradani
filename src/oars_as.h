#pragma once
#include "etc/evalmap.h"
#define AS(...) EVAL(MAP(A, __VA_ARGS__))
#define Α(...) AS(__VA_ARGS__)
