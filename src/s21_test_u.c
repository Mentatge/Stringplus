#include "s21_string.h"

void s21_u(long unsigned int base, char *src, specs_st *sp) {
  unsigned int value = 0;
  char s[128] = "";
  unsigned long int value2 = 0;
  if (sp->length != 'l') {
    value = (unsigned int)base;
    s21_itoa_unsigned(value, s);
  } else {
    value2 = (unsigned long int)base;
    s21_itoa_unsigned(value2, s);
  }
  s21_strncpy(src, s, s21_strlen(s));
}
