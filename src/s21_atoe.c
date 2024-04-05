#include "s21_string.h"

long double s21_atoe(char* string, int* valid) {
  int stringLength = s21_strlen(string);
  char goodString[256] = {0};
  int goodStringLength = 0;
  int good = 1;
  int i = 0;

  if (stringLength > 0 && string[0] == '-') {
    i++;
    goodString[goodStringLength++] = '-';
  } else if (stringLength > 0 && string[0] == '+') {
    i++;
    goodString[goodStringLength++] = '+';
  }

  for (; i < stringLength; i++) {
    if (s21_strchr(".0123456789eE", string[i]) && good) {
      goodString[goodStringLength++] = string[i];
    } else {
      good = 0;
    }
  }

  int fValid = 0;
  long double fResult = s21_atof(goodString, &fValid);
  string = string + fValid;
  if (string[0] == 'E' || string[0] == 'e') {
    int iValid = 0;
    long long iResult = s21_satoi(string + 1, 10, &iValid);
    *valid = fValid + iValid;
    fResult *= pow(10, iResult);
  } else
    *valid = fValid;

  return fResult;
}
