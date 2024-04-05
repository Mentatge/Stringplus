#define ALLSPECIFIERSYMBOLS "diuoxfegcspn%"
#define ALLSPECIFIERLENGTHFLAGS "hlL"
#define ALLSPECIFIERFLAGS "+- #0"

#include <stdarg.h>
#include <stdio.h>

#include "s21_string.h"

ConfigurationOfScan* InitializeConfigurationOfScan() {
  ConfigurationOfScan* configuration = calloc(1, sizeof(ConfigurationOfScan));

  configuration->itemsCount = 0;
  configuration->items = NULL;

  configuration->baseStringsCount = 0;
  configuration->baseStrings = NULL;

  configuration->formatSpecifiersCount = 0;
  configuration->formatSpecifiers = NULL;

  return configuration;
}

void ClearConfigurationOfScan(ConfigurationOfScan* configuration) {
  if (configuration->itemsCount) free(configuration->items);

  for (int i = 0; i < configuration->baseStringsCount; i++) {
    free(configuration->baseStrings[i]);
  }
  if (configuration->baseStringsCount) free(configuration->baseStrings);

  if (configuration->formatSpecifiersCount)
    free(configuration->formatSpecifiers);

  free(configuration);
}

void AddBaseStringToConfigurationOfScan(ConfigurationOfScan* configuration,
                                        char* newBaseString) {
  configuration->itemsCount += 1;
  configuration->items = (ConfigurationItems*)realloc(
      configuration->items,
      configuration->itemsCount * sizeof(ConfigurationItems));
  configuration->items[configuration->itemsCount - 1] = ItemString;

  configuration->baseStringsCount += 1;
  configuration->baseStrings =
      (char**)realloc(configuration->baseStrings,
                      configuration->baseStringsCount * sizeof(char*));
  configuration->baseStrings[configuration->baseStringsCount - 1] =
      (char*)calloc(s21_strlen(newBaseString) + 1, sizeof(char));
  s21_strcpy(configuration->baseStrings[configuration->baseStringsCount - 1],
             newBaseString);
}

void AddFormatSpecifierToConfigurationOfScan(
    ConfigurationOfScan* configuration) {
  configuration->itemsCount += 1;
  configuration->items = (ConfigurationItems*)realloc(
      configuration->items,
      configuration->itemsCount * sizeof(ConfigurationItems));
  configuration->items[configuration->itemsCount - 1] = ItemSpecifier;

  configuration->formatSpecifiersCount += 1;
  configuration->formatSpecifiers = realloc(
      configuration->formatSpecifiers,
      configuration->formatSpecifiersCount * sizeof(FormatSpecifierForScan));

  configuration->formatSpecifiers[configuration->formatSpecifiersCount - 1]
      .length = NoLengthFlag;
  configuration->formatSpecifiers[configuration->formatSpecifiersCount - 1]
      .specifier = NoSpecifier;
  configuration->formatSpecifiers[configuration->formatSpecifiersCount - 1]
      .width = -1;
  configuration->formatSpecifiers[configuration->formatSpecifiersCount - 1]
      .ignore = 0;
}

int ParseSpecifierInnerNumbers(char* string, char* tempString, s21_size_t* i,
                               int* errorCount) {
  int tempStringLength = 0;
  int parsed = -1;

  for (; *i < s21_strlen(string) &&
         ((string[*i] >= '0' && string[*i] <= '9') || string[*i] == '*');
       *i += 1) {
    tempString[tempStringLength++] = string[*i];
  }

  if (tempString == NULL) {
    parsed = -1;
  } else {
    if (s21_strchr(tempString, '*')) {
      if (s21_strlen(tempString) == 1) {
        parsed = -2;
      } else {
        *errorCount += 1;
      }
    } else {
      parsed = atoi(tempString);
    }
  }

  return parsed;
}

int ParseSpecifierForScan(FormatSpecifierForScan* specifier, char* string) {
  int errorCount = 0;

  s21_size_t stringLength = s21_strlen(string);

  char tempWidth[64] = {0};
  char* tempLength = NULL;

  for (s21_size_t i = 0; i < stringLength; i++) {
    if (string[i] == '*' && !specifier->ignore &&
        !s21_strchr("n", specifier->specifier)) {
      specifier->ignore = 1;
    } else if ((string[i] >= '0' && string[i] <= '9') &&
               specifier->width == -1 &&
               !s21_strchr("cn", specifier->specifier)) {
      specifier->width =
          ParseSpecifierInnerNumbers(string, tempWidth, &i, &errorCount);
      i--;
    } else if (tempLength == NULL &&
               (tempLength = s21_strchr(ALLSPECIFIERLENGTHFLAGS, string[i]))) {
      specifier->length = *tempLength;
    } else {
      errorCount++;
    }
  }

  if (specifier->specifier == Symbol_c && specifier->width == -1)
    specifier->width = 1;

  return errorCount;
}

int ParseScanFormatFromString(ConfigurationOfScan* configuration,
                              char* format) {
  int errorCount = 0;

  s21_size_t stringLength = s21_strlen(format);
  char* endOfSpecifier = NULL;

  char tempBaseString[256] = {0};
  int tempBaseStringLength = 0;
  FormatSpecifierForScan* nowSpecifier;

  for (s21_size_t i = 0; i < stringLength; i++) {
    if (format[i] == '%') {
      i++;
      char specifierInside[128] = {0};
      int specifierInsideLength = 0;
      for (; i < stringLength &&
             !(endOfSpecifier = s21_strchr(ALLSPECIFIERSYMBOLS, format[i]));
           i++) {
        specifierInside[specifierInsideLength] = format[i];
      }

      if (endOfSpecifier == NULL) {
        errorCount += 1;
      } else if (*endOfSpecifier != Symbol_percent) {
        AddFormatSpecifierToConfigurationOfScan(configuration);
        nowSpecifier =
            &(configuration
                  ->formatSpecifiers[configuration->formatSpecifiersCount - 1]);
        nowSpecifier->specifier = *endOfSpecifier;
        errorCount += ParseSpecifierForScan(nowSpecifier, specifierInside);
      } else {
        AddBaseStringToConfigurationOfScan(configuration, "%");
      }
    } else if (endOfSpecifier) {
      endOfSpecifier = NULL;
      i--;
    } else {
      tempBaseString[tempBaseStringLength++] = format[i];
      if (i + 1 < stringLength) {
        if (format[i + 1] == '%') {
          AddBaseStringToConfigurationOfScan(configuration, tempBaseString);
          s21_strnul(tempBaseString);
          tempBaseStringLength = 0;
        }
      }
    }
  }

  if (tempBaseStringLength != 0) {
    AddBaseStringToConfigurationOfScan(configuration, tempBaseString);
  }

  return errorCount;
}

int s21_sscanf(const char* str, const char* format, ...) {
  ConfigurationOfScan* configuration = InitializeConfigurationOfScan();
  int scaned = 0;
  int errorCount = (str == NULL || format == NULL);
  if (errorCount == 0)
    errorCount = ParseScanFormatFromString(configuration, (char*)format);
  if (errorCount == 0) {
    char* string = (char*)str;
    int baseStringIndex = -1, specifierIndex = -1;
    va_list varg;
    va_start(varg, format);
    int noMatch = 0;
    for (int i = 0; i < configuration->itemsCount && s21_strlen(string) > 0;
         i++) {
      specifierIndex += (configuration->items[i] == ItemSpecifier);
      baseStringIndex += (configuration->items[i] == ItemString);

      if (configuration->items[i] == ItemSpecifier && !noMatch) {
        FormatSpecifierForScan nowSpecififer =
            configuration->formatSpecifiers[specifierIndex];
        SpecifierSymbols nowSpecififerSymbol = nowSpecififer.specifier;

        char nowString[128] = {0};
        s21_strcpy(nowString, string);
        int nowStringLength = (int)s21_strlen(nowString);

        char numString[128] = {0};

        if (nowSpecififerSymbol != Symbol_c)
          s21_strcpy(numString, s21_strtok(nowString, " \n\t\0"));
        else
          numString[0] = nowString[0];

        int numStringLength = (int)s21_strlen(numString);
        nowStringLength = (int)s21_strlen(nowString);

        int separatorGotten = nowSpecififerSymbol != Symbol_c
                                  ? (nowStringLength - numStringLength)
                                  : 1;
        if (nowSpecififer.width != -1) {
          separatorGotten = numStringLength <= nowSpecififer.width;
        }

        if (nowSpecififer.width != -1 && !separatorGotten) {
          for (int i = 0; i < numStringLength; i++) {
            if (i >= nowSpecififer.width) numString[i] = '\0';
          }
        }

        numStringLength = (int)s21_strlen(nowString);

        int valid = 0;
        if (s21_strchr("di", nowSpecififerSymbol)) {
          long long value = s21_satoi(numString, 10, &valid);
          if (valid && !nowSpecififer.ignore) {
            if (nowSpecififer.length == LengthFlag_h)
              *(va_arg(varg, short int*)) = value;
            else if (nowSpecififer.length == LengthFlag_l)
              *(va_arg(varg, long int*)) = value;
            else
              *(va_arg(varg, int*)) = value;
          }
        } else if (s21_strchr("uox", nowSpecififerSymbol)) {
          int base = 10;

          if (nowSpecififerSymbol == Symbol_o) base = 8;
          if (nowSpecififerSymbol == Symbol_x) base = 16;

          long long value = s21_satoi(numString, base, &valid);
          if (valid && !nowSpecififer.ignore) {
            if (nowSpecififer.length == LengthFlag_h)
              *(va_arg(varg, unsigned short int*)) = value;
            else if (nowSpecififer.length == LengthFlag_l)
              *(va_arg(varg, unsigned long int*)) = value;
            else
              *(va_arg(varg, unsigned int*)) = value;
          }
        } else if (nowSpecififerSymbol == Symbol_f) {
          long double value = s21_atof(numString, &valid);
          if (valid && !nowSpecififer.ignore) {
            if (nowSpecififer.length == LengthFlag_l)
              *(va_arg(varg, double*)) = value;
            else if (nowSpecififer.length == LengthFlag_L)
              *(va_arg(varg, long double*)) = value;
            else
              *(va_arg(varg, float*)) = value;
          }
        } else if (nowSpecififerSymbol == Symbol_n) {
          *(va_arg(varg, int*)) =
              (int)s21_strlen(str) - (int)s21_strlen(string);
        } else if (nowSpecififerSymbol == Symbol_c) {
          valid = 1;
          separatorGotten = 0;
          if (valid && !nowSpecififer.ignore)
            *(va_arg(varg, char*)) = numString[0];
        } else if (nowSpecififerSymbol == Symbol_s) {
          valid = numStringLength;
          if (!nowSpecififer.ignore) {
            s21_strcpy(va_arg(varg, char*), numString);
          }
        } else if (s21_strchr("eg", nowSpecififerSymbol)) {
          long double value = s21_atoe(numString, &valid);
          if (valid && !nowSpecififer.ignore) {
            if (nowSpecififer.length == LengthFlag_l)
              *(va_arg(varg, double*)) = value;
            else if (nowSpecififer.length == LengthFlag_L)
              *(va_arg(varg, long double*)) = value;
            else
              *(va_arg(varg, float*)) = value;
          }
        } else if (nowSpecififerSymbol == Symbol_p) {
          unsigned long long value = s21_satoi(numString, 10, &valid);
          if (valid && !nowSpecififer.ignore) {
            *(va_arg(varg, void**)) = (void*)value;
          }
        }

        if (valid) scaned += !nowSpecififer.ignore;

        string = string + (valid + separatorGotten);
      } else {
        char* nowBaseString = configuration->baseStrings[baseStringIndex];
        char* nowOffset = s21_strstr(string, nowBaseString);
        if (nowOffset) {
          if (nowOffset - string == 0) {
            string = string + s21_strlen(nowBaseString);
            noMatch = 0;
          } else
            noMatch = 1;
        } else
          noMatch = 1;
      }
    }
    va_end(varg);
  }

  ClearConfigurationOfScan(configuration);

  return scaned;
}