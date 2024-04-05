#ifndef S21_SSCANF_H
#define S21_SSCANF_H

typedef enum ConfigurationItems {
  ItemString,
  ItemSpecifier,
} ConfigurationItems;

typedef enum SpecifierSymbols {
  NoSpecifier,
  Symbol_d = 'd',
  Symbol_i = 'i',
  Symbol_u = 'u',
  Symbol_o = 'o',
  Symbol_x = 'x',
  Symbol_X = 'X',
  Symbol_f = 'f',
  Symbol_e = 'e',
  Symbol_E = 'E',
  Symbol_G = 'G',
  Symbol_c = 'c',
  Symbol_s = 's',
  Symbol_p = 'p',
  Symbol_n = 'n',
  Symbol_percent = '%',
} SpecifierSymbols;

typedef enum SpecifierLengthFlags {
  NoLengthFlag,
  LengthFlag_h = 'h',
  LengthFlag_l = 'l',
  LengthFlag_L = 'L',
} SpecifierLengthFlags;

typedef struct FormatSpecifierForScan {
  SpecifierSymbols specifier;
  int ignore;
  int width;
  SpecifierLengthFlags length;
} FormatSpecifierForScan;

typedef struct ConfigurationOfScan {
  int itemsCount;
  ConfigurationItems* items;

  int baseStringsCount;
  char** baseStrings;

  int formatSpecifiersCount;
  FormatSpecifierForScan* formatSpecifiers;
} ConfigurationOfScan;

int s21_strcnt(char* string, char symbol);
char* s21_strcpy(char* dest, const char* src);
void s21_strnul(char* string);

#endif