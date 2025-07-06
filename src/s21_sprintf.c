#include "s21_string.h"

void init_sprintf(struct format *format_struct);
void check_bad_flags(struct format *format_struct);
char *sprintf_spec_c(struct format *format_struct, char *str, int sym);
char *sprintf_spec_d(struct format *format_struct, char *str, int num);
char *sprintf_spec_s(struct format *format_struct, char *str, char *sym);
char *sprintf_spec_u(struct format *format_struct, char *str, s21_size_t num);
char *sprintf_spec_f(struct format *format_struct, char *str, long double num);
void *sprintf_spec_p(char *str, void *ptr);
char *sprintf_spec_ld(struct format *format_struct, char *str, long int num);
char *sprintf_spec_ls(struct format *format_struct, char *str, wchar_t *sym);
char *sprintf_spec_lu(struct format *format_struct, char *str, s21_size_t num);
void sprintf_spec_n(const char *str, const char *start, int *path);
char *sprintf_spec_ox(struct format *format_struct, char *str, int num);
char *sprintf_spec_lox(struct format *format_struct, char *str, long int num);
void convert_l_to_a(long int n, char *str, struct format *format_struct);
void convert_u_to_a(s21_size_t n, char *str);
void convert_lu_to_a(s21_size_t n, char *str);
void convert_i_to_a(int n, char *str);
void convert(unsigned int num, int x, struct format *format_struct, char *str);
void convert_f_long(unsigned long int num, int x, struct format *format_struct,
                    char *str);
char *convert_p_to_str(long x, int hex);
void set_wight(char *c, struct format *format_struct);
void set_flag_minus(char *c, struct format *format_struct);
void set_format(struct format *format_struct, char *str);
void set_lenght(int x, char *str, struct format *format_struct);
void set_format_f(struct format *format_struct, char *str, int num);
void set_flag_hash(char *c, struct format *format_struct, int i);
void set_accur_for_s(char *c, struct format *format_struct);
void set_accur_for_d(char *str, struct format *format_struct);
void set_wight_for_ox(char *c, struct format *format_struct);
void set_flag_plus_space(char *c, struct format *format_struct);
void str_reverse(char *str);

int s21_sprintf(char *str, const char *format, ...) {
  struct format format_struct;
  init_sprintf(&format_struct);
  const char *start = str;
  va_list argumets_p;
  va_start(argumets_p, format);
  char *format_ptr = (char *)format;
  while (*format_ptr != '\0') {
    if (*format_ptr == '%') {
      format_ptr++;
      while (*format_ptr == '-' || *format_ptr == '+' || *format_ptr == ' ' ||
             *format_ptr == '#' || *format_ptr == '0') {
        if (*format_ptr == '-')
          format_struct.flag_minus = 1;
        else if (*format_ptr == '+')
          format_struct.flag_plus = 1;
        else if (*format_ptr == ' ')
          format_struct.flag_space = 1;
        else if (*format_ptr == '#')
          format_struct.flag_hash = 1;
        else if (*format_ptr == '0')
          format_struct.flag_zero = 1;
        format_ptr++;
      }
      while ((*format_ptr >= '0' && *format_ptr <= '9') || *format_ptr == '*') {
        if (*format_ptr >= '0' && *format_ptr <= '9')
          format_struct.wight = format_struct.wight * 10 + (*format_ptr - '0');
        else if (*format_ptr == '*')
          format_struct.wight = va_arg(argumets_p, int);
        format_ptr++;
      }
      if (*format_ptr == '.') {
        format_struct.accur = 0;
        format_ptr++;
        while ((*format_ptr >= '0' && *format_ptr <= '9') ||
               *format_ptr == '*') {
          if (*format_ptr >= '0' && *format_ptr <= '9')
            format_struct.accur =
                format_struct.accur * 10 + (*format_ptr - '0');
          else if (*format_ptr == '*')
            format_struct.accur = va_arg(argumets_p, int);
          format_ptr++;
        }
      }
      if (*format_ptr == 'h' || *format_ptr == 'l' || *format_ptr == 'L')
        format_struct.lenght = *format_ptr++;
      if (*format_ptr == 'c' || *format_ptr == 'd' || *format_ptr == 'i' ||
          *format_ptr == 'e' || *format_ptr == 'E' || *format_ptr == 'f' ||
          *format_ptr == 'g' || *format_ptr == 'G' || *format_ptr == 'o' ||
          *format_ptr == 's' || *format_ptr == 'u' || *format_ptr == 'x' ||
          *format_ptr == 'X' || *format_ptr == 'p' || *format_ptr == 'n')
        format_struct.spec = *format_ptr++;
      else if (*format_ptr == '%')
        *str++ = *format_ptr++;
      if (format_struct.spec == 'c') {
        check_bad_flags(&format_struct);
        if (format_struct.lenght == 'l')
          str = sprintf_spec_c(&format_struct, str,
                               (int)va_arg(argumets_p, wchar_t));
        else
          str = sprintf_spec_c(&format_struct, str, va_arg(argumets_p, int));
      } else if (format_struct.spec == 'd' || format_struct.spec == 'i') {
        check_bad_flags(&format_struct);
        if (format_struct.lenght == 'l')
          str = sprintf_spec_ld(&format_struct, str,
                                va_arg(argumets_p, long int));
        else
          str = sprintf_spec_d(&format_struct, str, va_arg(argumets_p, int));
      } else if (format_struct.spec == 's') {
        check_bad_flags(&format_struct);
        if (format_struct.lenght == 'l') {
          wchar_t *y = va_arg(argumets_p, wchar_t *);
          str = sprintf_spec_ls(&format_struct, str, y);
        } else {
          char *x = va_arg(argumets_p, char *);
          str = sprintf_spec_s(&format_struct, str, x);
        }
      } else if (format_struct.spec == 'n') {
        sprintf_spec_n(str, start, va_arg(argumets_p, int *));
      } else if (format_struct.spec == 'o' || format_struct.spec == 'x' ||
                 format_struct.spec == 'X') {
        check_bad_flags(&format_struct);
        if (format_struct.lenght == 'l')
          str = sprintf_spec_lox(&format_struct, str,
                                 va_arg(argumets_p, long int));
        else
          str = sprintf_spec_ox(&format_struct, str, va_arg(argumets_p, int));
      } else if (format_struct.spec == 'u') {
        check_bad_flags(&format_struct);
        if (format_struct.lenght == 'l')
          str = sprintf_spec_lu(&format_struct, str,
                                va_arg(argumets_p, s21_size_t));
        else
          str = sprintf_spec_u(&format_struct, str,
                               va_arg(argumets_p, s21_size_t));
      } else if (format_struct.spec == 'f') {
        str = sprintf_spec_f(&format_struct, str, va_arg(argumets_p, double));
      } else if (format_struct.spec == 'p') {
        check_bad_flags(&format_struct);
        str = sprintf_spec_p(str, va_arg(argumets_p, void *));
      }
      init_sprintf(&format_struct);
    } else {
      *str++ = *format_ptr++;
    }
  }
  int result = str - start;
  va_end(argumets_p);
  return result;
}

void init_sprintf(struct format *format_struct) {
  format_struct->flag_plus = 0;
  format_struct->flag_minus = 0;
  format_struct->flag_space = 0;
  format_struct->flag_hash = 0;
  format_struct->flag_zero = 0;
  format_struct->wight = 0;
  format_struct->accur = -1;
  format_struct->accur_spec_d = 0;
  format_struct->minus = 0;
  format_struct->lenght = '0';
  format_struct->spec = '0';
  format_struct->negative = 0;
}

void check_bad_flags(struct format *format_struct) {
  if (format_struct->spec == 'c') {
    format_struct->flag_plus = format_struct->flag_space =
        format_struct->flag_hash = format_struct->flag_zero = 0;
    format_struct->accur = -1;
    if (format_struct->lenght == 'h' || format_struct->lenght == 'L')
      format_struct->lenght = '0';
  } else if (format_struct->spec == 'd' || format_struct->spec == 'i') {
    format_struct->flag_hash = 0;
    if (format_struct->lenght == 'L') format_struct->lenght = '0';
    if (format_struct->flag_minus && format_struct->flag_zero)
      format_struct->flag_minus = format_struct->flag_zero = 0;
    if (format_struct->flag_space && format_struct->flag_plus)
      format_struct->flag_space = 0;
  } else if (format_struct->spec == 's') {
    format_struct->flag_plus = format_struct->flag_space =
        format_struct->flag_hash = format_struct->flag_zero = 0;
    if (format_struct->lenght == 'h' || format_struct->lenght == 'L')
      format_struct->lenght = '0';
  } else if (format_struct->spec == 'o' || format_struct->spec == 'x' ||
             format_struct->spec == 'X') {
    format_struct->flag_plus = format_struct->flag_space = 0;
    if (format_struct->flag_minus && format_struct->flag_zero)
      format_struct->flag_minus = format_struct->flag_zero = 0;
    if (format_struct->lenght == 'L') format_struct->lenght = '0';
  } else if (format_struct->spec == 'u') {
    format_struct->flag_plus = format_struct->flag_hash =
        format_struct->flag_space = 0;
    if (format_struct->lenght == 'L') format_struct->lenght = '0';
  } else if (format_struct->spec == 'p') {
    format_struct->flag_plus = format_struct->flag_hash =
        format_struct->flag_space = format_struct->flag_zero = 0;
  }
}

char *sprintf_spec_c(struct format *format_struct, char *str, int sym) {
  char str_array[S21_BUFF] = {};
  char *c = str_array;
  *c = (char)sym;
  if (format_struct->wight > 0 && !format_struct->flag_minus)
    set_wight(c, format_struct);
  else if (format_struct->flag_minus && format_struct->wight > 0)
    set_flag_minus(c, format_struct);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_d(struct format *format_struct, char *str, int num) {
  char str_array[S21_BUFF];
  char *c = str_array;
  if (num < 0 && format_struct->wight && format_struct->accur == -1) {
    format_struct->minus = 1;
    num *= -1;
  }
  if (format_struct->lenght == 'h')
    set_lenght(num, str_array, format_struct);
  else
    convert_i_to_a(num, str_array);
  if (format_struct->accur == 0 && num == 0) *c = '\0';
  set_format(format_struct, str_array);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_ld(struct format *format_struct, char *str, long int num) {
  char str_array[S21_BUFF];
  char *c = str_array;
  if (num == LLONG_MIN) {
    c = "-9223372036854775808";
  } else {
    if (num < 0) format_struct->negative = 1;
    convert_l_to_a(num, str_array, format_struct);
  }
  set_format(format_struct, str_array);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_s(struct format *format_struct, char *str, char *sym) {
  char str_array[S21_BUFF] = {};
  int i = 0;
  while (*sym) str_array[i++] = *sym++;
  char *c = str_array;
  set_format(format_struct, c);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_ls(struct format *format_struct, char *str, wchar_t *sym) {
  char str_array[S21_BUFF] = {};
  char temp[S21_BUFF] = {};
  char *c = temp;
  int i = 0;
  while (sym[i] != '\0') {
    str_array[i] = (char)sym[i];
    i++;
  }
  int len = s21_strlen(str_array);
  i = 0;
  while (len) {
    c[i] = str_array[i];
    i++;
    len--;
  }
  set_format(format_struct, c);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

void sprintf_spec_n(const char *str, const char *start, int *path) {
  *path = str - start;
}

char *sprintf_spec_ox(struct format *format_struct, char *str, int num) {
  char str_array[S21_BUFF] = {};
  char *c = str_array;
  if (num == 0) {
    int i = 0;
    str_array[i++] = num + '0';
    format_struct->flag_hash = 0;
  } else if (format_struct->spec == 'o') {
    convert(num, 8, format_struct, c);
    if (num < 0 && format_struct->lenght == 'h') {
      c += 5;
      *c = '1';
    }
  } else if (format_struct->spec == 'x' || format_struct->spec == 'X') {
    convert(num, 16, format_struct, c);
    if (num < 0 && format_struct->lenght == 'h') c += 4;
  }
  if (format_struct->accur == 0 && num == 0) *c = '\0';
  set_format(format_struct, str_array);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_lox(struct format *format_struct, char *str, long int num) {
  char str_array[S21_BUFF] = {};
  char *c = str_array;
  if (format_struct->spec == 'o' && num != 0) {
    convert_f_long(num, 8, format_struct, c);
  } else if ((format_struct->spec == 'x' || format_struct->spec == 'X') &&
             num != 0) {
    convert_f_long(num, 16, format_struct, c);
  }
  set_format(format_struct, str_array);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_u(struct format *format_struct, char *str, s21_size_t num) {
  if (format_struct->accur > format_struct->wight) {
    format_struct->wight = format_struct->accur;
    format_struct->flag_zero = 1;
  }
  char str_array[S21_BUFF];
  char *c = str_array;
  convert_u_to_a(num, str_array);
  set_format(format_struct, str_array);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_lu(struct format *format_struct, char *str, s21_size_t num) {
  if (format_struct->accur > format_struct->wight) {
    format_struct->wight = format_struct->accur;
    format_struct->flag_zero = 1;
  }
  char str_array[S21_BUFF];
  char *c = str_array;
  convert_lu_to_a(num, str_array);
  set_format(format_struct, str_array);
  while (*c) *str++ = *c++;
  *str = '\0';
  return str;
}

char *sprintf_spec_f(struct format *format_struct, char *str, long double num) {
  if (format_struct->accur == -1) format_struct->accur = 6;
  if (num < 0 && format_struct->wight) {
    format_struct->minus = 1;
    num *= -1;
  }
  char str_array[S21_BUFF] = {};
  char *c = str_array;
  int whole_part = 0;
  whole_part = !format_struct->accur ? (int)round(num) : (int)num;
  convert_i_to_a(whole_part, c);
  if (format_struct->flag_hash || format_struct->accur) s21_strcat(c, ".");
  if (format_struct->accur) {
    long double ostatok = num - (int)num;
    int acc = format_struct->accur;
    while (acc--) ostatok *= 10;
    char fl[S21_BUFF] = {};
    char *f = fl;
    convert_i_to_a(abs((int)round(ostatok)), f);
    int len = s21_strlen(f);
    while (len++ < format_struct->accur) s21_strcat(c, "0");
    s21_strcat(c, f);
  }
  set_format_f(format_struct, c, num);
  while (*c) *str++ = *c++;
  *str = '\0';
  s21_strcat(str, c);
  return str;
}

void *sprintf_spec_p(char *str, void *ptr) {
  int a = 0;
  static char string_pointer[S21_BUFF] = "0x";
  a = 10;
  char *p = string_pointer;
  long x = (long)ptr;
  char *buf = convert_p_to_str(x, 16);
  s21_strcat(string_pointer, buf);
  if (str) a = 1;
  if (a == 1) {
    while (*p) *str++ = *p++;
    *str = '\0';
  }
  return str;
}

void set_wight(char *c, struct format *format_struct) {
  char str_buffer[S21_BUFF] = {};
  int len = s21_strlen(c);
  int i = 0;
  int W = format_struct->wight;
  if ((format_struct->minus || format_struct->flag_plus) &&
      format_struct->wight <= len) {
    if (format_struct->minus)
      str_buffer[i++] = '-';
    else if (format_struct->flag_plus)
      str_buffer[i++] = '+';
  }
  if (format_struct->flag_space && !format_struct->minus &&
      !format_struct->flag_plus) {
    str_buffer[i++] = ' ';
    W--;
  }
  if (format_struct->minus && format_struct->flag_zero) {
    str_buffer[i++] = '-';
    W--;
  }
  if (format_struct->flag_plus && !format_struct->minus &&
      format_struct->flag_zero) {
    str_buffer[i++] = '+';
    W--;
  }
  while (W-- > len) {
    if (format_struct->flag_zero && format_struct->spec != 'c' &&
        format_struct->spec != 's' && format_struct->spec != 'n' &&
        format_struct->spec != 'p')
      str_buffer[i++] = '0';
    else
      str_buffer[i++] = ' ';
  }
  if (format_struct->minus && !format_struct->flag_zero)
    str_buffer[i - 1] = '-';
  if (format_struct->flag_plus && !format_struct->minus &&
      !format_struct->flag_zero) {
    if (format_struct->accur > -1 && c[0] != '-')
      str_buffer[i - 1] = '+';
    else
      str_buffer[i - 1] = '+';
  }
  s21_strcat(str_buffer, c);
  i = 0;
  while (str_buffer[i]) *c++ = str_buffer[i++];
  *c = '\0';
}

void set_flag_minus(char *c, struct format *format_struct) {
  char temp[S21_BUFF] = {};
  int i = 0;
  if (format_struct->accur > -1) {
    if (format_struct->flag_plus && c[0] != '-' && !format_struct->minus)
      temp[i++] = '+';
    format_struct->flag_plus = 0;
  }
  if (format_struct->flag_hash && !format_struct->flag_zero &&
      (format_struct->spec == 'o' || format_struct->spec == 'x' ||
       format_struct->spec == 'X')) {
    int x = i;
    set_flag_hash(temp, format_struct, x);
  }
  if (format_struct->minus) {
    temp[i++] = '-';
    s21_strcat(temp, c);
  } else if (format_struct->flag_plus) {
    format_struct->flag_space = 0;
    temp[i++] = '+';
    s21_strcat(temp, c);
  } else if (format_struct->flag_space) {
    temp[i++] = ' ';
    s21_strcat(temp, c);
  } else {
    s21_strcat(temp, c);
  }
  int len = s21_strlen(temp);
  if (format_struct->wight < len) format_struct->wight = len;
  while (len < format_struct->wight) temp[len++] = ' ';
  temp[len] = '\0';
  s21_strcpy(c, temp);
}

void set_format(struct format *format_struct, char *str) {
  if (format_struct->spec == 's') {
    if (format_struct->accur > 0) set_accur_for_s(str, format_struct);
    if (format_struct->accur == 0) *str = '\0';
  } else if (format_struct->accur > 0) {
    set_accur_for_d(str, format_struct);
  }
  if (format_struct->wight > 0 && !format_struct->flag_minus &&
      (format_struct->spec == 'o' || format_struct->spec == 'x' ||
       format_struct->spec == 'X'))
    set_wight_for_ox(str, format_struct);
  else if (format_struct->wight > 0 && !format_struct->flag_minus)
    set_wight(str, format_struct);
  else if (format_struct->flag_minus && format_struct->wight > 0)
    set_flag_minus(str, format_struct);
  if (!format_struct->wight && format_struct->negative == 0 &&
      (format_struct->flag_plus || format_struct->flag_space))
    set_flag_plus_space(str, format_struct);
  if (!format_struct->wight && format_struct->flag_hash &&
      (format_struct->spec == 'o' || format_struct->spec == 'x' ||
       format_struct->spec == 'X'))
    set_flag_plus_space(str, format_struct);
}

void convert_u_to_a(s21_size_t n, char *str) {
  int i = 0;
  if (n == 0) {
    str[i] = n + '0';
    i++;
  } else {
    while (n > 0) {
      str[i] = n % 10 + '0';
      i++;
      n /= 10;
    }
  }
  str[i] = '\0';
  str_reverse(str);
}

void convert_lu_to_a(s21_size_t n, char *str) {
  int i = 0;
  while (n > 0) {
    str[i] = n % 10 + '0';
    i++;
    n /= 10;
  }
  str[i] = '\0';
  str_reverse(str);
}

void convert_l_to_a(long int n, char *str, struct format *format_struct) {
  int i = 0;
  if (n < 0) {
    n = n * -1;
  }
  while (n > 0) {
    str[i++] = n % 10 + '0';
    n /= 10;
  }
  if (format_struct->negative == 1) {
    str[i++] = '-';
  }
  str[i] = '\0';
  str_reverse(str);
}

void convert_i_to_a(int n, char *str) {
  int i = 0;
  long int x = n;
  if (n < 0) x *= -1;
  if (!x) str[i++] = '0';
  while (x > 0) {
    str[i] = x % 10 + '0';
    i++;
    x /= 10;
  }
  if (n < 0) {
    str[i] = '-';
    i++;
  }
  str[i] = '\0';
  str_reverse(str);
}

void convert(unsigned int num, int x, struct format *format_struct, char *str) {
  const char str_array[] = "0123456789abcdef";
  const char str_array1[] = "0123456789ABCDEF";
  int i = 0;
  char str_buffer[S21_BUFF] = {};
  if (format_struct->spec == 'x' || format_struct->spec == 'o') {
    while (num != 0 && x != 0) {
      str_buffer[i++] = str_array[num % x];
      num /= x;
    }
  }
  if (format_struct->spec == 'X') {
    while (num != 0 && x != 0) {
      str_buffer[i++] = str_array1[num % x];
      num /= x;
    }
  }
  str_buffer[i] = '\0';
  str_reverse(str_buffer);
  s21_strcat(str, str_buffer);
}

void convert_f_long(unsigned long int num, int x, struct format *format_struct,
                    char *str) {
  const char str_array[] = "0123456789abcdef";
  const char str_array1[] = "0123456789ABCDEF";
  int i = 0;
  char str_buffer[S21_BUFF] = {};
  if (format_struct->spec == 'x' || format_struct->spec == 'o') {
    while (num != 0 && x != 0) {
      str_buffer[i++] = str_array[num % x];
      num /= x;
    }
  }
  if (format_struct->spec == 'X') {
    while (num != 0 && x != 0) {
      str_buffer[i++] = str_array1[num % x];
      num /= x;
    }
  }
  str_buffer[i] = '\0';
  str_reverse(str_buffer);
  s21_strcat(str, str_buffer);
}

void set_lenght(int x, char *str, struct format *format_struct) {
  if (format_struct->lenght == 'h') x = (short)x;
  convert_i_to_a((int)x, str);
}

void set_format_f(struct format *format_struct, char *str, int num) {
  if (format_struct->wight > 0 && !format_struct->flag_minus)
    set_wight(str, format_struct);
  else if (format_struct->flag_minus && format_struct->wight > 0)
    set_flag_minus(str, format_struct);
  if (!format_struct->wight && num >= 0 &&
      (format_struct->flag_plus || format_struct->flag_space))
    set_flag_plus_space(str, format_struct);
}

void set_flag_hash(char *c, struct format *format_struct, int i) {
  c[i++] = '0';
  if (format_struct->spec == 'x')
    c[i++] = 'x';
  else if (format_struct->spec == 'X')
    c[i++] = 'X';
}

char *convert_p_to_str(long x, int hex) {
  long num = x;
  const char str_array[] = "0123456789abcdef";
  static char buffer[S21_BUFF];
  char *ptr = buffer;
  while (num != 0 && hex != 0) {
    *--ptr = str_array[num % hex];
    num /= hex;
  }
  return (ptr);
}

void set_accur_for_s(char *c, struct format *format_struct) {
  char str_buffer[S21_BUFF] = {};
  int len = s21_strlen(c);
  int i = 0;
  if (format_struct->accur < len) {
    len = format_struct->accur;
  }
  while (len > 0) {
    str_buffer[i++] = *c++;
    len--;
  }
  s21_strcpy(c, str_buffer);
  *c = '\0';
}

void set_accur_for_d(char *str, struct format *format_struct) {
  format_struct->accur_spec_d = 1;
  format_struct->flag_zero = 0;
  char temp_in[S21_BUFF] = {};
  char *c = temp_in;
  s21_strcpy(c, str);
  int len = s21_strlen(temp_in);
  int min = 0;
  char temp[S21_BUFF] = {};
  char *b = temp;
  if (c[0] == '-') {
    min = 1;
    c[0] = '0';
  }
  if (format_struct->accur > len) {
    int i = 0;
    if (format_struct->flag_hash && format_struct->spec == 'o') len++;
    if (min && format_struct->accur >= len + 1) {
      b[i++] = '-';
    }
    while (len != format_struct->accur) {
      b[i++] = '0';
      len++;
    }
    b[i] = '\0';
    s21_strcat(b, c);
    s21_strcpy(str, b);
  }
}

void set_wight_for_ox(char *c, struct format *format_struct) {
  char str_buffer[S21_BUFF] = {};
  int len = s21_strlen(c);
  int i = 0;
  int W = format_struct->wight;
  if (format_struct->flag_hash) {
    if (format_struct->spec == 'o') W--;
    if (format_struct->spec == 'x' || (format_struct->spec == 'X')) W -= 2;
  }
  if (!format_struct->flag_zero) {
    while (W-- > len) str_buffer[i++] = ' ';
  }
  if (format_struct->flag_hash) {
    set_flag_hash(str_buffer, format_struct, i);
    if (format_struct->spec == 'o')
      i += 1;
    else if (format_struct->spec == 'x' || format_struct->spec == 'X')
      i += 2;
  }
  if (format_struct->flag_zero) {
    while (W-- > len) str_buffer[i++] = '0';
  }
  s21_strcat(str_buffer, c);
  i = 0;
  while (str_buffer[i]) *c++ = str_buffer[i++];
}

void set_flag_plus_space(char *c, struct format *format_struct) {
  char str_buffer[S21_BUFF] = {};
  int i = 0;
  if (format_struct->flag_hash &&
      (format_struct->spec == 'o' || format_struct->spec == 'x' ||
       format_struct->spec == 'X'))
    set_flag_hash(str_buffer, format_struct, i);
  i = 0;
  if (format_struct->flag_plus) {
    format_struct->flag_space = 0;
    str_buffer[i++] = '+';
  }
  if (format_struct->flag_space) str_buffer[i++] = ' ';
  s21_strcat(str_buffer, c);
  i = 0;
  while (str_buffer[i]) *c++ = str_buffer[i++];
  *c = '\0';
}

void str_reverse(char *str) {
  int i, j;
  for (i = 0, j = s21_strlen(str) - 1; i < j; i++, j--) {
    char buffer = str[i];
    str[i] = str[j];
    str[j] = buffer;
  }
}
