#include "s21_string.h"

long double s21_atof(char* string, int* valid) {
  char intNumber[128] = {0};
  char goodString[256] = {0};
  int goodStringLength = 0;
  int stringLength = (int)s21_strlen(string);
  int i = 0;

  if (stringLength > 0 && string[0] == '-') {
    i++;
    goodString[goodStringLength++] = '-';
  } else if (stringLength > 0 && string[0] == '+') {
    i++;
    goodString[goodStringLength++] = '+';
  }

  char* dotPointer = s21_strchr(string, '.');
  int dot = -1;

  if (dotPointer) dot = (int)(dotPointer - string);

  int good = 1;

  for (; i < stringLength; i++) {
    if (s21_strchr(".0123456789", string[i]) && good) {
      goodString[goodStringLength++] = string[i];
    } else {
      good = 0;
    }
  }

  *valid = s21_strcnt(goodString, '.') <= 1;

  if (*valid) *valid = goodStringLength;

  if (*valid) {
    int intNumberLength = 0;
    for (i = 0; i < goodStringLength; i++) {
      if (goodString[i] != '.') {
        intNumber[intNumberLength++] = goodString[i];
      }
    }
  }

  int atoiValid = 0;
  long long intResult = s21_satoi(intNumber, 10, &atoiValid);
  long double dotResult = 1;
  if (dot != -1) {
    dotResult = pow(10, (goodStringLength - 1) - dot);
  }
  return intResult / dotResult;
}