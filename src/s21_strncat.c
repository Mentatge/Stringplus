#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  s21_size_t j = 0;
  for (; dest[i] != '\0'; i++) {
    ;
  }
  for (; j < n; j++) {
    dest[i + j] = src[j];
  }
  return dest;

  return dest;
}
