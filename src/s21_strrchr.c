#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *rtn = S21_NULL;
  if (str != S21_NULL) {
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == (char)c) {
        rtn = &str[i];
      }
    }
  }
  return (char *)rtn;
}
