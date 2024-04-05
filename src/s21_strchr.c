#include "s21_string.h"

char *s21_strchr(char const *src, int c) {
  char ch = (char)c;
  char *res = NULL;
  int i = 0;
  if (src != NULL) {
    for (; src[i] != '\0'; i++) {
      if (src[i] == ch) {
        res = (char *)(src + i);
        break;
      }
    }
    if (src[i] == '\0' && ch == '\0') {
      res = (char *)(src + i);
    }
    if (src[0] == '\0' && ch == '\0') {
      res = (char *)src;
    }
  }
  return res;
}
