#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int rtn = 0;
  if (str1 != NULL && str2 != NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      rtn = str1[i] - str2[i];
      if (rtn != 0 || (str1[i] == '\0' && str2[i] == '\0')) {
        break;
      }
    }
  }
  return rtn;
}