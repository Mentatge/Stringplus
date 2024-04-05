#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *arr = str;
  void *res = S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (arr[i] == c) {
      res = (void *)(arr + i);
      break;
    }
  }
  return res;
}
