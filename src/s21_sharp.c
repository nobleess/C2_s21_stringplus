#include "s21_string.h"
/*
1 - void *to_upper(const char *str)
Возвращает копию строки (str), преобразованной в верхний регистр.
В случае какой-либо ошибки следует вернуть значение NULL
*/

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  char *res;
  s21_size_t len = s21_strlen(str);
  res = (char *)malloc(sizeof(char) * len + 1);

  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      res[i] = str[i] - 32;
    else
      res[i] = str[i];
  }
  res[len] = '\0';
  return res;
}

/*
2 - void *to_lower(const char *str)
Возвращает копию строки (str), преобразованной в нижний регистр.
В случае какой-либо ошибки следует вернуть значение NULL
*/

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  char *res;
  s21_size_t len = s21_strlen(str);
  res = (char *)malloc(sizeof(char) * len + 1);

  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      res[i] = str[i] + 32;
    else
      res[i] = str[i];
  }
  res[len] = '\0';
  return res;
}

/*
3 - void *insert(const char *src, const char *str, size_t start_index)
Возвращает новую строку, в которой указанная строка (str) вставлена
в указанную позицию (start_index) в данной строке (src).
В случае какой-либо ошибки следует вернуть значение NULL
*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || start_index > s21_strlen(src)) return S21_NULL;

  char *res;
  res = (char *)malloc(sizeof(char) * (s21_strlen(src) + s21_strlen(str) + 1));
  s21_size_t j = 0;

  for (s21_size_t i = 0; i < start_index; i++) {
    res[j++] = src[i];
  }
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    res[j++] = str[i];
  }
  for (s21_size_t i = start_index; i < s21_strlen(src); i++) {
    res[j++] = src[i];
  }
  res[j] = '\0';

  return (void *)res;
}

/*
4 - void *trim(const char *src, const char *trim_chars)
Возвращает новую строку, в которой удаляются все начальные и конечные
вхождения набора заданных символов (trim_chars) из данной строки (src).
В случае какой-либо ошибки следует вернуть значение NULL
*/

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) return S21_NULL;
  s21_size_t len_trim_chars = 0;
  if (trim_chars != S21_NULL) len_trim_chars = s21_strlen(trim_chars);

  s21_size_t len_src = s21_strlen(src);
  s21_size_t start_ind = 0;
  s21_size_t end_ind = len_src - 1;
  int trim_flag = 1;
  char *res;
  res = (char *)malloc(sizeof(char) * (len_src + 1));

  for (s21_size_t i = 0; i < len_src && trim_flag; i++) {
    trim_flag = 0;
    for (s21_size_t j = 0; j < len_trim_chars && !trim_flag; j++) {
      if (src[i] == trim_chars[j]) {
        start_ind = i + 1;
        trim_flag = 1;
      }
    }
  }

  trim_flag = 1;
  for (s21_size_t i = 0; i < len_src && trim_flag; i++) {
    trim_flag = 0;
    for (s21_size_t j = 0; j < len_trim_chars && !trim_flag; j++) {
      if (src[len_src - i - 1] == trim_chars[j]) {
        end_ind = len_src - i - 2;
        trim_flag = 1;
      }
    }
  }
  int j = 0;
  for (s21_size_t i = start_ind; i < end_ind + 1; i++) res[j++] = src[i];
  res[j] = '\0';
  return res;
}
