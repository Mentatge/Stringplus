#ifndef UNIT_TESTS_FOR_STRING_
#define UNIT_TESTS_FOR_STRING_

#include <check.h>
#include <strings.h>

#include "s21_string.h"

char str1[25] = "1 Another stupid test 2\0";
char str2[25] = "1 Another stupid test 2\n\0";
char str3[25] = "1 Another stupid test 2\n\0";
char str4[10] = " \n\0 we";
char str5[10] = " \0\n\0";
char str6[10] = "\n\0";
char str7[10] = "\0";
char str8[10] = "a\n\0";

char sprintf_str1[500] = {'\0'};
char sprintf_str2[500] = {'\0'};

#endif