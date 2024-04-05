#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest == NULL) {
    return NULL;
  }
  char *ret = dest;
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  dest[n + 1] = '\0';

  return ret;
}