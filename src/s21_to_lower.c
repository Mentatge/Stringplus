#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = NULL;
  int k = s21_strlen(str);
  res = (char *)calloc(k + 1, sizeof(char));
  for (int i = 0; i < k; i++) {
    if (str[i] > 64 && str[i] < 91) {
      res[i] = str[i] + 32;
    } else {
      res[i] = str[i];
    }
    res[k + 1] = '\0';
  }
  return res;
}