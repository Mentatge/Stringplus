#include <string.h>

#include "s21_string.h"

void s21_p(long unsigned int *base, char *src) {
  long unsigned int ptr = (long unsigned int)base;
  char s[128] = "";
  char s1[256] = "";
  s1[0] = '0';
  s1[1] = 'x';
  s21_hex(ptr, s);
  s21_strncat(s1, s, s21_strlen(s));
  s21_strncpy(src, s1, s21_strlen(s1));
}
