#pragma once

typedef struct stdiofun_s {
  int (*printf)(const char *__restrict __format, ...);
  int (*puts)(const char *__s);
} stdiofun_t;
