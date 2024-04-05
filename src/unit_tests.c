#include "unit_tests.h"

START_TEST(memchr_tests) {
  ck_assert_str_eq(s21_memchr(str1, 'i', 25), memchr(str1, 'i', 25));
}
END_TEST

START_TEST(memchr_tests2) { ck_assert_ptr_null(s21_memchr(str1, '7', 25)); }
END_TEST

START_TEST(memchr_tests3) {
  ck_assert_str_eq(s21_memchr(str1, '\0', 25), memchr(str1, '\0', 25));
}
END_TEST

START_TEST(memchr_tests4) {
  ck_assert_str_eq(s21_memchr(str4, '\0', 3), memchr(str4, '\0', 3));
}
END_TEST

START_TEST(memchr_tests5) {
  ck_assert_str_eq(s21_memchr(str4, '\n', 3), memchr(str4, '\n', 3));
}
END_TEST

// int s21_memcmp(const void *str1, const void *str2, size_t n);

START_TEST(memcmp_tests) {
  ck_assert_int_eq(s21_memcmp(str3, str2, 25), memcmp(str3, str2, 25));
}
END_TEST

START_TEST(memcmp_tests2) {
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
}
END_TEST

START_TEST(memcmp_tests3) {
  ck_assert_int_eq(s21_memcmp(str3, str1, 25), memcmp(str3, str1, 25));
}
END_TEST

START_TEST(memcmp_tests4) {
  ck_assert_int_eq(s21_memcmp(str1, str2, 25), memcmp(str1, str2, 25));
}
END_TEST

START_TEST(memcmp_tests5) {
  ck_assert_int_eq(s21_memcmp(str5, str4, 3), memcmp(str5, str4, 3));
}
END_TEST

// void *s21_memcpy(void *dest, const void *src, size_t n);

START_TEST(memcpy_tests) {
  char dst[30] = {'\0'};
  ck_assert_str_eq(s21_memcpy(dst, str1, 3), memcpy(dst, str1, 3));
}
END_TEST

START_TEST(memcpy_tests2) {
  char dst[30] = {'\0'};
  ck_assert_str_eq(s21_memcpy(dst, str1, 25), memcpy(dst, str1, 25));
}
END_TEST

START_TEST(memcpy_tests3) {
  char dst[30] = {'\0'};
  ck_assert_str_eq(s21_memcpy(dst, str3, 3), memcpy(dst, str3, 3));
}
END_TEST

START_TEST(memcpy_tests4) {
  char dst[30] = {'\0'};
  ck_assert_str_eq(s21_memcpy(dst, str4, 3), memcpy(dst, str4, 3));
}
END_TEST

START_TEST(memcpy_tests5) {
  char dst[30] = {'\0'};
  ck_assert_str_eq(s21_memcpy(dst, str1, 3), memcpy(dst, str1, 3));
  ck_assert_str_eq(s21_memcpy(dst, str4, 3), memcpy(dst, str4, 3));
}
END_TEST

// void *s21_memset(void *str, int c, s21_size_t n);

START_TEST(memset_tests) {
  ck_assert_str_eq(s21_memset(str1, '1', 3), memset(str1, '1', 3));
}
END_TEST

START_TEST(memset_tests2) {
  ck_assert_str_eq(s21_memset(str1, '1', 1), memset(str1, '1', 1));
}
END_TEST

START_TEST(memset_tests3) {
  ck_assert_str_eq(s21_memset(str3, '1', 13), memset(str3, '1', 13));
}
END_TEST

START_TEST(memset_tests4) {
  ck_assert_str_eq(s21_memset(str7, '1', 9), memset(str7, '1', 9));
}
END_TEST

START_TEST(memset_tests5) {
  ck_assert_str_eq(s21_memset(str8, '\0', 1), memset(str8, '\0', 1));
}
END_TEST

// char *s21_strncat(char *dest, const char *src, size_t n);

START_TEST(strncat_tests) {
  ck_assert_str_eq(s21_strncat(str7, str2, 3), strncat(str7, str2, 3));
}
END_TEST

START_TEST(strncat_tests2) {
  ck_assert_str_eq(s21_strncat(str1, str2, 0), strncat(str1, str2, 0));
}
END_TEST

START_TEST(strncat_tests3) {
  ck_assert_str_eq(s21_strncat(str8, str1, 1), strncat(str8, str1, 1));
}
END_TEST

START_TEST(strncat_tests4) { ck_assert_str_eq(s21_strncat(str7, str7, 1), ""); }
END_TEST

START_TEST(strncat_tests5) {
  ck_assert_str_eq(s21_strncat(str7, str4, 3), strncat(str7, str4, 3));
}
END_TEST

// char *s21_strchr(const char *str, int c);

START_TEST(strchr_tests) {
  ck_assert_str_eq(s21_strchr(str1, 'i'), strchr(str1, 'i'));
}
END_TEST

START_TEST(strchr_tests2) {
  ck_assert_str_eq(s21_strchr(str4, '\0'), strchr(str4, '\0'));
}
END_TEST

START_TEST(strchr_tests3) {
  ck_assert_str_eq(s21_strchr(str3, '\0'), strchr(str3, '\0'));
}
END_TEST

START_TEST(strchr_tests4) {
  ck_assert_str_eq(s21_strchr(str7, '\0'), strchr(str7, '\0'));
}
END_TEST

START_TEST(strchr_tests5) {
  ck_assert_str_eq(s21_strchr(str8, '\n'), strchr(str8, '\n'));
}
END_TEST

// int s21_strncmp(const char *str1, const char *str2, size_t n);

START_TEST(strncmp_tests) {
  const char str1[50] = "123456789";
  const char str2[50] = "123498765";
  ck_assert_int_eq(s21_strncmp(str1, str2, 15), strncmp(str1, str2, 15));
}
END_TEST

START_TEST(strncmp_tests2) {
  const char str1[50] = "123456789";
  const char str2[50] = "123428765";
  ck_assert_int_eq(s21_strncmp(str1, str2, 15), strncmp(str1, str2, 15));
}
END_TEST

START_TEST(strncmp_tests3) {
  const char str1[50] = "123456789";
  const char str2[50] = "123456789";
  ck_assert_int_eq(s21_strncmp(str1, str2, 15), strncmp(str1, str2, 15));
}
END_TEST

START_TEST(strncmp_tests4) {
  const char str1[50] = "QWER\0tyuiop";
  const char str2[50] = "QWER\0Tyuiop";
  ck_assert_int_eq(s21_strncmp(str1, str2, 15), strncmp(str1, str2, 15));
  ck_assert_int_eq(s21_strncmp(str1, str1, 15), strncmp(str1, str1, 15));
}
END_TEST

START_TEST(strncmp_tests5) {
  const char str1[50] = "QWER\0tyuiop";
  ck_assert_int_eq(s21_strncmp(str1, str1, 15), strncmp(str1, str1, 15));
}
END_TEST

// char *s21_strncpy(char *dest, const char *src, size_t n);

START_TEST(strncpy_tests) {
  ck_assert_str_eq(s21_strncpy(str1, str5, 3), strncpy(str1, str5, 3));
}
END_TEST

START_TEST(strncpy_tests2) {
  ck_assert_str_eq(s21_strncpy(str5, str8, 3), strncpy(str5, str8, 3));
}
END_TEST

START_TEST(strncpy_tests3) {
  ck_assert_str_eq(s21_strncpy(str7, str1, 3), strncpy(str7, str1, 3));
}
END_TEST

START_TEST(strncpy_tests4) {
  ck_assert_str_eq(s21_strncpy(str2, str7, 3), strncpy(str2, str7, 3));
}
END_TEST

START_TEST(strncpy_tests5) {
  char *dst = S21_NULL;
  ck_assert_ptr_null(s21_strncpy(dst, str7, 1));
}
END_TEST

// size_t s21_strcspn(const char *str1, const char *str2);

START_TEST(strcspn_tests) {
  ck_assert_int_eq(s21_strcspn("qwerty", "yes"), strcspn("qwerty", "yes"));
}
END_TEST

START_TEST(strcspn_tests2) {
  ck_assert_int_eq(s21_strcspn("123456", "yes"), strcspn("123456", "yes"));
}
END_TEST

START_TEST(strcspn_tests3) {
  ck_assert_int_eq(s21_strcspn("qwerty1234", "456"),
                   strcspn("qwerty1234", "456"));
}
END_TEST

START_TEST(strcspn_tests4) {
  ck_assert_int_eq(s21_strcspn("!@#$^&&", "&^"), strcspn("!@#$^&&", "&^"));
}
END_TEST

// char *s21_strerror(int errnum);

START_TEST(strerror_tests) {
#ifdef __APPLE__
#define SIZE_ARR_ERR 106
#endif
#ifdef __linux__
#define SIZE_ARR_ERR 133
#endif
  for (int i = 0; i <= SIZE_ARR_ERR; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(200), strerror(200));
}
END_TEST

// size_t s21_strlen(const char *str);

START_TEST(strlen_tests) { ck_assert_int_eq(s21_strlen(str1), strlen(str1)); }
END_TEST

START_TEST(strlen_tests2) { ck_assert_int_eq(s21_strlen(str2), strlen(str2)); }
END_TEST

START_TEST(strlen_tests3) { ck_assert_int_eq(s21_strlen(str6), strlen(str6)); }
END_TEST

START_TEST(strlen_tests4) { ck_assert_int_eq(s21_strlen(str7), strlen(str7)); }
END_TEST

START_TEST(strlen_tests5) { ck_assert_int_eq(s21_strlen(str8), strlen(str8)); }
END_TEST

// char *s21_strpbrk(const char *str1, const char *str2);

START_TEST(strpbrk_tests) {
  const char str1[14] = "Test4Strings.";
  const char str2[14] = "!@#$^&";
  ck_assert_ptr_null(s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_tests2) {
  const char str1[14] = "Test4Strings.";
  const char str2[14] = "str";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// char *s21_strrchr(const char *str, int c);

START_TEST(strrchr_tests) {
  const char str1[14] = "Test4Strings.";
  ck_assert_str_eq(s21_strrchr(str1, 's'), strrchr(str1, 's'));
  ck_assert_ptr_null(s21_strrchr(str1, '#'));
}
END_TEST

// char *s21_strstr(const char *haystack, const char *needle);

START_TEST(strstr_tests) {
  // char test8[10] = "\0";
  // char sym2[10] = "";

  char test9[10] = "ello\0";
  char sym3[10] = "elk\0";

  char test11[10] = "ello\0";
  char sym5[10] = "elloz\0";

  char test12[10] = "ello\0";
  char sym6[10] = "ll\0";

  // ck_assert_ptr_eq(s21_strstr(test8, sym2), strstr(test8, sym2));
  ck_assert_ptr_eq(s21_strstr(test9, sym3), strstr(test9, sym3));
  ck_assert_ptr_eq(s21_strstr(test11, sym5), strstr(test11, sym5));
  ck_assert_ptr_eq(s21_strstr(test12, sym6), strstr(test12, sym6));
}
END_TEST

START_TEST(strstr_tests2) { ck_assert_ptr_null(strstr(str1, "'")); }
END_TEST

// char *s21_strtok(char *str, const char *delim);

// void *s21_to_upper(const char *str);

START_TEST(to_upper_tests) {
  char strtst[14] = "Test4Strings.";
  ck_assert_str_eq(s21_to_upper(strtst), "TEST4STRINGS.");
}
END_TEST

START_TEST(to_upper_tests2) {
  char strtst[14] = "!@#$^&*()\n";
  ck_assert_str_eq(s21_to_upper(strtst), strtst);
}
END_TEST

START_TEST(to_upper_tests3) {
  char strtst[14] = "12345\n";
  ck_assert_str_eq(s21_to_upper(strtst), strtst);
}
END_TEST

START_TEST(to_upper_tests4) { ck_assert_str_eq(s21_to_upper(str7), str7); }
END_TEST

START_TEST(to_upper_tests5) { ck_assert_str_eq(s21_to_upper(str4), str4); }
END_TEST

// void *s21_to_lower(const char *str);

START_TEST(to_lower_tests) { ck_assert_str_eq(s21_to_lower(str7), str7); }
END_TEST

START_TEST(to_lower_tests2) { ck_assert_str_eq(s21_to_lower(str4), str4); }
END_TEST

START_TEST(to_lower_tests3) {
  char strtst[14] = "123456";
  ck_assert_str_eq(s21_to_lower(strtst), "123456");
}
END_TEST

START_TEST(to_lower_tests4) {
  char strtst[14] = "Test4Strings.";
  ck_assert_str_eq(s21_to_lower(strtst), "test4strings.");
}
END_TEST

START_TEST(to_lower_tests5) {
  char strtst[14] = "Test4Strings.";
  ck_assert_str_eq(s21_to_lower(strtst), "test4strings.");
}
END_TEST

START_TEST(strtok_tests) {
  char src[256] = " this is what we..call  testics\0";

  ck_assert_str_eq(s21_strtok(src, " ."), "this");
  ck_assert_str_eq(s21_strtok(NULL, " ."), "is");
  ck_assert_str_eq(s21_strtok(NULL, " ."), "what");
  ck_assert_str_eq(s21_strtok(NULL, " ."), "we");
  ck_assert_str_eq(s21_strtok(NULL, " ."), "call");
  ck_assert_str_eq(s21_strtok(NULL, " ."), "testics");
  ck_assert_ptr_null(s21_strtok(NULL, " ."));
}
END_TEST

// void *insert(const char *src, const char *str, size_t start_index);

START_TEST(trim_tests) {
  char str_trim1[30] = "-?Abrakadabra!";
  char str_trim3[] = "!?-";
  char str_trim4[] = "Abrakadabra";
  char *str_trim2 = s21_trim(str_trim1, str_trim3);
  ck_assert_pstr_eq(str_trim4, str_trim2);
  if (str_trim2) free(str_trim2);
}
END_TEST

START_TEST(trim_tests2) {
  char str_trim1[30] = "";
  char str_trim3[] = "";
  char *str_trim4 = "";
  char *str_trim2 = s21_trim(str_trim1, str_trim3);
  ck_assert_pstr_eq(str_trim4, str_trim2);
  if (str_trim2) free(str_trim2);
}
END_TEST

START_TEST(trim_tests3) {
  char *str_trim1 = S21_NULL;
  char str_trim3[] = "";
  char *str_trim4 = S21_NULL;
  char *str_trim2 = s21_trim(str_trim1, str_trim3);
  ck_assert_pstr_eq(str_trim4, str_trim2);
  if (str_trim2) free(str_trim2);
}
END_TEST

START_TEST(trim_tests4) {
  char str_trim1[30] = "!!!abcdefghij!?!";
  char str_trim3[] = "!";
  char str_trim4[] = "abcdefghij!?";
  char *str_trim2 = s21_trim(str_trim1, str_trim3);
  ck_assert_pstr_eq(str_trim4, str_trim2);
  if (str_trim2) free(str_trim2);
}
END_TEST

START_TEST(sprintf_tests) {
  char *format = "QWERTY %d";
  int d = 7;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));  // 9
  ck_assert_str_eq(sprintf_str1, sprintf_str2);        // QWERTY 8
}
END_TEST

START_TEST(sprintf_tests2) {
  char *format = "%d QWERTY";
  int d = 10;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));  // 8
  ck_assert_str_eq(sprintf_str1, sprintf_str2);        // 8 QWERTY
}
END_TEST

START_TEST(sprintf_tests3) {
  char *format = "QWE%dRTY";
  int d = 345;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));  // 7
  ck_assert_str_eq(sprintf_str1, sprintf_str2);        // QWE7RTY
}
END_TEST

START_TEST(sprintf_tests4) {
  char *format = "QWE%dRTY %d";
  int d = 96;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d),
                   sprintf(sprintf_str2, format, d, d));  // 9
  ck_assert_str_eq(sprintf_str1, sprintf_str2);           // QWE7RTY 7
}
END_TEST

START_TEST(sprintf_tests5) {
  char *format = "%d QWE%dRTY";
  int d = 234;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d),
                   sprintf(sprintf_str2, format, d, d));  // 9
  ck_assert_str_eq(sprintf_str1, sprintf_str2);           // 7 QWE7RTY
}
END_TEST

START_TEST(sprintf_tests6) {
  char *format = "%.7i";
  int d = 543;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests7) {
  char *format = "%.7i %.3i";
  int d = 23;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d),
                   sprintf(sprintf_str2, format, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests8) {
  char *format = "%.7i %d %.3i";
  int d = 54;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d, d),
                   sprintf(sprintf_str2, format, d, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests9) {
  char *format = "%7d";
  int d = 41234;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests10) {
  char *format = "%7d %d";
  int d = 42311;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d),
                   sprintf(sprintf_str2, format, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests11) {
  char *format = "%% %7d %d %.3i";
  int d = 4321234;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d, d),
                   sprintf(sprintf_str2, format, d, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests12) {
  char *format = "%7d %i %.0i";
  int d = 4;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, d, d),
                   sprintf(sprintf_str2, format, d, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests13) {
  char *format = "%7d %d %0.i";
  int d = 57454;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, d, d),
                   sprintf(sprintf_str2, format, d, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests14) {
  char *format = "%0.*i";
  int d = 57478645;
  ck_assert_int_eq(sprintf(sprintf_str1, format, 53, d),
                   sprintf(sprintf_str2, format, 53, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests15) {
  char *format = "%d %4d %.3i";
  int d = 52573467;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, 34, 23),
                   sprintf(sprintf_str2, format, d, 34, 23));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests16) {
  char *format = "%d %0*d %06i";
  int d = 54677644;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, 4, 432, 11),
                   sprintf(sprintf_str2, format, d, 4, 432, 11));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests17) {
  char *format = "%0.*ld";
  long int d = 938954677644;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 2, d),
                   sprintf(sprintf_str2, format, 2, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests18) {
  char *format = "%4.20li";
  long int d = 8923432954677644;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests19) {
  char *format = "%.0li";
  long int d = 203920454677644;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests20) {
  char *format = "% d";
  int d = 893;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

// float

START_TEST(sprintf_tests21) {
  char *format = "%Lf";
  long double d = 83.323123123131231;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests22) {
  char *format = "%10Lf";
  long double d = 893.2333312231231;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests23) {
  char *format = "%.3Lf";
  long double d = 893.234543;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests24) {
  char *format = "%0.Lf";
  long double d = 893.21312312312312312;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests25) {
  char *format = "% f";
  long double d = 893.4342342;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests26) {
  char *format = "%Le";
  long double d = 893.4342342;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests27) {
  char *format = "%.3Le";
  long double d = 893.4342342;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests28) {
  char *format = "%.Le";
  long double d = -43234124111.42342;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests29) {
  char *format = "%12e %e";
  double d = 0.04342342;
  double e = 0.000000000432;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, e),
                   sprintf(sprintf_str2, format, d, e));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests30) {
  char *format = "%.6E %.6E %.6E";
  double d = -12.001;
  double e = 0.00012;
  double b = 124341234324;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, e, b),
                   sprintf(sprintf_str2, format, d, e, b));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests31) {
  char *format = "%02E";
  double d = 0.00000000004342;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests32) {
  char *format = "%10E";
  double d = 893.4342342;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests33) {
  char *format = "%10LE %d";
  long double d = 893.4342342;
  int a = 3131;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, a),
                   sprintf(sprintf_str2, format, d, a));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests34) {
  char *format = "%s %d %-12Lf";
  long double d = -893.4342342;
  int a = 3131;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, "dewdwd", a, d),
                   sprintf(sprintf_str2, format, "dewdwd", a, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests35) {
  char *format = "%s %s %s";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, "dewdwd", "a", "d"),
                   sprintf(sprintf_str2, format, "dewdwd", "a", "d"));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests36) {
  char *format = "%u %d %s";
  int res = sprintf(sprintf_str2, format, (unsigned)43242, 234242, "d");
  ck_assert_int_eq(
      s21_sprintf(sprintf_str1, format, (unsigned)43242, 234242, "d"), res);
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests37) {
  char *format = "%10lu %d %s";
  ck_assert_int_eq(
      s21_sprintf(sprintf_str1, format, (long unsigned)43242, -234242, "d"),
      sprintf(sprintf_str2, format, (unsigned)43242, -234242, "d"));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests38) {
  char *format = "%c %c %c";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, '1', 'D', '\n'),
                   sprintf(sprintf_str2, format, '1', 'D', '\n'));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests39) {
  char *format = "%d %c %s";
  ck_assert_int_eq(
      s21_sprintf(sprintf_str1, format, 132423, 'D', "feferferferf"),
      sprintf(sprintf_str2, format, 132423, 'D', "feferferferf"));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests40) {
  char *format = "%x %x %s";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 0, "feferferferf"),
                   sprintf(sprintf_str2, format, 132423, 0, "feferferferf"));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests41) {
  char *format = "%X %X %s";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 0, "feferferferf"),
                   sprintf(sprintf_str2, format, 132423, 0, "feferferferf"));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests42) {
  char *format = "%X %d %s % Lf";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 0, "feferferferf",
                               (long double)25.543234523543),
                   sprintf(sprintf_str2, format, 132423, 0, "feferferferf",
                           (long double)25.543234523543));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests43) {
  char *format = "%X %d %s %+Lf";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 0, "feferferferf",
                               (long double)25.543234523543),
                   sprintf(sprintf_str2, format, 132423, 0, "feferferferf",
                           (long double)25.543234523543));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests44) {
  char *format = "%*x";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 12, 13213),
                   sprintf(sprintf_str2, format, 12, 13213));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests45) {
  char *format = "%*X";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 13, 122423),
                   sprintf(sprintf_str2, format, 13, 122423));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests46) {
  char *format = "%.20X";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 3112310),
                   sprintf(sprintf_str2, format, 132423, 3112310));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests47) {
  char *format = "%.20x";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 3112310),
                   sprintf(sprintf_str2, format, 132423, 3112310));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests48) {
  char *format = "%#.1X";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 3112310),
                   sprintf(sprintf_str2, format, 132423, 3112310));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}

END_TEST

START_TEST(sprintf_tests49) {
  char *format = "%#.1x";
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, 132423, 3112310),
                   sprintf(sprintf_str2, format, 132423, 3112310));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests50) {
  char *format = "%.7i %d %.3i";
  int d = 54;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, d, d),
                   sprintf(sprintf_str2, format, d, d, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests51) {
  char *format = "%#o 123%n";
  int d = 54;
  int a = 21312;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d, &a),
                   sprintf(sprintf_str2, format, d, &a));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests52) {
  char *format = "%n";
  int a = 21312;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, &a),
                   sprintf(sprintf_str2, format, &a));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests53) {
  char *format = "%o";
  int d = 21312;
  ck_assert_int_eq(s21_sprintf(sprintf_str1, format, d),
                   sprintf(sprintf_str2, format, d));
  ck_assert_str_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests54) {
  char *format = "%Lg %2g %.g %5.g %3.2g";
  double d = 54.523445;
  ck_assert_int_eq(
      sprintf(sprintf_str1, format, (long double)d, d, d, d, d),
      s21_sprintf(sprintf_str2, format, (long double)d, d, d, d, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests55) {
  char *format = "erqr %.g %5.LGrqrq %3.10g";
  double d = 48.524325;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, (long double)d, d),
                   s21_sprintf(sprintf_str2, format, d, (long double)d, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests56) {
  char *format = "%G %2g12345 %3.10g";
  double d = 93.7543523;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, d, d),
                   s21_sprintf(sprintf_str2, format, d, d, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests57) {
  char *format = "%lo %ho";
  int d = 93563;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, (short int)d),
                   s21_sprintf(sprintf_str2, format, d, (short int)d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests58) {
  char *format = "%10o";
  int d = 23423234;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d),
                   s21_sprintf(sprintf_str2, format, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests59) {
  char *format = "%3.3o %.3o %3.o %.o";
  int d = 32423423;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, d, d, d),
                   s21_sprintf(sprintf_str2, format, d, d, d, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests60) {
  char *format = "%-3.3o %-.3o %-3.o %-.o";
  int d = 4342323;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d, d, d, d),
                   s21_sprintf(sprintf_str2, format, d, d, d, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

START_TEST(sprintf_tests61) {
  char *format = "%12p";
  int d = 434232;
  ck_assert_int_eq(sprintf(sprintf_str1, format, d),
                   s21_sprintf(sprintf_str2, format, d));
  ck_assert_pstr_eq(sprintf_str1, sprintf_str2);
}
END_TEST

// sscanf

START_TEST(sscanf_tests) {
  char *format = "%d";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("123", format, &a), s21_sscanf("123", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests2) {
  char *format = "%d %d";
  int d = 0;
  int e = 0;
  int a = 0;
  int b = 0;
  ck_assert_int_eq(sscanf("12 3", format, &a, &b),
                   s21_sscanf("12 3", format, &d, &e));
  ck_assert_int_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests3) {
  char *format = "%d %c";
  int d = 0;
  char e = 0;
  int a = 0;
  char b = 0;
  ck_assert_int_eq(sscanf("12 3", format, &a, &b),
                   s21_sscanf("12 3", format, &d, &e));
  ck_assert_int_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests4) {
  char *format = "%o";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("73568261", format, &a),
                   s21_sscanf("73568261", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests7) {
  char *format = "%x";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("735682AB", format, &a),
                   s21_sscanf("735682AB", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests8) {
  char *format = "%hx %d";
  short int d = 0;
  int e = 0;
  short int a = 0;
  int b = 0;
  ck_assert_int_eq(sscanf("735682AB 1", format, &a, &b),
                   s21_sscanf("735682AB 1", format, &d, &e));
  ck_assert_int_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests9) {
  char *format = "%+f";
  double d = 0;
  double a = 0;
  ck_assert_int_eq(sscanf("735682.234", format, &a),
                   s21_sscanf("735682.234", format, &d));
  ck_assert_float_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests10) {
  char *format = "%Lf";
  long double d = 0;
  long double a = 0;
  ck_assert_int_eq(sscanf("-735682.234", format, &a),
                   s21_sscanf("-735682.234", format, &d));
  ck_assert_double_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests11) {
  char *format = "%ld";
  long int d = 0;
  long int a = 0;
  ck_assert_int_eq(sscanf("735682", format, &a),
                   s21_sscanf("735682", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests12) {
  char *format = "%*d %d";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("73568 -2", format, &a),
                   s21_sscanf("73568 -2", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests13) {
  char *format = "%d %n";
  int d = 0;
  int e = 0;
  int a = 0;
  int b = 0;
  ck_assert_int_eq(sscanf("73 568", format, &a, &b),
                   s21_sscanf("73 568", format, &d, &e));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests15) {
  char *format = "%2i";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("735682AB", format, &a),
                   s21_sscanf("735682AB", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests16) {
  char *format = "%s";
  char d[50] = {'\0'};
  char a[50] = {'\0'};
  ck_assert_int_eq(sscanf("i love codding", format, &a),
                   s21_sscanf("i love codding", format, &d));
  ck_assert_str_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests17) {
  char *format = "%s %d";
  char d[50] = {'\0'};
  int e = 0;
  char a[50] = {'\0'};
  int b = 0;
  ck_assert_int_eq(sscanf("i love codding 5", format, &a, &b),
                   s21_sscanf("i love codding 5", format, &d, &e));
  ck_assert_str_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests18) {
  char *format = "%s %d";
  char d[50] = {'\0'};
  int e = 0;
  char a[50] = {'\0'};
  int b = 0;
  ck_assert_int_eq(sscanf("i love codding -5", format, &a, &b),
                   s21_sscanf("i love -5", format, &d, &e));
  ck_assert_str_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests19) {
  char *format = "%e";
  float d = 0;
  float a = 0;
  ck_assert_int_eq(sscanf("-735682.12345e-02", format, &a),
                   s21_sscanf("-735682.12345e-02", format, &d));
  ck_assert_float_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests21) {
  char *format = "%g";
  float d = 0;
  float a = 0;
  ck_assert_int_eq(sscanf("735682.123456789", format, &a),
                   s21_sscanf("735682.123456789", format, &d));
  ck_assert_float_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests23) {
  char *format = "%u";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("735682", format, &a),
                   s21_sscanf("735682", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

Suite *example_suite_create(void) {
  Suite *suite = suite_create("string_tests");

  TCase *tcase_core = tcase_create("S21_STINGS");
  tcase_add_test(tcase_core, memchr_tests);
  tcase_add_test(tcase_core, memchr_tests2);
  tcase_add_test(tcase_core, memchr_tests3);
  tcase_add_test(tcase_core, memchr_tests4);
  tcase_add_test(tcase_core, memchr_tests5);

  tcase_add_test(tcase_core, memcmp_tests);
  tcase_add_test(tcase_core, memcmp_tests2);
  tcase_add_test(tcase_core, memcmp_tests3);
  tcase_add_test(tcase_core, memcmp_tests4);
  tcase_add_test(tcase_core, memcmp_tests5);

  tcase_add_test(tcase_core, memcpy_tests);
  tcase_add_test(tcase_core, memcpy_tests2);
  tcase_add_test(tcase_core, memcpy_tests3);
  tcase_add_test(tcase_core, memcpy_tests4);
  tcase_add_test(tcase_core, memcpy_tests5);

  tcase_add_test(tcase_core, memset_tests);
  tcase_add_test(tcase_core, memset_tests2);
  tcase_add_test(tcase_core, memset_tests3);
  tcase_add_test(tcase_core, memset_tests4);
  tcase_add_test(tcase_core, memset_tests5);

  tcase_add_test(tcase_core, strncat_tests);
  tcase_add_test(tcase_core, strncat_tests2);
  tcase_add_test(tcase_core, strncat_tests3);
  tcase_add_test(tcase_core, strncat_tests4);
  tcase_add_test(tcase_core, strncat_tests5);

  tcase_add_test(tcase_core, strchr_tests);
  tcase_add_test(tcase_core, strchr_tests2);
  tcase_add_test(tcase_core, strchr_tests3);
  tcase_add_test(tcase_core, strchr_tests4);
  tcase_add_test(tcase_core, strchr_tests5);

  tcase_add_test(tcase_core, strncmp_tests);
  tcase_add_test(tcase_core, strncmp_tests2);
  tcase_add_test(tcase_core, strncmp_tests3);
  tcase_add_test(tcase_core, strncmp_tests4);
  tcase_add_test(tcase_core, strncmp_tests5);

  tcase_add_test(tcase_core, strncpy_tests);
  tcase_add_test(tcase_core, strncpy_tests2);
  tcase_add_test(tcase_core, strncpy_tests3);
  tcase_add_test(tcase_core, strncpy_tests4);
  tcase_add_test(tcase_core, strncpy_tests5);

  tcase_add_test(tcase_core, strcspn_tests);
  tcase_add_test(tcase_core, strcspn_tests2);
  tcase_add_test(tcase_core, strcspn_tests3);
  tcase_add_test(tcase_core, strcspn_tests4);

  tcase_add_test(tcase_core, strerror_tests);

  tcase_add_test(tcase_core, strlen_tests);
  tcase_add_test(tcase_core, strlen_tests2);
  tcase_add_test(tcase_core, strlen_tests3);
  tcase_add_test(tcase_core, strlen_tests4);
  tcase_add_test(tcase_core, strlen_tests5);

  tcase_add_test(tcase_core, strpbrk_tests);
  tcase_add_test(tcase_core, strpbrk_tests2);

  tcase_add_test(tcase_core, strrchr_tests);

  tcase_add_test(tcase_core, strstr_tests);
  tcase_add_test(tcase_core, strstr_tests2);

  tcase_add_test(tcase_core, to_upper_tests);
  tcase_add_test(tcase_core, to_upper_tests2);
  tcase_add_test(tcase_core, to_upper_tests3);
  tcase_add_test(tcase_core, to_upper_tests4);
  tcase_add_test(tcase_core, to_upper_tests5);

  tcase_add_test(tcase_core, to_lower_tests);
  tcase_add_test(tcase_core, to_lower_tests2);
  tcase_add_test(tcase_core, to_lower_tests3);
  tcase_add_test(tcase_core, to_lower_tests4);
  tcase_add_test(tcase_core, to_lower_tests5);

  tcase_add_test(tcase_core, trim_tests);
  tcase_add_test(tcase_core, trim_tests2);
  tcase_add_test(tcase_core, trim_tests3);
  tcase_add_test(tcase_core, trim_tests4);

  tcase_add_test(tcase_core, strtok_tests);

  tcase_add_test(tcase_core, sprintf_tests);
  tcase_add_test(tcase_core, sprintf_tests2);
  tcase_add_test(tcase_core, sprintf_tests3);
  tcase_add_test(tcase_core, sprintf_tests4);
  tcase_add_test(tcase_core, sprintf_tests5);
  tcase_add_test(tcase_core, sprintf_tests6);
  tcase_add_test(tcase_core, sprintf_tests7);
  tcase_add_test(tcase_core, sprintf_tests8);
  tcase_add_test(tcase_core, sprintf_tests9);
  tcase_add_test(tcase_core, sprintf_tests10);
  tcase_add_test(tcase_core, sprintf_tests11);
  tcase_add_test(tcase_core, sprintf_tests12);
  tcase_add_test(tcase_core, sprintf_tests13);
  tcase_add_test(tcase_core, sprintf_tests14);
  tcase_add_test(tcase_core, sprintf_tests15);
  tcase_add_test(tcase_core, sprintf_tests16);
  tcase_add_test(tcase_core, sprintf_tests17);
  tcase_add_test(tcase_core, sprintf_tests18);
  tcase_add_test(tcase_core, sprintf_tests19);
  tcase_add_test(tcase_core, sprintf_tests20);
  tcase_add_test(tcase_core, sprintf_tests21);
  tcase_add_test(tcase_core, sprintf_tests22);
  tcase_add_test(tcase_core, sprintf_tests23);
  tcase_add_test(tcase_core, sprintf_tests24);
  tcase_add_test(tcase_core, sprintf_tests25);
  tcase_add_test(tcase_core, sprintf_tests26);
  tcase_add_test(tcase_core, sprintf_tests27);
  tcase_add_test(tcase_core, sprintf_tests28);
  tcase_add_test(tcase_core, sprintf_tests29);
  tcase_add_test(tcase_core, sprintf_tests30);
  tcase_add_test(tcase_core, sprintf_tests31);
  tcase_add_test(tcase_core, sprintf_tests32);
  tcase_add_test(tcase_core, sprintf_tests33);
  tcase_add_test(tcase_core, sprintf_tests34);
  tcase_add_test(tcase_core, sprintf_tests35);
  tcase_add_test(tcase_core, sprintf_tests36);
  tcase_add_test(tcase_core, sprintf_tests37);
  tcase_add_test(tcase_core, sprintf_tests38);
  tcase_add_test(tcase_core, sprintf_tests39);
  tcase_add_test(tcase_core, sprintf_tests40);
  tcase_add_test(tcase_core, sprintf_tests41);
  tcase_add_test(tcase_core, sprintf_tests42);
  tcase_add_test(tcase_core, sprintf_tests43);
  tcase_add_test(tcase_core, sprintf_tests44);
  tcase_add_test(tcase_core, sprintf_tests45);
  tcase_add_test(tcase_core, sprintf_tests46);
  tcase_add_test(tcase_core, sprintf_tests47);
  tcase_add_test(tcase_core, sprintf_tests48);
  tcase_add_test(tcase_core, sprintf_tests49);
  tcase_add_test(tcase_core, sprintf_tests50);
  tcase_add_test(tcase_core, sprintf_tests51);
  tcase_add_test(tcase_core, sprintf_tests52);
  tcase_add_test(tcase_core, sprintf_tests53);
  tcase_add_test(tcase_core, sprintf_tests54);
  tcase_add_test(tcase_core, sprintf_tests55);
  tcase_add_test(tcase_core, sprintf_tests56);
  tcase_add_test(tcase_core, sprintf_tests57);
  tcase_add_test(tcase_core, sprintf_tests58);
  tcase_add_test(tcase_core, sprintf_tests59);
  tcase_add_test(tcase_core, sprintf_tests60);
  tcase_add_test(tcase_core, sprintf_tests61);

  tcase_add_test(tcase_core, sscanf_tests);
  tcase_add_test(tcase_core, sscanf_tests2);
  tcase_add_test(tcase_core, sscanf_tests3);
  tcase_add_test(tcase_core, sscanf_tests4);

  tcase_add_test(tcase_core, sscanf_tests7);
  tcase_add_test(tcase_core, sscanf_tests8);
  tcase_add_test(tcase_core, sscanf_tests9);
  tcase_add_test(tcase_core, sscanf_tests10);

  tcase_add_test(tcase_core, sscanf_tests11);
  tcase_add_test(tcase_core, sscanf_tests12);
  tcase_add_test(tcase_core, sscanf_tests13);

  tcase_add_test(tcase_core, sscanf_tests15);

  tcase_add_test(tcase_core, sscanf_tests16);
  tcase_add_test(tcase_core, sscanf_tests17);
  tcase_add_test(tcase_core, sscanf_tests18);
  tcase_add_test(tcase_core, sscanf_tests19);

  tcase_add_test(tcase_core, sscanf_tests21);

  tcase_add_test(tcase_core, sscanf_tests23);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *s21_string = example_suite_create();
  SRunner *s21_string_runner = srunner_create(s21_string);
  int failed = 0;
  srunner_run_all(s21_string_runner, CK_NORMAL);
  failed = srunner_ntests_failed(s21_string_runner);
  srunner_free(s21_string_runner);
  return failed == 0 ? 0 : 1;
}
