#include <math.h>
#include <stdio.h>

#include "s21_string.h"

int RemoveTrailingZeores(char *dest) {
  s21_size_t i = s21_strlen(dest) - 1;
  int tmp = 0;

  for (; dest[i] == '0' || dest[i] == '.'; i--) {
    if (tmp == '.') {
      break;
    }
    tmp = dest[i];
    dest[i] = '\0';
  }
  return 0;
}

int s21_g(double num, char *dest, long int accuracy, specs_st *sp) {
  if (accuracy < 0) {
    accuracy = 6;
  }
  int exp = 0;
  char tmp[128] = "";
  exp = s21_e(num, tmp, accuracy, sp);
  int P = 6;
  if (accuracy == 0) {
    P = 1;
  } else if (accuracy > 0) {
    P = accuracy;
  }

  if (P > exp && exp >= -4) {
    s21_ftoa(num, dest, (P - (exp + 1)), sp->flag);
    if (sp->flag != '#') RemoveTrailingZeores(dest);
  } else {
    s21_e(num, dest, P - 1, sp);
  }

  return 1;
}
