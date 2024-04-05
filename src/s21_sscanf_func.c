#include "s21_sscanf.h"
#include "s21_string.h"

void s21_strnul(char* string) {
  s21_size_t stringLength = s21_strlen(string);
  for (int i = 0; i < (int)stringLength; i++) {
    string[i] = '\0';
  }
}

char* s21_strcpy(char* dest, const char* src) {
  s21_size_t sizeSecond = s21_strlen(src);

  for (s21_size_t i = 0; i < sizeSecond; i++) {
    dest[i] = src[i];
  }

  return dest;
}

int s21_strcnt(char* string, char symbol) {
  int result = 0;

  for (int i = 0; i < (int)s21_strlen(string); i++) {
    result += string[i] == symbol;
  }

  return result;
}