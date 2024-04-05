#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_str = S21_NULL;

  if (src && trim_chars) {
    char *begin = (char *)src;
    char *end = (char *)src + s21_strlen(src);

    for (; *begin && s21_strchr(trim_chars, *begin); begin++)
      ;
    for (; end != begin && s21_strchr(trim_chars, *(end - 1)); end--)
      ;
    trim_str = (char *)malloc((end - begin) * sizeof(char));

    if (trim_str) {
      s21_strncpy(trim_str, begin, end - begin);
      *(trim_str + (end - begin)) = '\0';
    }
  }
  return trim_str;
}
