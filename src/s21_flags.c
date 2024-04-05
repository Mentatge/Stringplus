#include "s21_string.h"

char *s21_flags(char *src, long int width, specs_st *sp, char *tmp) {
  char *inserted = NULL;
  if (sp->flag == '#') {
    if (sp->specifier == 'o') {
      inserted = s21_insert(tmp, "0", 0);
      s21_strncpy(tmp, inserted, s21_strlen(inserted));
    }
    if (sp->specifier == 'x') {
      inserted = s21_insert(tmp, "0x", 0);
      s21_strncpy(tmp, inserted, s21_strlen(inserted));
    }
    if (sp->specifier == 'X') {
      inserted = s21_insert(tmp, "0X", 0);
      s21_strncpy(tmp, inserted, s21_strlen(inserted));
    }
  }
  if (sp->flag != '-') {
    (void)width;
  }
  if (inserted != NULL) {
    free(inserted);
  }
  return src;
}
