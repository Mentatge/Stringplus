#include <stdarg.h>
#include <stdio.h>

#include "s21_string.h"

int ParseSpecs(const char *format, specs_st *sp, va_list ap);
static void cpychr(char *dest, char sym);
static int GetWidth(char *tmp, va_list ap);
static int GetAccuracy(char *tmp, va_list ap);
static int getLength(char *tmp, s21_size_t size, char *sym);
static int getFlag(char *tmp, char *sym);
static void free_sp(specs_st *sp);
static int CheckSrc(char *src);

int s21_sprintf(char *src, const char *format, ...) {
  int EXIT_CODE = SUCCESS;
  EXIT_CODE = CheckSrc(src);
  int NUM_OF_CHAR_PRINTED = 0;

  if (!EXIT_CODE) {
    int src_position = 0;

    specs_st sp = {0, 0, 0, -1, 0, 0};
    v_argument_uni value = {0};
    int i = 0;

    va_list ap;
    va_start(ap, format);

    char edit_format[512] = "\0";
    s21_memcpy(edit_format, format, s21_strlen(format) + 1);
    for (i = 0; edit_format[i] != '\0'; i++) {
      if (edit_format[i] == '%') {
        if (edit_format[i + 1] == '%') {
          s21_strncat(src, "%", s21_strlen("%"));
          src_position += 1;
          continue;
        } else if (i != 0 && edit_format[i - 1] == '%') {
          continue;
        } else {
          EXIT_CODE = ParseSpecs(format + i, &sp, ap);
          if (EXIT_CODE) {
            NUM_OF_CHAR_PRINTED = (int)s21_strlen(src);
            break;
          }
          GetArg(&sp, ap, &value, src);
          i += (int)sp.sizeAfterPer + 1;

          free_sp(&sp);
        }
      }
      char *tmp = (char *)calloc(2, sizeof(char));
      cpychr(tmp, edit_format[i]);
      s21_strncat(src, tmp, 2);
      free(tmp);
    }
    if (NUM_OF_CHAR_PRINTED == 0) {
      NUM_OF_CHAR_PRINTED = (int)s21_strlen(src);
    }

    va_end(ap);
  }
  return NUM_OF_CHAR_PRINTED;
}

int ParseSpecs(const char *format, specs_st *sp, va_list ap) {
  int EXIT_CODE = SUCCESS;
  char *Specifiers = "cdieEfgGosuxXpn";

  char *all = "-+ #0987654321hlL.*";
  (void)format;
  (void)sp;
  char *tmp = (char *)calloc(256, sizeof(char));

  s21_size_t numOfChar = s21_strcspn(format, Specifiers);
  sp->specifier = format[numOfChar];

  for (int i = 1; i < (int)numOfChar; i++) {
    if (!s21_strchr(all, format[i])) {
      EXIT_CODE = FAIL_WRONG_PARAM;
      break;
    }
  }

  if (EXIT_CODE == SUCCESS) {
    sp->sizeAfterPer = numOfChar;
    s21_memcpy(tmp, format + 1, numOfChar);
    sp->width = GetWidth(tmp, ap);
    sp->accuracy = GetAccuracy(tmp, ap);
    EXIT_CODE = getLength(tmp, numOfChar, &sp->length);
    if (!EXIT_CODE) {
      EXIT_CODE = getFlag(tmp, &sp->flag);
    }
  }
  free(tmp);
  return EXIT_CODE;
}

static int getFlag(char *tmp, char *sym) {
  int EXIT_CODE = SUCCESS;
  char *flags = "-+ #0";
  char *flag_p = s21_strchr(flags, tmp[0]);
  if (tmp == s21_strpbrk(tmp, flags)) {
    *sym = *flag_p;
  }

  return EXIT_CODE;
}

static int getLength(char *tmp, s21_size_t size, char *ch) {
  int EXIT_CODE = SUCCESS;

  char *sym = "lLh";
  int sz = (int)size - 2;
  if (sz >= 0) {
    char *len_p = NULL;
    len_p = s21_strpbrk(tmp, sym);
    int len = s21_strcspn(tmp, sym);
    if (len >= 0 && len_p != NULL) {
      if (sz == len) {
        *ch = tmp[sz];
      } else {
        EXIT_CODE = FAIL_WRONG_LENGTH;
      }
    }
  }

  return EXIT_CODE;
}

static int GetAccuracy(char *tmp, va_list ap) {
  int accuracy = -1;
  int i = 0;
  for (; tmp[i] != '\0'; i++) {
    if (tmp[i] == '.') {
      if (tmp[i + 1] == '*') {
        accuracy = va_arg(ap, int);
      } else {
        tmp[i] = ' ';
        accuracy = GetWidth(tmp + i, ap);
        tmp[i] = '.';
      }
    }
  }

  return accuracy;
}

static int GetWidth(char *tmp, va_list ap) {
  int width = 0;
  int j = 0;
  char w[100] = "";
  int i = 0;
  for (; tmp[i] != '\0'; i++) {
    if (tmp[i] == '.') {
      break;
    }
    if (i == 0 && tmp[i] == '0') continue;
    if (((tmp[i] >= '0') && tmp[i] <= '9') || (tmp[i] == '*')) {
      w[j++] = tmp[i];
    }
  }
  w[j] = '\0';
  if (*w == '*') {
    width = va_arg(ap, int);
  } else if (s21_strlen(w) > 0) {
    width = s21_atoi(w);
  }

  return width;
}

static void cpychr(char *dest, char sym) {
  dest[0] = sym;
  dest[1] = '\0';
}

static void free_sp(specs_st *sp) {
  sp->accuracy = -1;
  sp->flag = 0;
  sp->length = 0;
  sp->sizeAfterPer = 0;
  sp->specifier = 0;
  sp->width = 0;
}

static int CheckSrc(char *src) {
  int EXIT_CODE = SUCCESS;
  if (src == NULL) {
    EXIT_CODE = EXIT_FAILURE;
  } else if (*src != '\0') {
    for (int i = 0; src[i] != '\0'; i++) {
      src[i] = '\0';
    }
  }
  return EXIT_CODE;
}