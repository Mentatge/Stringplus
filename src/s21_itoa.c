#include "s21_string.h"

static void reverse(char src[]) {
  int i, j;
  char tmp;

  for (i = 0, j = s21_strlen(src) - 1; i < j; i++, j--) {
    tmp = src[i];
    src[i] = src[j];
    src[j] = tmp;
  }
}
// convert int to string
void s21_itoa(long long int num, char src[]) {
  int i = 0;
  int sign = 0;
  if (num < 0) {
    sign = -1;
  } else {
    sign = 1;
  }

  if (sign < 0) {
    num = -num;
  }

  do {
    src[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);
  if (sign < 0) {
    src[i++] = '-';
  }
  src[i] = '\0';
  reverse(src);
}

void s21_itoa_unsigned(long unsigned int num, char src[]) {
  int i = 0;
  do {
    src[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);
  src[i] = '\0';
  reverse(src);
}