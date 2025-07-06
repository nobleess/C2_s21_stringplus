#include "s21_string.h"

/*
1 - void *memchr(const void *str, int c, size_t n)
Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах
строки, на которую указывает аргумент str.
*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i;
  char *result = S21_NULL;
  for (i = 0; c != *((char *)str + i) && i < n; i++) {
  }
  if (n - i) result = (char *)str + i;
  return (void *)result;
}

/*
2 - int memcmp(const void *str1, const void *str2, size_t n)
Сравнивает первые n байтов str1 и str2.
*/

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++) {
    int a = *((unsigned char *)str1 + i);
    int b = *((unsigned char *)str2 + i);
    if (a != b) result = a - b;
  }
  return result;
}

/*
3 - void *memcpy(void *dest, const void *src, size_t n)
Копирует n символов из src в dest.
*/

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++)
    *((unsigned char *)dest + i) = *((unsigned char *)src + i);
  return dest;
}

/*
4 - void *memmove(void *dest, const void *src, size_t n)
Еще одна функция для копирования n символов из str2 в str1.
*/

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *str_dest = (char *)dest;
  const char *str_src = (char *)src;
  if (str_dest <= str_src || str_dest >= str_src + n) {
    while (n--) {
      *str_dest = *str_src;
      str_dest++;
      str_src++;
    }
  } else {
    str_dest = str_dest + n - 1;
    str_src = str_src + n - 1;
    while (n--) {
      *str_dest = *str_src;
      str_dest--;
      str_src--;
    }
  }
  return dest;
}

/*
5 - void *memset(void *str, int c, size_t n)
Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
указывает аргумент str.
*/

void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *((unsigned char *)str + i) = c;
  }
  return str;
}

/*
6 - char *strcat(char *dest, const char *src)
Добавляет строку, на которую указывает src, в конец строки, на которую указывает
dest.
*/

char *s21_strcat(char *dest, const char *src) {
  char *ret = dest;
  while (*dest != '\0') dest++;
  while (*src != '\0') {
    *dest++ = *src++;
  }
  *dest++ = '\0';
  return ret;
}

/*
7 - char *strncat(char *dest, const char *src, size_t n)
Добавляет строку, на которую указывает src, в конец строки, на которую указывает
dest, длиной до n символов.
*/

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, j = 0;
  i = s21_strlen(dest);
  for (j = 0; j < n && src[j]; j++) {
    dest[i++] = src[j];
  }
  dest[i] = '\0';
  return (dest);
}

/*
8 - char *strchr(const char *str, int c)
Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
которую указывает аргумент str.
*/

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++)
    if (str[i] == c && result == S21_NULL) result = (char *)str + i;
  return result;
}

/*
9 - int strcmp(const char *str1, const char *str2)
Сравнивает строку, на которую указывает str1, со строкой, на которую указывает
str2.
*/

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  while (*str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
  }
  res = *str1 - *str2;
  return res;
}

/*
10 - int strncmp(const char *str1, const char *str2, size_t n)
Сравнивает не более первых n байтов str1 и str2.
*/

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n && res == 0; i++)
    if (*((char *)str1 + i) - *((char *)str2 + i) != 0)
      res = *((char *)str1 + i) - *((char *)str2 + i);
  return res;
}

/*
11 - char *strcpy(char *dest, const char *src)
Копирует строку, на которую указывает src, в dest.
*/

char *s21_strcpy(char *dest, const char *src) {
  for (s21_size_t i = 0; i < s21_strlen(src); i++) dest[i] = src[i];
  dest[s21_strlen(src)] = '\0';
  return dest;
}

/*12 - char *strncpy(char *dest, const char *src,
                    size_t n) Копирует до n символов из строки,
    на которую указывает src,
    в dest.*/

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ret = dest;
  while (n > 0) {
    *dest++ = *src++;
    n--;
  }
  return ret;
}

/*
13 - size_t strcspn(const char *str1, const char *str2)
Вычисляет длину начального сегмента str1, который полностью состоит из символов,
не входящих в str2.
*/

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i, j;
  s21_size_t count = 0;
  for (i = 0; *((char *)str1 + i) != '\0'; i++) {
    for (j = 0; *((char *)str2 + j) != '\0'; j++) {
      if (*((char *)str1 + i) == *((char *)str2 + j)) count++;
    }
    if (count > 0) return i;
  }
  return i;
}

/*14 - char *strerror(int errnum)
Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие
массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок
есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью
директив.
*/

// заголовки доп.функций

int countChar(int number);
int intToStr(int number, char *str);

char *s21_strerror(int errnum) {
  static char res[50];

  if (errnum >= 0 && errnum < NUM_ERRORS) {
    char *errors[NUM_ERRORS] = ERRORS_LIST;
    s21_strcpy(res, errors[errnum]);
  } else {
    s21_strcpy(res, "Unknown error");
    if (NUM_ERRORS == 107) s21_strcat(res, ":");
    s21_strcat(res, " ");
    if (errnum < 0) s21_strcat(res, "-");
    char temp[10];
    intToStr(errnum, temp);
    s21_strcat(res, temp);
  }
  return res;
}

int countChar(int number) {
  int res = 0;
  if (number == 0) return 1;
  if (number < 0) number *= -1;
  while (number > 0) {
    res++;
    number /= 10;
  }
  return res;
}

int intToStr(int number, char *str) {
  int count = 0;
  int len = countChar(number);
  if (number < 0) number *= -1;
  while (number > 0) {
    str[len - count - 1] = number % 10 + 48;
    number /= 10;
    count++;
  }
  str[count] = '\0';
  return count;
}

/*
15 - size_t strlen(const char *str)
Вычисляет длину строки str, не включая завершающий нулевой символ.
*/

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++) {
  }
  return len;
}

/*
16 - char *strpbrk(const char *str1, const char *str2)
Находит первый символ в строке str1, который соответствует любому символу,
указанному в str2.
*/

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t i, j;
  char *result = S21_NULL;
  for (i = 0; *((char *)str1 + i) != '\0' && result == S21_NULL; i++) {
    for (j = 0; *((char *)str2 + j) != '\0' && result == S21_NULL; j++)
      if (*((char *)str1 + i) == *((char *)str2 + j)) result = (char *)str1 + i;
  }
  return result;
}

/*
17 - char *strrchr(const char *str, int c)
Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
которую указывает аргумент str.
*/

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  s21_size_t len = s21_strlen(str);
  for (s21_size_t i = 0; i < len + 1 && result == S21_NULL; i++)
    if (str[len - i] == c) result = (char *)str + len - i;
  return result;
}

/*
18 - size_t strspn(const char *str1, const char *str2)
Вычисляет длину начального сегмента str1, который полностью состоит из символов
str2.
*/

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  int f_break = 0;

  for (s21_size_t i = 0; i < s21_strlen(str1) && !f_break; i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2) && !f_break; j++)
      if (str1[i] == str2[j]) {
        res++;
        f_break = 1;
      }
    f_break = 0;
    if (i != res - 1) f_break = 1;
  }
  return res;
}

/*
19 - char *strstr(const char *haystack, const char *needle)
Находит первое вхождение всей строки needle (не включая завершающий нулевой
символ), которая появляется в строке haystack.
*/

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  if (!haystack || !needle) return result;

  s21_size_t len_n = s21_strlen(needle);
  s21_size_t len_h = s21_strlen(haystack);

  if (len_n == 0) return (char *)haystack;

  s21_size_t j = 0, eval_count = 0;

  for (s21_size_t i = 0; i < len_h && (eval_count != len_n); i++) {
    if (haystack[i] == needle[j]) {
      eval_count++;
      j++;
    } else {
      j = 0;
      eval_count = 0;
    }
    if (eval_count == len_n) result = (char *)(haystack + i - (int)len_n + 1);
  }
  return result;
}

/*
20 - char *strtok(char *str, const char *delim)
Разбивает строку str на ряд токенов, разделенных delim.
*/

char *s21_strtok(char *str, const char *delim) {
  static char *ptr_next_str;
  char *ptr_str;
  if (str == S21_NULL) {
    ptr_str = ptr_next_str;
  } else {
    ptr_str = str;
  }
  ptr_str = ptr_str + s21_strspn(ptr_str, delim);
  if ((ptr_next_str = s21_strpbrk(ptr_str, delim)) != S21_NULL) {
    *ptr_next_str = '\0';
    ptr_next_str++;
  } else {
    ptr_next_str = ptr_str + s21_strlen(ptr_str);
  }
  if (*ptr_str == '\0') {
    ptr_str = S21_NULL;
  }
  return ptr_str;
}
