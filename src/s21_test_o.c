#include "s21_string.h"

void s21_octal(long unsigned int base, char *src) {
  char s[128] = "";
  // char o[128] = "";
  char h[8] = "01234567";
  char x[2] = "";
  char tmp;
  long unsigned int value = base;
  int j = 0;

  if (value == 0) {
    {
      s[0] = '0';
      s[1] = '\0';
    };
  }
  while (value > 0) {
    x[0] = h[value % 8];
    // x[1] = '\0';
    s21_strncat(s, x, 1);
    value = value / 8;
  }

  if (base != 0) {
    for (int i = s21_strlen(s) - 1; j < i; i--, j++) {
      tmp = s[j];
      s[j] = s[i];
      s[i] = tmp;
    }
  }

  s21_strncpy(src, s, s21_strlen(s));
}
