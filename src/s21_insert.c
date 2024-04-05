#include <stdlib.h>

#include "s21_string.h"

char *s21_strcat(char *dest, const char *src);

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *rtn_value = S21_NULL;
  s21_size_t src_len = s21_strlen(src), str_len = s21_strlen(str),
             sum = start_index + str_len,
             new_line = (sum > src_len ? sum : src_len);
  if (start_index <= src_len) {
    char *str1 = calloc(new_line + 1, sizeof(char));
    s21_strncpy(str1, src, start_index);
    s21_strcat(str1, str);
    s21_strcat(str1, src + start_index);
    rtn_value = str1;
  }
  return rtn_value;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t len = s21_strlen(dest);
  int i = 0;
  for (; src[i] != '\0'; i++) {
    dest[len + i] = src[i];
  }
  dest[len + i] = '\0';
  return dest;
}
