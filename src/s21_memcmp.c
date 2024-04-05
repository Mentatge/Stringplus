#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int rtn = 0;
  while (n != 0) {
    if ((*(const unsigned char *)str1 < *(const unsigned char *)str2) ||
        (*(const unsigned char *)str1 > *(const unsigned char *)str2)) {
      rtn = (*(const unsigned char *)str1 - *(const unsigned char *)str2);
      break;
    }
    n--;
    str1++;
    str2++;
  }

  return rtn;
}