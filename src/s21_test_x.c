#include "s21_string.h"

void s21_hex(long unsigned int base, char *src) {
  char s[128] = "";
  // char ox[256] = ""; // FIX FIX FIX FIX
  char h[16] = "0123456789abcdef";
  char x[2] = "";
  char tmp;
  long unsigned int value = base;
  int j = 0;

  if (value == 0) s[0] = '0';
  while (value > 0) {
    x[0] = h[value % 16];
    s21_strncat(s, x, 2);
    value = value / 16;
  }

  if (base != 0) {
    for (int i = s21_strlen(s) - 1; j < i; i--, j++) {
      tmp = s[j];
      s[j] = s[i];
      s[i] = tmp;
    }
  }

  s21_strncat(src, s, s21_strlen(s));
}
