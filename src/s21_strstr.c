#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  for (; *haystack != '\0'; haystack++) {
    if (*haystack == *needle &&
        s21_strncmp(haystack, needle, s21_strlen(needle)) == 0) {
      res = (char *)haystack;
      break;
    }
  }
  return res;
}
