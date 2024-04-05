#include <wchar.h>

#include "s21_string.h"
#include "stdarg.h"

int SetWidth(char *tmp, specs_st *sp, char *src);
void SetAccuarcyForInt(char *tmp, int accuracy);
void IntProcessFunction(specs_st *sp, v_argument_uni *value, char *tmp,
                        char *src, va_list ap);
void F_ProcessFunction(specs_st *sp, v_argument_uni *value, char *tmp,
                       char *src, va_list ap);

static void s21_cpychr(char *dest, char sym) {
  dest[0] = sym;
  dest[1] = '\0';
}

void ProcessWideChar(wchar_t *string, char *src, char *tmp, specs_st *sp);

int GetArg(specs_st *sp, va_list ap, v_argument_uni *value, char *src) {
  int EXIT_CODE = SUCCESS;
  char tmp[256] = "";
  switch (sp->specifier) {
    case 'c':  // done
      if (sp->length) {
        value->wide_char = va_arg(ap, wchar_t);
        int conv_val = 0;
        conv_val = wctob(value->wide_char);
        s21_cpychr(tmp, conv_val);
        s21_strncat(src, tmp, s21_strlen(tmp));
      } else {
        value->num_i = va_arg(ap, int);
        s21_cpychr(tmp, value->num_i);
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'u':  // done
      if (sp->length != 'l') {
        value->num_ui = va_arg(ap, unsigned int);
      } else {
        value->num_ui = va_arg(ap, long unsigned int);
      }
      s21_u(value->num_ui, tmp, sp);
      SetAccuarcyForInt(tmp, sp->accuracy);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'o':
      value->num_i = va_arg(ap, int);
      s21_octal(value->num_i, tmp);
      s21_flags(src, sp->width, sp, tmp);  // done well
      SetAccuarcyForInt(tmp, sp->accuracy);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'i':  // done for fprintf as d
    case 'd':  // done all
      IntProcessFunction(sp, value, tmp, src, ap);
      break;
    case 's':  // wchar_t * x need to fix
      if (sp->length) {
        value->string_l = va_arg(ap, wchar_t *);
        ProcessWideChar(value->string_l, src, tmp, sp);

      } else {
        value->string = va_arg(ap, char *);
        if (sp->accuracy < 0) {
          sp->accuracy = s21_strlen(value->string);
        }
        s21_strncat(src, value->string, sp->accuracy);
      }
      break;
    case 'e':  //делается через f // fix
      if (sp->length == 'L') {
        value->num_lf = va_arg(ap, long double);
      } else {
        value->num_lf = (double)va_arg(ap, double);
      }
      s21_e(value->num_lf, tmp, sp->accuracy, sp);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'E':
      if (sp->length == 'L') {
        value->num_lf = va_arg(ap, long double);
      } else {
        value->num_lf = (double)va_arg(ap, double);
      }
      s21_E(value->num_lf, tmp, sp->accuracy);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'g':
      if (sp->length == 'L') {
        value->num_lf = va_arg(ap, long double);
      } else {
        value->num_lf = (double)va_arg(ap, double);
      }
      s21_g(value->num_lf, tmp, sp->accuracy, sp);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'G':
      if (sp->length == 'L') {
        value->num_lf = va_arg(ap, long double);
      } else {
        value->num_lf = (double)va_arg(ap, double);
      }
      s21_g(value->num_lf, tmp, sp->accuracy, sp);
      char *new = NULL;
      new = s21_to_upper(tmp);
      s21_strncpy(tmp, new, s21_strlen(new));
      free(new);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'x':  // maybe done need tests
      value->num_i = va_arg(ap, int);
      s21_hex(value->num_i, tmp);
      s21_flags(src, sp->accuracy, sp, tmp);  // done well
      SetAccuarcyForInt(tmp, sp->accuracy);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'X':  // as x
      value->num_i = va_arg(ap, int);
      s21_hex_big(value->num_i, tmp);
      s21_flags(src, sp->accuracy, sp, tmp);
      SetAccuarcyForInt(tmp, sp->accuracy);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
    case 'f':  // done without
      F_ProcessFunction(sp, value, tmp, src, ap);
      break;
    case 'p':  // done
      value->ptr = va_arg(ap, void *);
      s21_p(value->ptr, tmp);
      if (sp->width) {
        SetWidth(tmp, sp, src);
      } else {
        s21_strncat(src, tmp, s21_strlen(tmp));
      }
      break;
      break;
    default:
      break;
      // add remaining specs
  }
  return EXIT_CODE;
}

void IntProcessFunction(specs_st *sp, v_argument_uni *value, char *tmp,
                        char *src, va_list ap) {
  // lets get a value from ...
  if (sp->length == 'L' || sp->length == 'l') {
    value->num_i = va_arg(ap, long int);
  } else {
    value->num_i = va_arg(ap, int);
  }
  int spaceForSign = 0;
  if (sp->flag == '+' && value->num_i >= 0) {
    spaceForSign = 1;
    tmp[0] = '+';
  } else if (sp->flag == ' ' && value->num_i >= 0) {
    spaceForSign = 1;
    tmp[0] = ' ';
  }

  // convert int value to string
  s21_itoa(value->num_i, tmp + spaceForSign);
  SetAccuarcyForInt(tmp, sp->accuracy);
  if (sp->width) {
    SetWidth(tmp, sp, src);
  } else {
    s21_strncat(src, tmp, s21_strlen(tmp));
  }
}

void F_ProcessFunction(specs_st *sp, v_argument_uni *value, char *tmp,
                       char *src, va_list ap) {
  if (sp->length == 'L') {
    value->num_lf = va_arg(ap, long double);
  } else {
    value->num_f = va_arg(ap, double);
  }

  int spaceForSign = 0;
  if (sp->flag == '+') {
    if (sp->length == 'L' && (value->num_lf >= 0.)) {
      spaceForSign = 1;
      tmp[0] = '+';
    } else if (!sp->length && (value->num_f >= 0.)) {
      spaceForSign = 1;
      tmp[0] = '+';
    }
  } else if (sp->flag == ' ') {
    if (sp->length == 'L' && (value->num_lf >= 0.)) {
      spaceForSign = 1;
      tmp[0] = ' ';
    } else if (!sp->length && (value->num_f >= 0.)) {
      spaceForSign = 1;
      tmp[0] = ' ';
    }
  }
  if (sp->length == 'L') {
    s21_ftoa(value->num_lf, tmp + spaceForSign, sp->accuracy, sp->flag);
  } else {
    s21_ftoa(value->num_f, tmp + spaceForSign, sp->accuracy, sp->flag);
  }

  if (sp->width) {
    SetWidth(tmp, sp, src);
  } else {
    s21_strncat(src, tmp, s21_strlen(tmp));
  }
}

void SetAccuarcyForInt(char *tmp, int accuracy) {
  int len = (int)s21_strlen(tmp);
  int diff = accuracy - len;
  int i = 0;
  i = (1 == (int)s21_strlen(tmp)) && (tmp[0] == '0');
  if (accuracy == 0 && i) {
    tmp[0] = ' ';
  } else if (diff > 0) {
    char *zeroez = (char *)calloc(diff + 1, sizeof(char));
    for (int i = 0; i < diff; i++) {
      zeroez[i] = '0';
    }
    char *inserted = s21_insert(tmp, zeroez, 0);
    s21_strncpy(tmp, inserted, s21_strlen(inserted));
    free(inserted);
  }
}

int SetWidth(char *tmp, specs_st *sp, char *src) {
  int EXIT_CODE = SUCCESS;
  s21_size_t tmpSize = s21_strlen(tmp);
  int numOfZeroes = 0;
  numOfZeroes = sp->width - (int)tmpSize;
  if (numOfZeroes > 0) {
    char *zeroes = (char *)calloc(numOfZeroes + 1, sizeof(char));
    char ch = ' ';
    if (sp->flag == '0') {
      if (s21_strchr("oud", sp->specifier) && sp->accuracy < 0) {
        ch = '0';
      } else if (!s21_strchr("oud", sp->specifier)) {
        ch = '0';
      }
    }
    int i = 0;
    for (; i < numOfZeroes; i++) {
      zeroes[i] = ch;
    }
    zeroes[i] = '\0';

    if (sp->flag == '-') {
      s21_strncat(tmp, zeroes, s21_strlen(zeroes));
      s21_strncat(src, tmp, s21_strlen(tmp));
    } else {
      //добавить приклеивание нормальной ширины // done
      s21_strncat(src, zeroes, s21_strlen(zeroes));
      s21_strncat(src, tmp, s21_strlen(tmp));
    }
    free(zeroes);
  } else {
    s21_strncat(src, tmp, s21_strlen(tmp));
  }

  return EXIT_CODE;
}

void ProcessWideChar(wchar_t *string, char *src, char *tmp, specs_st *sp) {
  s21_size_t len = 0;
  len = wcslen(string);

  for (s21_size_t i = 0; i < len; i++) {
    int conv_bytes = 0;
    conv_bytes = wctob(string[i]);
    if (conv_bytes <= 128) {
      tmp[i] = conv_bytes;
    } else {
      continue;
    }
  }
  if (sp->accuracy >= 0) {
    tmp[sp->accuracy] = '\0';
  }
  if (sp->width) {
    SetWidth(tmp, sp, src);
  } else {
    s21_strncat(src, tmp, s21_strlen(tmp));
  }
}