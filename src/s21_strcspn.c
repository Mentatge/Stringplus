#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  const char *str_tmp1, *str_tmp2;
  str_tmp1 = str1;
  while (*str_tmp1 != '\0') {
    str_tmp2 = str2;
    while (*str_tmp2 != '\0') {
      if (*str_tmp1 == *str_tmp2) return (str_tmp1 - str1);
      str_tmp2++;
    }
    str_tmp1++;
  }
  return (str_tmp1 - str1);
}
