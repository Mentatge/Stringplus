#include <math.h>
#include <stdio.h>

#include "s21_string.h"

double RoundDouble(long double num, int accuracy) {
  long double rounded;
  long double shift = pow(10, accuracy);
  rounded = shift * num;
  rounded = roundl(rounded);
  rounded = rounded * (pow(10, -accuracy));
  return rounded + pow(10, -accuracy - 1);
}

int s21_ftoa(long double num1, char *dest, long int accuracy, int sharpflag) {
  if (accuracy < 0) {
    accuracy = 6;
  }

  long double num;

  if (num1 != num1) {
    num = 0;
  } else {
    num = num1;
  }

  int sign = 0;

  if (num < 0) {
    num = -num;
    sign = 1;
  }

  num = RoundDouble(num, accuracy);
  long int numBeforePoint = (long)num;
  long double numAfterPoint = num - numBeforePoint;
  int countFallingZeroes = 0;

  for (int i = 0; i < accuracy; i++) {
    numAfterPoint = numAfterPoint * 10;
    if (numAfterPoint < 1) {
      countFallingZeroes += 1;
    }
  }

  numAfterPoint = roundl(numAfterPoint);
  long long int fr = (long long int)numAfterPoint;

  if (fr < 0) {
    fr = -fr;
  }

  char strBeforePoint[512] = "";
  char strAfterPoint[512] = "";
  s21_itoa(numBeforePoint, strBeforePoint);

  for (int i = 0; i < countFallingZeroes; i++) {
    strAfterPoint[i] = '0';
  }
  if (fr != 0) {
    s21_itoa(fr, strAfterPoint + countFallingZeroes);
  }

  int i = 0;
  if (sign) {
    dest[i++] = '-';
  }
  for (int j = 0; strBeforePoint[j] != '\0'; j++) {
    dest[i++] = strBeforePoint[j];
  }

  if (sharpflag == '#' || accuracy > 0) dest[i++] = '.';

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

  return 1;
}
