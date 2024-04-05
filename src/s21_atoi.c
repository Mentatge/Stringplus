
// convert string to int

int s21_atoi(char *src) {
  int res = 0;
  int i = 0;
  int sign = 1;

  if (src[i] == '-') {
    sign = -1;
    i++;
  }

  for (; src[i] != '\0'; i++) {
    res = res * 10 + src[i] - '0';
  }

  return sign * res;
}