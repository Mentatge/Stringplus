#include <math.h>
#include <stdio.h>

#include "s21_string.h"

int s21_e(long double num, char *dest, long int accuracy, specs_st *sp) {
  int degree = 0;
  int neg_degree = 0;
  char str_degree[128] = "";
  long double copy = 0;
  int sign = 0;

  if (num < 0) {
    sign = 1;
    num = -num;
  }

  if (accuracy < 0) {
    accuracy = 6;
  }

  copy = num;

  while (copy >= 10) {
    copy = copy / 10;
    degree++;
  }
  while (copy < 1) {
    copy = copy * 10;
    neg_degree++;
  }
  if (copy < 1 && copy > 0) neg_degree++;

  copy = RoundDouble(copy, accuracy);
  long int numBeforePoint = (long)copy;
  double numAfterPoint = copy - numBeforePoint;
  int countFallingZeroes = 0;

  for (int i = 0; i < accuracy; i++) {
    numAfterPoint = numAfterPoint * 10;
    if (numAfterPoint < 1) {
      countFallingZeroes += 1;
    }
  }
  long int fr = (long int)round(numAfterPoint);
  if (fr < 0) {
    fr = -fr;
  }

  char strBeforePoint[128] = "";
  char strAfterPoint[128] = "";
  s21_itoa(numBeforePoint, strBeforePoint);

  for (int i = 0; i < countFallingZeroes; i++) {
    strAfterPoint[i] = '0';
  }
  if (fr != 0) {
    s21_itoa(fr, strAfterPoint + countFallingZeroes);
  }

  if (degree > 0) s21_itoa(degree, str_degree);
  if (neg_degree > 0) s21_itoa(neg_degree, str_degree);

  int i = 0;
  if (sign) {
    dest[i++] = '-';
  }
  for (int j = 0; strBeforePoint[j] != '\0'; j++) {
    dest[i++] = strBeforePoint[j];
  }
  if (sp->flag == '#' || accuracy > 0) dest[i++] = '.';

  if (numAfterPoint == 0.) {
    while (accuracy--) {
      dest[i++] = '0';
    }
  } else {
    for (int j = 0; strAfterPoint[j] != 0; j++) {
      dest[i++] = strAfterPoint[j];
    }
  }
  dest[i] = '\0';
  if (degree < 10 && neg_degree == 0 && degree != 0) {
    s21_strncat(dest, "e+0", 3);
    s21_strncat(dest, str_degree, s21_strlen(str_degree));
  }
  if (degree >= 10 && neg_degree == 0) {
    s21_strncat(dest, "e+", 2);
    s21_strncat(dest, str_degree, s21_strlen(str_degree));
  }
  if (neg_degree < 10 && neg_degree != 0 && degree == 0) {
    s21_strncat(dest, "e-0", 3);
    s21_strncat(dest, str_degree, s21_strlen(str_degree));
  }
  if (neg_degree >= 10 && degree == 0) {
    s21_strncat(dest, "e-", 2);
    s21_strncat(dest, str_degree, s21_strlen(str_degree));
  }
  if (neg_degree == 0 && degree == 0) {
    s21_strncat(dest, "e+00", 4);
  }

  int return_degree = 0;
  if (neg_degree > 0) {
    return_degree = -neg_degree;
  } else if (degree > 0) {
    return_degree = degree;
  }

  return return_degree;
}
