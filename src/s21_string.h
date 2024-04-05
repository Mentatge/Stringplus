#ifndef S21_STRING_H_
#define S21_STRING_H_
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_sscanf.h"

#define S21_NULL ((void *)0)

typedef long unsigned s21_size_t;

typedef union _argument_from_varg {
  long int num_i;
  long unsigned int num_ui;
  double num_f;
  long double num_lf;
  void *ptr;
  char *string;
  wchar_t *string_l;
  wchar_t wide_char;
} v_argument_uni;

typedef struct specs_st {
  char specifier;
  char flag;
  char length;
  int accuracy;
  int width;
  s21_size_t sizeAfterPer;
} specs_st;

#define SUCCESS 0
#define FAIL_NO_SPEC 1
#define FAIL_WRONG_FALG 2
#define FAIL_WRONG_LENGTH 3
#define FAIL_WRONG_PARAM 4

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);

int s21_atoi(char *src);
int s21_ftoa(long double num, char *dest, long int accuracy, int sharpflag);

int s21_sprintf(char *src, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);
int GetArg(specs_st *sp, va_list ap, v_argument_uni *value, char *src);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void s21_itoa_unsigned(long unsigned int num, char src[]);
void s21_itoa(long long int num, char src[]);
long double s21_atoe(char *string, int *valid);
long double s21_atof(char *string, int *valid);
long long s21_satoi(char *string, int base, int *valid);
double RoundDouble(long double num, int accuracy);

void s21_octal(long unsigned int base, char *src);
void s21_hex(long unsigned int base, char *src);
void s21_hex_big(long unsigned int base, char *src);
void s21_u(long unsigned int base, char *src, specs_st *sp);
void s21_p(long unsigned int *base, char *src);
int s21_e(long double num, char *dest, long int accuracy, specs_st *sp);
int s21_E(double num, char *dest, long int accuracy);
int s21_g(double num, char *dest, long int accuracy, specs_st *sp);
char *s21_flags(char *src, long int accuracy, specs_st *sp, char *tmp);

#endif
