#include "s21_string.h"

void init_scanf(struct formats *format_struct);
int get_spec(char spec, struct formats *format_struct, va_list arguments_p);
int check_error(struct formats *format_struct);
void set_spaces(struct formats *format_struct);
void sscanf_spec_c(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_lc(struct formats *format_struct, va_list arguments_p);
int check_valid_s(char *c);
void sscanf_spec_s(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_ls(struct formats *format_struct, va_list arguments_p);
void check_isresult_d(int res, struct formats *format_struct, int *path);
void check_isresult_ld(int res, struct formats *format_struct, long *path);
int check_valid_d(char c);
int check_valid_o(int c);
int convert_o_to_int(int value);
int convert_x_to_int(int value);
void convert_str_to_i(int *res, struct formats *format_struct, int n,
                      int *path);
void convert_str_to_li(int *res, struct formats *format_struct, int n,
                       long *path);
void sscanf_spec_d(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_ld(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_o(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_lo(struct formats *format_struct, va_list arguments_p);
int check_valid_x(int value);
void sscanf_spec_x(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_lx(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_i(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_li(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_n(struct formats *format_struct, va_list arguments_p);
long double convert_str_to_lda(struct formats *format_struct, int *res);
void sscanf_spec_f(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_lf(struct formats *format_struct, va_list arguments_p);
int check_valid_f(char c);
void sscanf_spec_llf(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_p(struct formats *format_struct, va_list arguments_p);
void sscanf_spec_l(struct formats *format_struct, va_list arguments_p);
void *temp_adress(void);

int s21_sscanf(const char *str, const char *format, ...) {
  struct formats format_struct;
  char *format_ptr = (char *)format;
  va_list arguments_p;
  va_start(arguments_p, format);
  format_struct.str = format_struct.start = (char *)str;
  format_struct.result = *format_struct.str == '\0' ? -1 : 0;
  format_struct.error = 0;
  while (*format_ptr != '\0') {
    init_scanf(&format_struct);
    if (*format_ptr == '%' && *(format_ptr + 1) != '\0') {
      format_ptr++;
      if (*format_ptr == '*') {
        format_struct.ast = 1;
        format_ptr++;
      }
      while (*format_ptr >= '0' && *format_ptr <= '9')
        format_struct.wight = format_struct.wight * 10 + (*format_ptr++ - '0');
      if (*format_ptr == 'h' || *format_ptr == 'l' || *format_ptr == 'L')
        format_struct.lenght = *format_ptr++;
      if ((format_struct.error && *format_ptr != 'n') ||
          !get_spec(*format_ptr, &format_struct, arguments_p))
        break;
      check_error(&format_struct);
    }
    format_ptr++;
  }
  va_end(arguments_p);
  return format_struct.result;
}

void init_scanf(struct formats *format_struct) {
  format_struct->wight = 0;
  format_struct->lenght = '0';
  format_struct->minus = 1;
  format_struct->ast = 0;
  format_struct->wight = 0;
}

void *temp_adress(void) {
  static int temp[S21_BUFF] = {0};
  void *adress = temp;
  return adress;
}

int check_error(struct formats *format_struct) {
  if (!*format_struct->str) format_struct->error = 1;
  return format_struct->error;
}

void set_spaces(struct formats *format_struct) {
  while (!check_valid_s(format_struct->str)) format_struct->str++;
  if (*format_struct->str == '-') {
    format_struct->minus = -1;
    format_struct->str++;
    format_struct->wight--;
  } else if (*format_struct->str == '+') {
    format_struct->str++;
    format_struct->wight--;
  }
}

void sscanf_spec_c(struct formats *format_struct, va_list arguments_p) {
  char *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, char *);
  if (*format_struct->str) {
    *path = *format_struct->str++;
    if (!format_struct->ast) format_struct->result++;
  }
}

void sscanf_spec_lc(struct formats *format_struct, va_list arguments_p) {
  wchar_t *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, wchar_t *);
  if (*format_struct->str) {
    *path = (wchar_t)*format_struct->str++;
    format_struct->result++;
  }
}

int check_valid_s(char *c) {
  int res = 1;
  switch (*c) {
    case '\n':
    case '\t':
    case '\v':
    case '\f':
    case '\r':
    case ' ':
      res = 0;
      break;
  }
  return res;
}

void sscanf_spec_s(struct formats *format_struct, va_list arguments_p) {
  char *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, char *);
  while (!check_valid_s(format_struct->str)) format_struct->str++;
  int res = 0;
  while (!check_error(format_struct) && check_valid_s(format_struct->str) &&
         format_struct->wight--) {
    *path++ = *format_struct->str++;
    res = 1;
  }
  if (res && !format_struct->ast) format_struct->result += res;
  *path = '\0';
}

void sscanf_spec_ls(struct formats *format_struct, va_list arguments_p) {
  wchar_t *path = (wchar_t *)temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, wchar_t *);
  while (!check_valid_s(format_struct->str)) format_struct->str++;
  int res = 0;
  while (!check_error(format_struct) && check_valid_s(format_struct->str) &&
         format_struct->wight--) {
    *path++ = *format_struct->str++;
    res = 1;
  }
  if (res && !format_struct->ast) format_struct->result += res;
  *path = '\0';
}

void check_isresult_d(int res, struct formats *format_struct, int *path) {
  if (res && !format_struct->ast) {
    format_struct->result++;
    *path *= format_struct->minus;
  }
}

void check_isresult_ld(int res, struct formats *format_struct, long *path) {
  if (res && !format_struct->ast) {
    format_struct->result++;
    *path *= format_struct->minus;
  }
}

int check_valid_d(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') res = 1;
  return res;
}

int convert_o_to_int(int value) {
  if (value >= '0' && value <= '7') value -= '0';
  if (value >= '8' && value <= '9') value = 0;
  return value;
}

int convert_x_to_int(int value) {
  if (value >= '0' && value <= '9')
    value -= '0';
  else if (value == 'x')
    value = 0;
  else if (value == 'a' || value == 'A')
    value = 10;
  else if (value == 'b' || value == 'B')
    value = 11;
  else if (value == 'c' || value == 'C')
    value = 12;
  else if (value == 'd' || value == 'D')
    value = 13;
  else if (value == 'e' || value == 'E')
    value = 14;
  else if (value == 'f' || value == 'F')
    value = 15;
  return value;
}

int check_valid_o(int value) {
  int res = 0;
  if (value >= '0' && value <= '7') res = 1;
  return res;
}

void convert_str_to_i(int *res, struct formats *format_struct, int n,
                      int *path) {
  if (*res == 0) {
    *path = 0;
    *res = 1;
  }
  if (*format_struct->str == 'x')
    if (!format_struct->wight || !check_valid_d(*(format_struct->str + 1)))
      format_struct->error = 1;
  if (n == 10)
    *path = *path * n + (*format_struct->str - '0');
  else if (n == 8)
    *path = *path * n + convert_o_to_int(*format_struct->str);
  else if (n == 16)
    *path = *path * n + convert_x_to_int(*format_struct->str);
  format_struct->str++;
}

void convert_str_to_li(int *res, struct formats *format_struct, int n,
                       long *path) {
  if (*res == 0) {
    *path = 0;
    *res = 1;
  }
  if (*format_struct->str == 'x')
    if (format_struct->wight == 0 || !check_valid_d(*(format_struct->str + 1)))
      format_struct->error = 1;
  if (n == 10)
    *path = *path * n + (*format_struct->str - '0');
  else if (n == 8)
    *path = *path * n + convert_o_to_int(*format_struct->str);
  else if (n == 16)
    *path = *path * n + convert_x_to_int(*format_struct->str);
  format_struct->str++;
}

void sscanf_spec_d(struct formats *format_struct, va_list arguments_p) {
  int temp[S21_BUFF];
  int *path = temp;
  if (!format_struct->ast) path = va_arg(arguments_p, int *);
  set_spaces(format_struct);
  int res = 0;
  while (check_valid_d(*format_struct->str) && format_struct->wight--)
    convert_str_to_i(&res, format_struct, 10, path);
  check_isresult_d(res, format_struct, path);
  if (format_struct->lenght == 'h') *path = (unsigned short)*path;
}

void sscanf_spec_ld(struct formats *format_struct, va_list arguments_p) {
  long *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, long *);
  set_spaces(format_struct);
  int res = 0;
  while (check_valid_d(*format_struct->str) && format_struct->wight--)
    convert_str_to_li(&res, format_struct, 10, path);
  check_isresult_ld(res, format_struct, path);
}

void sscanf_spec_o(struct formats *format_struct, va_list arguments_p) {
  int *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, int *);
  set_spaces(format_struct);
  int res = 0;
  while (check_valid_o(*format_struct->str) && format_struct->wight--)
    convert_str_to_i(&res, format_struct, 8, path);
  check_isresult_d(res, format_struct, path);
  if (format_struct->lenght == 'h') *path = (unsigned short)*path;
}

void sscanf_spec_lo(struct formats *format_struct, va_list arguments_p) {
  long *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, long *);
  set_spaces(format_struct);
  int res = 0;
  while (check_valid_o(*format_struct->str) && format_struct->wight--)
    convert_str_to_li(&res, format_struct, 8, path);
  check_isresult_ld(res, format_struct, path);
}

int check_valid_x(int value) {
  int result = 0;
  if ((value >= '0' && value <= '9') || (value == 'x' || value == 'X') ||
      (value >= 'a' && value <= 'f') || (value >= 'A' && value <= 'F')) {
    result = 1;
  }
  return result;
}

void sscanf_spec_x(struct formats *format_struct, va_list arguments_p) {
  int *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, int *);
  set_spaces(format_struct);
  int res = 0;
  while (check_valid_x(*format_struct->str) && format_struct->wight--) {
    if (*format_struct->str == 'x' && !check_valid_d(*(format_struct->str + 1)))
      format_struct->error = 1;
    convert_str_to_i(&res, format_struct, 16, path);
  }
  check_isresult_d(res, format_struct, path);
  if (format_struct->lenght == 'h') *path = (unsigned short)*path;
}

void sscanf_spec_lx(struct formats *format_struct, va_list arguments_p) {
  long *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, long *);
  set_spaces(format_struct);
  int res = 0;
  while (check_valid_x(*format_struct->str) && format_struct->wight--)
    convert_str_to_li(&res, format_struct, 16, path);
  check_isresult_ld(res, format_struct, path);
}

void sscanf_spec_i(struct formats *format_struct, va_list arguments_p) {
  set_spaces(format_struct);
  if (*format_struct->str == '0' && *(format_struct->str + 1) == 'x')
    sscanf_spec_x(format_struct, arguments_p);
  else if (*format_struct->str == '0')
    sscanf_spec_o(format_struct, arguments_p);
  else if (check_valid_d(*format_struct->str))
    sscanf_spec_d(format_struct, arguments_p);
}

void sscanf_spec_li(struct formats *format_struct, va_list arguments_p) {
  set_spaces(format_struct);
  if (*format_struct->str == '0' && *(format_struct->str + 1) == 'x')
    sscanf_spec_lx(format_struct, arguments_p);
  else if (*format_struct->str == '0')
    sscanf_spec_lo(format_struct, arguments_p);
  else if (check_valid_d(*format_struct->str))
    sscanf_spec_ld(format_struct, arguments_p);
}

void sscanf_spec_n(struct formats *format_struct, va_list arguments_p) {
  int *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, int *);
  *path = format_struct->str - format_struct->start;
}

long double convert_str_to_lda(struct formats *format_struct, int *res) {
  set_spaces(format_struct);
  long double path = 0;
  while (check_valid_d(*format_struct->str) && format_struct->wight--) {
    path = path * 10 + (*format_struct->str - '0');
    format_struct->str++;
    *res = 1;
  }
  if (*format_struct->str >= '.' && format_struct->wight) {
    format_struct->str++;
    format_struct->wight--;
    long double x = 10;
    while (check_valid_d(*format_struct->str) && format_struct->wight--) {
      path = path + (*format_struct->str - '0') / x;
      x *= 10;
      format_struct->str++;
    }
  }
  if ((*format_struct->str == 'e' || *format_struct->str == 'E') &&
      format_struct->wight) {
    format_struct->str++;
    format_struct->wight--;
    int minus = 0;
    long double exp = 10;
    if (*format_struct->str == '+' && format_struct->wight) {
      format_struct->str++;
      format_struct->wight--;
    } else if (*format_struct->str == '-' && format_struct->wight) {
      format_struct->str++;
      format_struct->wight--;
      minus = 1;
    }
    int num = 0;
    while (check_valid_d(*format_struct->str) && format_struct->wight--)
      num = num * 10 + *format_struct->str++ - '0';
    exp = powl(10, num);
    path = minus ? path / exp : path * exp;
  }
  if (*res && !format_struct->ast) format_struct->result++;
  path *= format_struct->minus;
  return path;
}

void sscanf_spec_f(struct formats *format_struct, va_list arguments_p) {
  float *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, float *);
  int res = 0;
  float result = (float)convert_str_to_lda(format_struct, &res);
  if (res) *path = result;
}

void sscanf_spec_lf(struct formats *format_struct, va_list arguments_p) {
  double *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, double *);
  int res = 0;
  double result = (double)convert_str_to_lda(format_struct, &res);
  if (res) *path = result;
}

int check_valid_f(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') {
    res = 1;
  } else if (c == '.' || c == '-' || c == 'e' || c == '+') {
    res = 1;
  }
  return res;
}

void sscanf_spec_llf(struct formats *format_struct, va_list arguments_p) {
  while (*format_struct->str == ' ') format_struct->str++;
  long double *path = temp_adress();
  if (!format_struct->ast) path = va_arg(arguments_p, long double *);
  char *a = temp_adress();
  int i = 0;
  while (format_struct->wight-- && check_valid_f(*format_struct->str))
    *(a + i++) = *format_struct->str++;
  *(a + i) = '\0';
  long double result = strtold(a, &a);
  if (i && !format_struct->ast) {
    *path = result;
    format_struct->result++;
  }
}

void sscanf_spec_p(struct formats *format_struct, va_list arguments_p) {
  int a = 0;
  void **path = (void *)temp_adress();
  set_spaces(format_struct);
  if (!format_struct->ast) path = va_arg(arguments_p, void **);
  long adres = 0;
  int res = 0;
  while (check_valid_x(*format_struct->str) && format_struct->wight--) {
    adres = adres * 16 + convert_x_to_int(*format_struct->str);
    format_struct->str++;
    res = 1;
    a++;
  }
  if (res && !format_struct->ast) format_struct->result++;
  *path = (void *)adres;
}

void sscanf_spec_l(struct formats *format_struct, va_list arguments_p) {
  if (format_struct->spec == 'c')
    sscanf_spec_lc(format_struct, arguments_p);
  else if (format_struct->spec == 'i')
    sscanf_spec_li(format_struct, arguments_p);
  else if (format_struct->spec == 'o')
    sscanf_spec_lo(format_struct, arguments_p);
  else if (format_struct->spec == 's')
    sscanf_spec_ls(format_struct, arguments_p);
  else if (format_struct->spec == 'x' || format_struct->spec == 'X')
    sscanf_spec_lx(format_struct, arguments_p);
  else if (format_struct->spec == 'd' || format_struct->spec == 'u')
    sscanf_spec_ld(format_struct, arguments_p);
  else if (format_struct->spec == 'f' || format_struct->spec == 'G' ||
           format_struct->spec == 'g' || format_struct->spec == 'E' ||
           format_struct->spec == 'e')
    sscanf_spec_lf(format_struct, arguments_p);
}

int get_spec(char spec, struct formats *format_struct, va_list arguments_p) {
  int result = 1;
  format_struct->spec = spec;
  if (format_struct->wight == 0) format_struct->wight = 999999;
  if (format_struct->lenght == 'l')
    sscanf_spec_l(format_struct, arguments_p);
  else if (spec == 'c')
    sscanf_spec_c(format_struct, arguments_p);
  else if (spec == 'i')
    sscanf_spec_i(format_struct, arguments_p);
  else if (spec == 'o')
    sscanf_spec_o(format_struct, arguments_p);
  else if (spec == 's')
    sscanf_spec_s(format_struct, arguments_p);
  else if (spec == 'p')
    sscanf_spec_p(format_struct, arguments_p);
  else if (spec == 'n')
    sscanf_spec_n(format_struct, arguments_p);
  else if (spec == 'x' || spec == 'X')
    sscanf_spec_x(format_struct, arguments_p);
  else if (spec == 'd' || spec == 'u')
    sscanf_spec_d(format_struct, arguments_p);
  else if ((spec == 'f' || spec == 'G' || spec == 'g' || spec == 'E' ||
            spec == 'e') &&
           format_struct->lenght == 'L')
    sscanf_spec_llf(format_struct, arguments_p);
  else if (spec == 'f' || spec == 'G' || spec == 'g' || spec == 'E' ||
           spec == 'e')
    sscanf_spec_f(format_struct, arguments_p);
  else
    result = 0;
  return result;
}
