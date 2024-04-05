#include "s21_string.h"

long long s21_satoi(char* string, int base, int* valid) {
  long long result = 0;
  int sign = 1;
  int haveSign = 0;

  if (base >= 2 && base <= 36) {
    char goodString[256] = {0};
    int goodStringLength = 0;

    int stringLength = (int)s21_strlen(string);
    int i = 0;
    if (stringLength > 0 && string[0] == '-') {
      i++;
      sign = -1;
      haveSign = 1;
    } else if (stringLength > 0 && string[0] == '+') {
      haveSign = 1;
      i++;
    }

    char* upperString = s21_to_upper(string);
    char alphabet[38] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    alphabet[base] = '\0';
    int good = 1;
    for (; i < stringLength; i++) {
      if (s21_strchr(alphabet, upperString[i]) && good) {
        goodString[goodStringLength++] = upperString[i];
      } else {
        good = 0;
      }
    }

    free(upperString);
    *valid = goodStringLength + haveSign;

    if (*valid) {
      for (i = 0; i < goodStringLength; i++) {
        result += pow(base, goodStringLength - 1 - i) *
                  (goodString[i] <= '9' ? (goodString[i] - '0')
                                        : (goodString[i] - 'A' + 10));
      }
    }
  }

  return result * sign;
}