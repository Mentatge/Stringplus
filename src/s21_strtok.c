#include "s21_string.h"

static int IsDelim(char ch, const char *delim) {
  int isMatch = 0;
  for (int i = 0; delim[i] != '\0'; i++) {
    if (ch == delim[i] || delim[i] == '\0') {
      isMatch = 1;
      break;
    }
  }
  return isMatch;
}

static int CountNotDelim(char *src, const char *delim) {
  int count = 0;
  while (IsDelim(src[count], delim) == 0 && src[count] != '\0') {
    count += 1;
  }
  return count;
}

char *s21_strtok(char *src, const char *delim) {
  static char *end = NULL;
  int isMatch = 0;
  int numsOfCharInToken = 0;
  char *token = src;
  int sdvig = 0, onlyDelims = 1;
  if (src == NULL && end == NULL) {
    token = NULL;
  }
  if (src != NULL) {
    for (int i = 0; src[i] != '\0'; i++) {
      isMatch = IsDelim(src[i], delim);
      if (isMatch) {
        token += 1;
        continue;
      } else {
        numsOfCharInToken = CountNotDelim(token, delim);
        end = token + numsOfCharInToken;
        onlyDelims = 0;
        break;
      }
    }
  }
  if (src == NULL && end != NULL) {
    end += 1;
    token = end;
    for (int i = 0; token[i] != '\0'; i++) {
      isMatch = IsDelim(token[i], delim);
      if (isMatch) {
        sdvig += 1;
        continue;
      } else {
        numsOfCharInToken = CountNotDelim(token + sdvig, delim);

        token += sdvig;
        end = token + numsOfCharInToken;
        onlyDelims = 0;
        break;
      }
    }
  }
  if (onlyDelims) {
    token = NULL;
  }
  if (end != NULL) {
    if (*end == '\0') {
      end = NULL;
    } else {
      *end = '\0';
    }
  }
  return token;
}