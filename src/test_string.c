#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

// MARK: - STRLEN 5

START_TEST(STRLENTest1) {
  char str[] = "School21";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(STRLENTest2) {
  char str[] = "S chool 2 1 ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(STRLENTest3) {
  char str[] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(STRLENTest4) {
  char str[] = " S c h o o l 2 1 ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(STRLENTest5) {
  char str[] = "S c h o o l 2 1 \\n";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

// MARK: - STRERROR 1

START_TEST(STRERRORTest1) {
  for (int i = -100; i < 150; i++)
    ck_assert_str_eq(s21_strerror(i), strerror(i));
}
END_TEST

// MARK: - STRCPY 5

START_TEST(STRCPYTest1) {
  char str[] = "School21";
  char str1[15];
  char str2[15];
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest2) {
  char str[] = "   School21  ";
  char str1[15];
  char str2[15];
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest3) {
  char str[] = "\\nSchool21";
  char str1[15];
  char str2[15];
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest4) {
  char str[] = "";
  char str1[15] = "str";
  char str2[15] = "str";
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest5) {
  char str[] = "test";
  char str1[15] = "1";
  char str2[15] = "1";
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// MARK: - STRCHR 5

START_TEST(STRCHRTest1) {
  char str[] = "School21KZN";
  int ch = 'Z';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest2) {
  char str[] = "School21KZN";
  int ch = 'o';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest3) {
  char str[] = "School21KZN";
  int ch = 'x';
  ck_assert_ptr_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest4) {
  char str[] = "School21KZN";
  int ch = 'S';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest5) {
  char str[] = "School21KZN";
  int ch = '\0';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

// MARK:- STRSPN 8

START_TEST(STRSPNTest1) {
  char *str1 = "School21";
  char *str2 = "School";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test1");
}
END_TEST

START_TEST(STRSPNTest2) {
  char *str1 = "School21";
  char *str2 = "Scho345ol21";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test2");
}
END_TEST

START_TEST(STRSPNTest3) {
  char *str1 = "School21";
  char *str2 = "Sc23klhool21";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test3");
}
END_TEST

START_TEST(STRSPNTest4) {
  char *str1 = "School21";
  char *str2 = "kzn";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test4");
}
END_TEST

START_TEST(STRSPNTest5) {
  char *str1 = "School21";
  char *str2 = "12loohcS";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test5");
}
END_TEST

START_TEST(STRSPNTest6) {
  char *str1 = "School21";
  char *str2 = "KzNSchool21";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test6");
}
END_TEST

START_TEST(STRSPNTest7) {
  char *str1 = "School21";
  char *str2 = " ";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test7");
}
END_TEST

START_TEST(STRSPNTest8) {
  char *str1 = "School21";
  char *str2 = " Sc";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2),
                "Failed on test8");
}
END_TEST

// MARK: - STRCSPN 6

START_TEST(STRCSPNTest1) {
  char *src = "School21";
  char *str = "21";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on test1");
}
END_TEST

START_TEST(STRCSPNTest2) {
  char *src = "School21";
  char *str = "kzn";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on test2");
}
END_TEST

START_TEST(STRCSPNTest3) {
  char *src = "kzn";
  char *str = "21";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on test3");
}
END_TEST

START_TEST(STRCSPNTest4) {
  char *src = "School21";
  char *str = "School21";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on test4");
}
END_TEST

START_TEST(STRCSPNTest5) {
  char *src = "";
  char *str = "School21";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on test5");
}
END_TEST
START_TEST(STRCSPNTest6) {
  char *src = "\0";
  char *str = "\0";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on test6");
}
END_TEST

// MARK:- MEMCPY 5

START_TEST(MEMCPYTest1) {
  unsigned char *src = "School21";
  unsigned char dest1[5];
  unsigned char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest1, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest2) {
  char *src = "  Shool21";
  char dest1[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest1, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest3) {
  char *src = "Shool21";
  char dest1[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest1, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest4) {
  char *src = "Shco\0ol21";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest5) {
  char *src = "\0Sch\0ool21";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest6) {
  char *src = "";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 1), memcpy(dest2, src, 1), 1);
}
END_TEST

// MARK:- STRCAT 5
START_TEST(STRCATTest1) {
  char src[1024] = "School21";
  char dst[1024] = "KZN";
  ck_assert_str_eq(s21_strcat(dst, src), strcat(dst, src));
}
END_TEST

START_TEST(STRCATTest2) {
  char src[1024] = " ";
  char dst[1024] = "   ";
  ck_assert_str_eq(s21_strcat(dst, src), strcat(dst, src));
}
END_TEST

START_TEST(STRCATTest3) {
  char src[1024] = "S h c o o l 2 1 ";
  char dst[1024] = " K Z N 2022   ";
  ck_assert_str_eq(s21_strcat(dst, src), strcat(dst, src));
}
END_TEST

START_TEST(STRCATTest4) {
  char src[1024] = "School";
  char dst[1024] = "2 1                ";
  ck_assert_str_eq(s21_strcat(dst, src), strcat(dst, src));
}
END_TEST

START_TEST(STRCATTest5) {
  char src[1024] = "\0";
  char dst[1024] = "\n\0";
  ck_assert_str_eq(s21_strcat(dst, src), strcat(dst, src));
}
END_TEST

// MARK: MEMCMP 10
START_TEST(MEMCMPTest1) {
  char str1[] = "School21";
  char str2[] = "School21";
  int n = 6;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest2) {
  char str1[] = "School21";
  char str2[] = "SchOol21";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n) < 0, memcmp(str1, str2, n) < 0);
}
END_TEST
START_TEST(MEMCMPTest3) {
  char str1[] = "Sch1ol21";
  char str2[] = "School21";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n) > 0, memcmp(str1, str2, n) > 0);
}
END_TEST
START_TEST(MEMCMPTest4) {
  char str1[] = "SchSol21";
  char str2[] = "School21";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest5) {
  char str1[] = "School21";
  char str2[] = "";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n) > 0, memcmp(str1, str2, n) > 0);
}
END_TEST
START_TEST(MEMCMPTest6) {
  char str1[] = "";
  char str2[] = "";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n) < 0, memcmp(str1, str2, n) < 0);
}
END_TEST
START_TEST(MEMCMPTest7) {
  char str1[] = "School21";
  char str2[] = "12loohcS";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest8) {
  char str1[] = "School21\0School21";
  char str2[] = "School21";
  int n = 9;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest9) {
  char str1[] = "School21";
  char str2[] = "ScHool21";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n) > 0, memcmp(str1, str2, n) > 0);
}
END_TEST
START_TEST(MEMCMPTest10) {
  char str1[] = "t\300";
  char str2[] = "t\0";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n) > 0, memcmp(str1, str2, n) > 0);
}
END_TEST

// MARK: STRNCAT 5
START_TEST(STRNCATTest1) {
  char str1[1024] = "School21";
  char str2[] = " Kzn";
  int n = 4;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest2) {
  char str1[1024] = "School21";
  char str2[] = " KZN";
  int n = 4;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest3) {
  char str1[1024] = "";
  char str2[] = " School21";
  int n = 5;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest4) {
  char str1[1024] = "School21 ";
  char str2[] = "Kzn\0O";
  int n = 5;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest5) {
  char str1[1024] = "\0";
  char str2[] = "kzn";
  int n = 5;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

// MARK: STRNCPY 5

START_TEST(STRNCPYTest1) {
  char str1[1024] = "Shool21";
  char str2[] = " Kzn";
  int n = 6;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest2) {
  char str1[1024] = "Shool21";
  char str2[] = " Kazan";
  int n = 4;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest3) {
  char str1[1024] = "";
  char str2[] = " Shool21";
  int n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest4) {
  char str1[1024] = "Shool21, ";
  char str2[] = " Kzn\0O";
  int n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest5) {
  char str1[1024] = "Shool21, ";
  char str2[] = " Kazan";
  int n = 20;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

// MARK: - STRRCHR 5
START_TEST(STRRCHRTest1) {
  char str1[] = "School21 KZN";
  int c = 'l';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest2) {
  char str1[] = "School21 KZN";
  int c = 'z';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest3) {
  char str1[] = "";
  int c = 'z';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest4) {
  char str1[] = "School21 KZN";
  int c = '\0';
  ck_assert_str_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest5) {
  char str1[] = "School21 KZN";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest6) {
  char str1[] = "Hello world";
  ck_assert_pstr_eq(strrchr(str1, ' '), s21_strrchr(str1, ' '));

  char str2[] = "john.smith\0@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'm'), s21_strrchr(str2, 'm'));

  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));

  char str4[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str4, '6'), s21_strrchr(str4, '6'));

  char str5[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str5, 'o'), s21_strrchr(str5, 'o'));

  char str6[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str6, 'h'), s21_strrchr(str6, 'h'));

  char str7[] = "";
  ck_assert_pstr_eq(strrchr(str7, 'd'), s21_strrchr(str7, 'd'));

  char str8[] = {""};
  ck_assert_pstr_eq(strrchr(str8, 'z'), s21_strrchr(str8, 'z'));

  char str9[] = "";
  char str10 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str9, str10), strrchr(str9, str10));
}
END_TEST

// MARK:MEMMOVE 4

START_TEST(MEMMOVETest1) {
  char dest1[5] = "Dwdan";
  char dest2[5] = "Kazan";
  char src[7] = "student";
  ck_assert_mem_eq(s21_memmove(dest1, src, 3), memmove(dest2, src, 3), 5);
}
END_TEST

START_TEST(MEMMOVETest2) {
  char src[5] = "kazaN";
  char *dest1 = src + 3;
  char *dest2 = src + 3;
  ck_assert_mem_eq(s21_memmove(dest1, src, 5), memmove(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMMOVETest3) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[5] = "KazaN";
  ck_assert_mem_eq(s21_memmove(dest1, src, 5), memmove(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMMOVETest4) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[10] = "student\0";
  ck_assert_mem_eq(s21_memmove(dest1, src, 9), memmove(dest2, src, 9), 9);
}
END_TEST

START_TEST(MEMMOVETest5) {
  char dest1[10] = "\0";
  char dest2[10] = "\0";
  char src[9] = "student\0";
  ck_assert_mem_eq(s21_memmove(dest1, src, 9), memmove(dest2, src, 9), 9);
}
END_TEST

START_TEST(MEMMOVETest6) {
  char dest1[10] = "\0";
  char dest2[10] = "\0";
  char src[5] = "\0";
  ck_assert_mem_eq(s21_memmove(dest1, src, 2), memmove(dest2, src, 2), 4);
}
END_TEST

// MARK:STRSTR 5

START_TEST(STRSTRTest1) {
  char str1[10] = "School21";
  char str2[10] = "hoo";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest2) {
  char str1[10] = "School21";
  char str2[10] = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest3) {
  char str1[10] = "School21";
  char str2[10] = "kzn";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest4) {
  char str1[10] = "School21";
  char str2[10] = "School22";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest5) {
  char str1[1024] = "School21 KZN School21";
  char str2[10] = "School21";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest6) {
  char str1[1024] = "School21 KZN School21";
  char str2[10] = "";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest7) {
  char str1[1024] = "School21 KZN School21";
  char str2[10] = "l21";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(STRSTRTest8) {
  char str1[1024] = "S1111";
  char str2[10] = "S1111";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));

  char str3[1024] = "S";
  char str4[10] = "S";
  ck_assert_ptr_eq(s21_strstr(str3, str4), strstr(str3, str4));

  char str5[1024] = "";
  char str6[10] = "";
  ck_assert_ptr_eq(s21_strstr(str5, str6), strstr(str5, str6));

  char str7[20] = "casvavevewv";
  char str8[20] = "wefwgvwggwq";
  ck_assert_ptr_eq(s21_strstr(str7, str8), strstr(str7, str8));

  char str9[] = "abO";
  char str10[] = "abO";
  ck_assert_pstr_eq(s21_strstr(str9, str10), strstr(str9, str10));

  char str11[] = "abOB";
  char str12[] = "abOb";
  ck_assert_pstr_eq(s21_strstr(str11, str12), strstr(str11, str12));

  char str13[] = "abOBo";
  char str14[] = "abObo";
  ck_assert_pstr_eq(s21_strstr(str13, str14), strstr(str13, str14));

  char str15[] = "abOBos";
  char str16[] = "abOboS";
  ck_assert_pstr_eq(s21_strstr(str15, str16), strstr(str15, str16));

  char str17[] = "abOBosN";
  char str18[] = "abOboSN";
  ck_assert_pstr_eq(s21_strstr(str17, str18), strstr(str17, str18));

  char str19[] = "abOBosNy";
  char str20[] = "abOboSNY";
  ck_assert_pstr_eq(s21_strstr(str19, str20), strstr(str19, str20));

  char str21[] = "AbOBosNyT1";
  char str22[] = "BbOboSNYT1";
  ck_assert_pstr_eq(s21_strstr(str21, str22), strstr(str21, str22));

  char str23[] = "abOBosNyTSa";
  char str24[] = "abOboSNYTs1";
  ck_assert_pstr_eq(s21_strstr(str23, str24), strstr(str23, str24));
}
END_TEST

// MARK: STRCMP 6

START_TEST(STRCMPTest1) {
  char str1[10] = "School21";
  char str2[10] = "School21";
  ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest2) {
  char str1[10] = "School21";
  char str2[10] = "Schook21";
  ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest3) {
  char str1[10] = "School21";
  char str2[10] = "school21";
  ck_assert_int_eq(s21_strcmp(str1, str2) < 0, strcmp(str1, str2) < 0);
}
END_TEST

START_TEST(STRCMPTest4) {
  char str1[10] = "School21";
  char str2[10] = "";
  ck_assert_int_eq(s21_strcmp(str1, str2) > 0, strcmp(str1, str2) > 0);
}
END_TEST

START_TEST(STRCMPTest5) {
  char str1[10] = "";
  char str2[10] = "School21";
  ck_assert_int_eq(s21_strcmp(str1, str2) < 0, strcmp(str1, str2) < 0);
}
END_TEST

START_TEST(STRCMPTest6) {
  char str1[10] = "";
  char str2[10] = "";
  ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

// MARK: - MEMCHR 6

START_TEST(MEMCHRTest1) {
  char str1[10] = "School21";
  ck_assert_mem_eq(s21_memchr(str1, 'o', 5), memchr(str1, 'o', 5), 5);
}
END_TEST

START_TEST(MEMCHRTest2) {
  char str1[10] = "Studen21";
  ck_assert_msg(s21_memchr(str1, 'z', 5) == S21_NULL, "Failed: Str == NULL");
}
END_TEST

START_TEST(MEMCHRTest3) {
  char str1[10] = "Kazan";
  ck_assert_msg(s21_memchr(str1, 'Z', 5) == S21_NULL, "Failed: Str == NULL");
}
END_TEST

START_TEST(MEMCHRTest4) {
  char str1[10] = "School21";
  ck_assert_mem_eq(s21_memchr(str1, 'l', 8), memchr(str1, 'l', 8), 8);
}
END_TEST

START_TEST(MEMCHRTest5) {
  char str1[10] = "School21";
  ck_assert_mem_eq(s21_memchr(str1, 'S', 0), memchr(str1, 'S', 0), 0);
}
END_TEST

START_TEST(MEMCHRTest6) {
  char str1[10] = "School21";
  ck_assert_ptr_eq(s21_memchr(str1, 'X', 8), memchr(str1, 'X', 8));
}
END_TEST

// MARK: - STRPBRK 4

START_TEST(STRPBRKTest1) {
  char *str = "School21";
  char *str1 = "School";
  ck_assert_str_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(STRPBRKTest2) {
  char *str = "School21";
  char *str1 = "21o";
  ck_assert_str_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(STRPBRKTest3) {
  char *str = "School21";
  char *str1 = "Zoo";
  ck_assert_str_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(STRPBRKTest4) {
  char *str = "School21";
  char *str1 = "2l";
  ck_assert_str_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(STRPBRKTest5) {
  char *str = "School21";
  char *str1 = "xy";
  ck_assert_ptr_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

// MARK: - STRNCMP 8

START_TEST(STRNCMPTest1) {
  char *str1 = "School21";
  char *str2 = "School21";
  ck_assert_msg(s21_strncmp(str1, str2, 8) == strncmp(str1, str2, 8),
                "Failed on 1");
}
END_TEST

START_TEST(STRNCMPTest2) {
  char *str1 = "School21";
  char *str2 = "Schoon21";
  ck_assert_int_eq(s21_strncmp(str1, str2, 8) < 0, strncmp(str1, str2, 8) < 0);
}
END_TEST

START_TEST(STRNCMPTest3) {
  char *str1 = "School21";
  char *str2 = "School21";
  ck_assert_msg(s21_strncmp(str1, str2, 0) == strncmp(str1, str2, 0),
                "Failed on 3");
}
END_TEST

START_TEST(STRNCMPTest4) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 4");
}
END_TEST

START_TEST(STRNCMPTest5) {
  char *str1 = "School21";
  char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) > 0, strncmp(str1, str2, 5) > 0);
}
END_TEST

START_TEST(STRNCMPTest6) {
  char *str1 = "School21";
  char *str2 = "Cccool21";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) > 0, strncmp(str1, str2, 5) > 0);
}
END_TEST

START_TEST(STRNCMPTest7) {
  char *str1 = "kazan\0std";
  char *str2 = "kazan\0std";
  ck_assert_msg(s21_strncmp(str1, str2, 6) == strncmp(str1, str2, 6),
                "Failed on 7");
}
END_TEST
START_TEST(STRNCMPTest8) {
  char *str1 = "kazan";
  char *str2 = "azan";
  ck_assert_msg(s21_strncmp(str1, str2, 0) == strncmp(str1, str2, 0),
                "Failed on 8");
}
END_TEST

// MARK: - MEMSET 7

START_TEST(MEMSETTest1) {
  char str1[15] = "student-sh21";
  char str2[15] = "student-sh21";
  int c = 'Z';
  int n = 7;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest2) {
  char str1[15] = "student-sh21";
  char str2[15] = "Student-sh21";
  int c = 'V';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest3) {
  char str1[12] = "Student-sh21";
  char str2[12] = "Student-sh21";
  int c = 'x';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 12);
}
END_TEST

START_TEST(MEMSETTest4) {
  char str1[12] = "Student-sh21";
  char str2[12] = "Student-sh21";
  int c = '\0';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 12);
}
END_TEST

START_TEST(MEMSETTest5) {
  char str1[12] = "Student-sh21";
  char str2[12] = "Student-sh21";
  int c = '0';
  int n = 0;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 12);
}
END_TEST

START_TEST(MEMSETTest6) {
  char str1[12] = "Student-sh21";
  char str2[12] = "Student-sh21";
  int c = '\0';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 12);
}
END_TEST

START_TEST(MEMSETTest7) {
  char str1[14] = "Stu\0dent-sh21";
  char str2[14] = "Stu\0dent-sh21";
  int c = '\n';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 14);
}
END_TEST

// MARK: -STRTOK 6

START_TEST(STRTOKTest1) {
  static char str_in1[35] = "***kzn***school***student***sber***";
  static char str_in2[35] = "***kzn***school***student***sber***";
  char delim[4] = "***";

  ck_assert_str_eq(s21_strtok(str_in1, delim), strtok(str_in2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(STRTOKTest2) {
  static char str_in1[35] = "***kzn***school***student***sber***";
  static char str_in2[35] = "***kzn***school***student***sber***";
  char delim[4] = "**";

  ck_assert_str_eq(s21_strtok(str_in1, delim), strtok(str_in2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(STRTOKTest3) {
  static char str_in1[35] = "***kzn***school***student***sber***";
  static char str_in2[35] = "***kzn***school***student***sber***";
  char delim[4] = "*s";

  ck_assert_str_eq(s21_strtok(str_in1, delim), strtok(str_in2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(STRTOKTest4) {
  static char str_in1[36] = "***kzn***school***student***sber***";
  static char str_in2[36] = "***kzn***school***student***sber***";
  char delim[4] = "xxx";

  ck_assert_str_eq(s21_strtok(str_in1, delim), strtok(str_in2, delim));
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(STRTOKTest5) {
  static char str_in1[35] = "";
  static char str_in2[35] = "";
  char delim[4] = "";

  ck_assert_ptr_eq(s21_strtok(str_in1, delim), strtok(str_in2, delim));
}
END_TEST

START_TEST(STRTOKTest6) {
  static char str_in1[36] = "***kzn***school***student***sber***";
  static char str_in2[36] = "***kzn***school***student***sber***";
  char delim[1] = "";

  ck_assert_str_eq(s21_strtok(str_in1, delim), strtok(str_in2, delim));
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

// MARK: - TO_UPPER 7
START_TEST(TOUPPERTest1) {
  char str[6] = "kazan";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "KAZAN");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest2) {
  char str[14] = "School 21 kzn";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "SCHOOL 21 KZN");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest3) {
  char str[1] = "";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest4) {
  char str[6] = "KAZAN";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "KAZAN");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest5) {
  char str[11] = "21 sh - 21";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "21 SH - 21");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest6) {
  char *str = S21_NULL;
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_ptr_eq(str1, S21_NULL);
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest7) {
  char str[13] = "school21\0kzn";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "SCHOOL21");
  free(str1);
}
END_TEST

// MARK: - TO_LOWER 7
START_TEST(TOLOWERTest1) {
  char str[6] = "KAZAN";
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str1, "kazan");
  free(str1);
}
END_TEST

START_TEST(TOLOWERTest2) {
  char str[14] = "SchooL 21 kZn";
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str1, "school 21 kzn");
  free(str1);
}
END_TEST

START_TEST(TOLOWERTest3) {
  char str[1] = "";
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str1, "");
  free(str1);
}
END_TEST

START_TEST(TOLOWERTest4) {
  char str[6] = "kazan";
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str1, "kazan");
  free(str1);
}
END_TEST

START_TEST(TOLOWERTest5) {
  char str[11] = "21 SH - 21";
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str1, "21 sh - 21");
  free(str1);
}
END_TEST

START_TEST(TOLOWERTest6) {
  char *str = S21_NULL;
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_ptr_eq(str1, S21_NULL);
  free(str1);
}
END_TEST

START_TEST(TOLOWERTest7) {
  char str[13] = "SCHOOL21\0KZN";
  char *str1 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str1, "school21");
  free(str1);
}
END_TEST

// MARK: - INSERT 7
START_TEST(INSERTTest1) {
  char str1[4] = "abc";
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 2);
  ck_assert_str_eq(str3, "ab1234c");
  free(str3);
}
END_TEST

START_TEST(INSERTTest2) {
  char str1[1] = "";
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 1);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(INSERTTest3) {
  char str1[2] = " ";
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 1);
  ck_assert_str_eq(str3, " 1234");
  free(str3);
}
END_TEST

START_TEST(INSERTTest4) {
  char str1[4] = "abc";
  char str2[2] = " ";
  char *str3 = (char *)s21_insert(str1, str2, 2);
  ck_assert_str_eq(str3, "ab c");
  free(str3);
}
END_TEST

START_TEST(INSERTTest5) {
  char str1[4] = "abc";
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, -1);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(INSERTTest6) {
  char str1[4] = "abc";
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_str_eq(str3, "1234abc");
  free(str3);
}
END_TEST

START_TEST(INSERTTest7) {
  char *str1 = S21_NULL;
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

// MARK: - TRIM 8

START_TEST(TRIMTest1) {
  char *str = "School21S\0, Kzn";
  char *str2 = "S";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "chool21");
  free(str3);
}
END_TEST

START_TEST(TRIMTest2) {
  char *str = "              School21S     ";
  char *str2 = " ";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "School21S");
  free(str3);
}
END_TEST

START_TEST(TRIMTest3) {
  char *str = "   !2           School21S     ";
  char *str2 = " !2S";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "chool21");
  free(str3);
}
END_TEST

START_TEST(TRIMTest4) {
  char *str = "School21";
  char *str2 = "School21";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(TRIMTest5) {
  char *str = "oooooSchool21oooooo";
  char *str2 = "oooooooo";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "School21");
  free(str3);
}
END_TEST

START_TEST(TRIMTest6) {
  char *str = "School21";
  char *str2 = NULL;
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "School21");
  free(str3);
}
END_TEST

START_TEST(TRIMTest7) {
  char *str = "School21";
  char *str2 = "";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "School21");
  free(str3);
}
END_TEST

START_TEST(TRIMTest8) {
  char *str = S21_NULL;
  char *str2 = "wed";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

// MARK: - SPRINTF 1
START_TEST(SPRINTFTest1) {
  char str1[200] = {};
  char str2[200] = {};
  char s = 'S';
  char str3[6] = "kazan";
  s21_sprintf(str1, "test c:%c", s);
  sprintf(str2, "test c:%c", s);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test c:%-c %%", s);
  sprintf(str2, "test c:%-c %%", s);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test c:%s %15s", str3, str3);
  sprintf(str2, "test c:%s %15s", str3, str3);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test c:%c %-c %% %s", s, s, str3);
  sprintf(str2, "test c:%c %-c %% %s", s, s, str3);
  ck_assert_str_eq(str1, str2);

  wchar_t str_w[] = L"abra carabra";

  s21_sprintf(str1, "test c:%ls", str_w);
  sprintf(str2, "test c:%ls", str_w);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(SPRINTFTest2) {
  char str1[100] = {};
  char str2[100] = {};
  int n = 12345;
  long int n2 = 9876543210;
  short n3 = 333;

  s21_sprintf(str1, "test d: %d %+d", n, n);
  sprintf(str2, "test d: %d %+d", n, n);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test d: %8d %-8d %.5d", n, n, n);
  sprintf(str2, "test d: %8d %-8d %.5d", n, n, n);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test d: %hd %ld", n3, n2);
  sprintf(str2, "test d: %hd %ld", n3, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(SPRINTFTest3) {
  char str1[100] = {};
  char str2[100] = {};
  int n = 345678;
  long int n2 = 45454564654;
  short n3 = 777;
  s21_sprintf(str1, "test i: %i %+i %9i %-9i %.5i %hi", n, n, n, n, n, n3);
  sprintf(str2, "test i: %i %+i %9i %-9i %.5i %hi", n, n, n, n, n, n3);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "%hi %li", n3, n2);
  sprintf(str2, "%hi %li", n3, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(SPRINTFTest4) {
  char str1[100] = {};
  char str2[100] = {};
  float n = 1234567.891;
  double n2 = 456456454.43254325;

  s21_sprintf(str1, "test f: %5.4f", n);
  sprintf(str2, "test f: %5.4f", n);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test f: %-10.6f", n);
  sprintf(str2, "test f: %-10.6f", n);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test f: %12.6f", n2);
  sprintf(str2, "test f: %12.6f", n2);
  ck_assert_str_eq(str1, str2);

  s21_sprintf(str1, "test f: %5.4f %-10.6f %12.1f", n, n, n2);
  sprintf(str2, "test f: %5.4f %-10.6f %12.1f", n, n, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(SPRINTFTest0) {
  char c[255] = {}, d[255] = {}, x1 = 't';
  int n = 2100, n1 = 0, n2 = -21;
  short sh = 123, sh1 = -123;
  float f = 21.21, f1 = -21.21;
  long int lg = 12345678912345, lg1 = -12345678912345;
  s21_sprintf(c, "%% %p", &n);
  sprintf(d, "%% %p", &n);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
              lg1);
  sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld", n, n1, n2, sh, sh1, lg, lg1,
          lg1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
              2121, n2, n, 21, 55, -55);
  sprintf(d, "%10d %+3d %+010d %+-10d %+-10d % -10d %-10d %-10d", n, 212121,
          2121, n2, n, 21, 55, -55);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
  sprintf(d, "%-10d %010d %010d %*d %2d", 21, n2, n, 10, n, n2);
  ck_assert_str_eq(c, d);
  s21_sprintf(c,
              "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
              10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  sprintf(d, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
          10, n, n2, 42, 21, 10, n, n2, -21, x1, 21, -42);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
              USHRT_MAX, LONG_MAX, LONG_MIN);
  sprintf(d, "%d %d %d %d %d %ld %ld", INT_MIN, INT_MAX, SHRT_MAX, SHRT_MIN,
          USHRT_MAX, LONG_MAX, LONG_MIN);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
  sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
              "hello", "hello", "hello", "hello");
  sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
          "hello", "hello", "hello", "hello");
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
              L"hello", L"hello", L"hello", L"hello", L"hello");
  sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
          L"hello", L"hello", L"hello", L"hello", L"hello");
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%u %lu", UINT_MAX, ULONG_MAX);
  sprintf(d, "%u %lu", UINT_MAX, ULONG_MAX);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "hello %n", &n);
  sprintf(d, "hello %n", &n1);
  ck_assert_msg(c, d, "error");
  s21_sprintf(c, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n, 0,
              n2, 0, 21, 42);
  sprintf(d, "%-10o %lo %lo %o %o %o %10o %#10o %0#10o", 21, lg, lg1, n, 0, n2,
          0, 21, 42);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0,
              123);
  sprintf(d, "%#o %#o %#10o %0#10o %.10o %.0o %#5.10o", n, n2, 0, 0, n, 0, 123);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n,
              0, 123);
  sprintf(d, "%x %x %x %10x %-10x %.10x %.0x %#5.10x", n, n1, n2, 0, 21, n, 0,
          123);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n,
              n2, 21, 0, 42, 21, 0, -65, lg, lg1);
  sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n, n2,
          21, 0, 42, 21, 0, -65, lg, lg1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
  sprintf(d, "%X %X %X %10X %-10X %lX", n, n1, n2, 0, 21, lg1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0,
              4221, n1);
  sprintf(d, "%#X %#X %-#10X %#10X %#10X %0#10X %0#10X", n, n2, 21, 42, 0, 4221,
          n1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1,
              21.21, -21.21, 42.42, -42.42, f, f1);
  sprintf(d, "%+.1f %.2f %.3f %.4f %10.5f %10.5f %-10.3f %-10.2f", f, f1, 21.21,
          -21.21, 42.42, -42.42, f, f1);
  ck_assert_str_eq(c, d);
  s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
              21.21, 0.0, 21.21, 21., 0.0, 21.21);
  sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21., 21.21,
          0.0, 21.21, 21., 0.0, 21.21);
  ck_assert_str_eq(c, d);
  ck_assert_int_eq(
      s21_sprintf(c, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
                  21.21, 0.0, 21.21, 21., 0.0, 21.21),
      sprintf(d, "% 10f % 10f %f %.0f %.0f %#.0f %.0f %f %010f", f, f1, 21.,
              21.21, 0.0, 21.21, 21., 0.0, 21.21));
  ck_assert_int_eq(
      s21_sprintf(c, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx",
                  n, n2, 21, 0, 42, 21, 0, -65, lg, lg1),
      sprintf(d, "%#x %#x %#10x %#10x %-#10x %0#10x %0#10x %-10.5x %lx %lx", n,
              n2, 21, 0, 42, 21, 0, -65, lg, lg1));
}
END_TEST

// MARK: - SSCANF 30

START_TEST(SSCANFTest1) {
  char str[] = "21 -21 +21 0 -0 +0";
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
  s21_sscanf(str, "%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%d %d %d %d %d %d", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest2) {
  char str[] = "21 -21 +21 0 -0 +0";
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
  s21_sscanf(str, "%i %i %i %i %i %i", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%i %i %i %i %i %i", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest3) {
  char str[] = "021 -021 +021 00 -00 +00";
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
  s21_sscanf(str, "%i %i %i %i %i %i", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%i %i %i %i %i %i", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest4) {
  char str[] = "0x21 -0x21 +0x21 0x0 -0x0 +0x0";
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
  s21_sscanf(str, "%i %i %i %i %i %i", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%i %i %i %i %i %i", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest5) {
  char str[] = "0x21 -0x21 +0x21 0x0 -0x0 +0x0";
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
  s21_sscanf(str, "%i %i %i %i %i %i", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%i %i %i %i %i %i", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest6) {
  char str[] = "21 -21 +21 0 -0 +0";
  unsigned int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
      num11, num12;
  s21_sscanf(str, "%o %o %o %o %o %o", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%o %o %o %o %o %o", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest7) {
  char str[] = "021 -021 +021 00 -00 +00";
  unsigned int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
      num11, num12;
  s21_sscanf(str, "%o %o %o %o %o %o", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%o %o %o %o %o %o", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest8) {
  char str[] = "21 +21 0 +0";
  unsigned int num1, num2, num3, num4, num5, num6, num7, num8;
  s21_sscanf(str, "%u %u %u %u", &num1, &num2, &num3, &num4);
  sscanf(str, "%u %u %u %u", &num5, &num6, &num7, &num8);
  ck_assert_int_eq(num1, num5);
  ck_assert_int_eq(num2, num6);
  ck_assert_int_eq(num3, num7);
  ck_assert_int_eq(num4, num8);
}
END_TEST

START_TEST(SSCANFTest9) {
  char str[] = "0x21 -0x21 +0x21 0x0 -0x0 +0x0";
  unsigned int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
      num11, num12;
  s21_sscanf(str, "%x %x %x %x %x %x", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%x %x %x %x %x %x", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest10) {
  char str[] = "21 -21 +21 0 -0 +0";
  unsigned int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
      num11, num12;
  s21_sscanf(str, "%x %x %x %x %x %x", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%x %x %x %x %x %x", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_int_eq(num1, num7);
  ck_assert_int_eq(num2, num8);
  ck_assert_int_eq(num3, num9);
  ck_assert_int_eq(num4, num10);
  ck_assert_int_eq(num5, num11);
  ck_assert_int_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest11) {
  char str[] = "1.11 -2.2 +3.333 0 -0.0 +0.00";
  float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11,
      num12;
  s21_sscanf(str, "%f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%f %f %f %f %f %f", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_float_eq(num1, num7);
  ck_assert_float_eq(num2, num8);
  ck_assert_float_eq(num3, num9);
  ck_assert_float_eq(num4, num10);
  ck_assert_float_eq(num5, num11);
  ck_assert_float_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest12) {
  char str[] = "1.11 -2.2 +3.333 0 -0.0 +0.00";
  float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11,
      num12;
  s21_sscanf(str, "%e %e %e %e %e %e", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%e %e %e %e %e %e", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_float_eq(num1, num7);
  ck_assert_float_eq(num2, num8);
  ck_assert_float_eq(num3, num9);
  ck_assert_float_eq(num4, num10);
  ck_assert_float_eq(num5, num11);
  ck_assert_float_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest13) {
  char str[] = "1.11 -2.2 +3.333 0 -0.0 +0.00";
  float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11,
      num12;
  s21_sscanf(str, "%E %E %E %E %E %E", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%E %E %E %E %E %E", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_float_eq(num1, num7);
  ck_assert_float_eq(num2, num8);
  ck_assert_float_eq(num3, num9);
  ck_assert_float_eq(num4, num10);
  ck_assert_float_eq(num5, num11);
  ck_assert_float_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest14) {
  char str[] = "1.11 -2.2 +3.333 0 -0.0 +0.00";
  float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11,
      num12;
  s21_sscanf(str, "%g %g %g %g %g %g", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%g %g %g %g %g %g", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_float_eq(num1, num7);
  ck_assert_float_eq(num2, num8);
  ck_assert_float_eq(num3, num9);
  ck_assert_float_eq(num4, num10);
  ck_assert_float_eq(num5, num11);
  ck_assert_float_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest15) {
  char str[] = "1.11 -2.2 +3.333 0 -0.0 +0.00";
  float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11,
      num12;
  s21_sscanf(str, "%G %G %G %G %G %G", &num1, &num2, &num3, &num4, &num5,
             &num6);
  sscanf(str, "%G %G %G %G %G %G", &num7, &num8, &num9, &num10, &num11, &num12);
  ck_assert_float_eq(num1, num7);
  ck_assert_float_eq(num2, num8);
  ck_assert_float_eq(num3, num9);
  ck_assert_float_eq(num4, num10);
  ck_assert_float_eq(num5, num11);
  ck_assert_float_eq(num6, num12);
}
END_TEST

START_TEST(SSCANFTest16) {
  char str[] = "0x7fffffffd600";
  void **num1, **num2;
  s21_sscanf(str, "%p", &num1);
  sscanf(str, "%p", &num2);
  ck_assert_int_eq((unsigned long)num1, (unsigned long)num2);
}
END_TEST

START_TEST(SSCANFTest17) {
  char str[] = "Hello world!";
  char str1[30];
  char str2[30];
  s21_sscanf(str, "%13s", str1);
  sscanf(str, "%13s", str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(SSCANFTest18) {
  char str[] = "12345 -54321 999999 88 7667";
  int num1, num2, num5, num6, num7, num10;
  short int num3, num8;
  long int num4, num9;
  s21_sscanf(str, "%d %2d %2hd %2ld %d", &num1, &num2, &num3, &num4, &num5);
  sscanf(str, "%d %2d %2hd %2ld %d", &num6, &num7, &num8, &num9, &num10);
  ck_assert_int_eq(num1, num6);
  ck_assert_int_eq(num2, num7);
  ck_assert_int_eq(num3, num8);
  ck_assert_int_eq(num4, num9);
  ck_assert_int_eq(num5, num10);
}
END_TEST

START_TEST(SSCANFTest19) {
  char str[] = "1.2345 -5.4321";
  float num1, num3;
  long double num2, num4;
  s21_sscanf(str, "%f %Lf", &num1, &num2);
  sscanf(str, "%f %Lf", &num3, &num4);
  ck_assert_float_eq(num1, num3);
  ck_assert_float_eq(num2, num4);
}
END_TEST

START_TEST(SSCANFTest20) {
  char str[] = "ab";
  wchar_t a1, a2, a3, a4;
  s21_sscanf(str, "%lc %lc", &a1, &a2);
  sscanf(str, "%lc %lc", &a3, &a4);
  ck_assert_int_eq(a1, a3);
  ck_assert_int_eq(a2, a4);
}
END_TEST

START_TEST(SSCANFTest0) {
  wchar_t wc1, wc2;
  int a1 = 1, b1 = 0, i1 = 0, n1 = 0, i2 = 0, n2 = 0;
  unsigned int a2 = 1, a3 = 1, b2 = 0, b3 = 0;
  long e1 = 1, r1 = 1;
  unsigned long e2 = 0, r2 = 0;
  long double e3 = 0, e4 = 0, g3 = 0, g4 = 0, ld1 = 0, ld2 = 1;
  float f1 = 0, f2 = 1;
  char q1 = '0', w1 = '1', arr1[100] = "", arr2[100] = "";
  void *adres1 = S21_NULL, *adres2 = S21_NULL;
  ck_assert_int_eq(
      s21_sscanf(" -12345678asd", " %2d%2o%2x%1c%2s", &a1, &a2, &a3, &q1, arr1),
      sscanf(" -12345678asd", " %2d%2o%2x%1c%2s", &b1, &b2, &b3, &w1, arr2));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(q1, w1);
  ck_assert_str_eq(arr1, arr2);
  ck_assert_int_eq(s21_sscanf("z1.25e5 1.23e+10", "%lc%G%Le", &wc1, &f1, &ld1),
                   sscanf("z1.25e5 1.23e+10", "%lc%G%Le", &wc2, &f2, &ld2));
  ck_assert_float_eq(f1, f2);
  ck_assert_ldouble_eq(ld1, ld2);
  ck_assert_int_eq(s21_sscanf(" -123abcdeasd", "%2li%2lo", &e1, &e2),
                   sscanf(" -123abcdeasd", "%2li%2lo", &r1, &r2));
  ck_assert_int_eq(e1, r1);
  ck_assert_int_eq(e2, r2);
  ck_assert_int_eq(s21_sscanf("5 0x213def", "%1i%p%n", &i1, &adres1, &n1),
                   sscanf("5 0x213def", "%1i%p%n", &i2, &adres2, &n2));
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(n1, n2);
  ck_assert_ptr_eq(adres1, adres2);
  ck_assert_int_eq(
      s21_sscanf("1.23451e+15 34567837433.456", "%Le%Lg", &e3, &g3),
      sscanf("1.23451e+15 34567837433.456", "%Le%Lg", &e4, &g4));
  ck_assert_ldouble_eq(e3, e4);
  ck_assert_ldouble_eq(g3, g4);
  ck_assert_int_eq(s21_sscanf(" -123abcdeasd", "%2li%2lo", &e1, &e2),
                   sscanf(" -123abcdeasd", "%2li%2lo", &r1, &r2));
  ck_assert_int_eq(s21_sscanf(" -123abcdeasd", "dfdf"),
                   sscanf(" -123abcdeasd", "dfdf"));
}
END_TEST

Suite *my_suite_create() {
  Suite *my_suite = suite_create("Test_string");
  TCase *StrLenTest = tcase_create("STRLEN");
  TCase *StrErrorTest = tcase_create("STRERROR");
  TCase *StrCpyTest = tcase_create("STRCPY");
  TCase *StrChrTest = tcase_create("STRCHR");
  TCase *StrSpnTest = tcase_create("STRSPN");
  TCase *StrCspnTest = tcase_create("STRCSPN");
  TCase *MemCpyTest = tcase_create("MEMCPY");
  TCase *StrCatTest = tcase_create("STRCAT");
  TCase *MemCmpTest = tcase_create("MEMCMP");
  TCase *StrNcatTest = tcase_create("STRNCAT");
  TCase *StrNcpyTest = tcase_create("STRNCPY");
  TCase *StrRchrTest = tcase_create("STRRCHR");
  TCase *MemMoveTest = tcase_create("MEMMOVE");
  TCase *StrStrTest = tcase_create("STRSTR");
  TCase *StrCmpTest = tcase_create("STRCMP");
  TCase *MemChrTest = tcase_create("MEMCHR");
  TCase *StrPbrkTest = tcase_create("STRPBRK");
  TCase *StrNcmpTest = tcase_create("STRNCMP");
  TCase *MemSetTest = tcase_create("MEMSET");
  TCase *StrTokTest = tcase_create("STRTOK");
  TCase *ToUpperTest = tcase_create("TOUPPER");
  TCase *ToLowerTest = tcase_create("TOLOWER");
  TCase *InsertTest = tcase_create("INSERT");
  TCase *TrimTest = tcase_create("TRIM");
  TCase *SprintfTest = tcase_create("SPRINTF");
  TCase *SscanfTest = tcase_create("SSFANF");

  suite_add_tcase(my_suite, StrLenTest);
  tcase_add_test(StrLenTest, STRLENTest1);
  tcase_add_test(StrLenTest, STRLENTest2);
  tcase_add_test(StrLenTest, STRLENTest3);
  tcase_add_test(StrLenTest, STRLENTest4);
  tcase_add_test(StrLenTest, STRLENTest5);

  suite_add_tcase(my_suite, StrCpyTest);
  tcase_add_test(StrCpyTest, STRCPYTest1);
  tcase_add_test(StrCpyTest, STRCPYTest2);
  tcase_add_test(StrCpyTest, STRCPYTest3);
  tcase_add_test(StrCpyTest, STRCPYTest4);
  tcase_add_test(StrCpyTest, STRCPYTest5);

  suite_add_tcase(my_suite, StrErrorTest);
  tcase_add_test(StrErrorTest, STRERRORTest1);

  suite_add_tcase(my_suite, StrChrTest);
  tcase_add_test(StrChrTest, STRCHRTest1);
  tcase_add_test(StrChrTest, STRCHRTest2);
  tcase_add_test(StrChrTest, STRCHRTest3);
  tcase_add_test(StrChrTest, STRCHRTest4);
  tcase_add_test(StrChrTest, STRCHRTest5);

  suite_add_tcase(my_suite, StrSpnTest);
  tcase_add_test(StrSpnTest, STRSPNTest1);
  tcase_add_test(StrSpnTest, STRSPNTest2);
  tcase_add_test(StrSpnTest, STRSPNTest3);
  tcase_add_test(StrSpnTest, STRSPNTest4);
  tcase_add_test(StrSpnTest, STRSPNTest5);
  tcase_add_test(StrSpnTest, STRSPNTest6);
  tcase_add_test(StrSpnTest, STRSPNTest7);
  tcase_add_test(StrSpnTest, STRSPNTest8);

  suite_add_tcase(my_suite, StrCspnTest);
  tcase_add_test(StrCspnTest, STRCSPNTest1);
  tcase_add_test(StrCspnTest, STRCSPNTest2);
  tcase_add_test(StrCspnTest, STRCSPNTest3);
  tcase_add_test(StrCspnTest, STRCSPNTest4);
  tcase_add_test(StrCspnTest, STRCSPNTest5);
  tcase_add_test(StrCspnTest, STRCSPNTest6);

  suite_add_tcase(my_suite, MemCpyTest);
  tcase_add_test(MemCpyTest, MEMCPYTest1);
  tcase_add_test(MemCpyTest, MEMCPYTest2);
  tcase_add_test(MemCpyTest, MEMCPYTest3);
  tcase_add_test(MemCpyTest, MEMCPYTest4);
  tcase_add_test(MemCpyTest, MEMCPYTest5);
  tcase_add_test(MemCpyTest, MEMCPYTest6);

  suite_add_tcase(my_suite, StrCatTest);
  tcase_add_test(StrCatTest, STRCATTest1);
  tcase_add_test(StrCatTest, STRCATTest2);
  tcase_add_test(StrCatTest, STRCATTest3);
  tcase_add_test(StrCatTest, STRCATTest4);
  tcase_add_test(StrCatTest, STRCATTest5);

  suite_add_tcase(my_suite, MemCmpTest);
  tcase_add_test(MemCmpTest, MEMCMPTest1);
  tcase_add_test(MemCmpTest, MEMCMPTest2);
  tcase_add_test(MemCmpTest, MEMCMPTest3);
  tcase_add_test(MemCmpTest, MEMCMPTest4);
  tcase_add_test(MemCmpTest, MEMCMPTest5);
  tcase_add_test(MemCmpTest, MEMCMPTest6);
  tcase_add_test(MemCmpTest, MEMCMPTest7);
  tcase_add_test(MemCmpTest, MEMCMPTest8);
  tcase_add_test(MemCmpTest, MEMCMPTest9);
  tcase_add_test(MemCmpTest, MEMCMPTest10);

  suite_add_tcase(my_suite, StrNcatTest);
  tcase_add_test(StrNcatTest, STRNCATTest1);
  tcase_add_test(StrNcatTest, STRNCATTest2);
  tcase_add_test(StrNcatTest, STRNCATTest3);
  tcase_add_test(StrNcatTest, STRNCATTest4);
  tcase_add_test(StrNcatTest, STRNCATTest5);

  suite_add_tcase(my_suite, StrNcpyTest);
  tcase_add_test(StrNcpyTest, STRNCPYTest1);
  tcase_add_test(StrNcpyTest, STRNCPYTest2);
  tcase_add_test(StrNcpyTest, STRNCPYTest3);
  tcase_add_test(StrNcpyTest, STRNCPYTest4);
  tcase_add_test(StrNcpyTest, STRNCPYTest5);

  suite_add_tcase(my_suite, StrRchrTest);
  tcase_add_test(StrRchrTest, STRRCHRTest1);
  tcase_add_test(StrRchrTest, STRRCHRTest2);
  tcase_add_test(StrRchrTest, STRRCHRTest3);
  tcase_add_test(StrRchrTest, STRRCHRTest4);
  tcase_add_test(StrRchrTest, STRRCHRTest5);
  tcase_add_test(StrRchrTest, STRRCHRTest6);

  suite_add_tcase(my_suite, MemMoveTest);
  tcase_add_test(MemMoveTest, MEMMOVETest1);
  tcase_add_test(MemMoveTest, MEMMOVETest2);
  tcase_add_test(MemMoveTest, MEMMOVETest3);
  tcase_add_test(MemMoveTest, MEMMOVETest4);
  tcase_add_test(MemMoveTest, MEMMOVETest5);
  tcase_add_test(MemMoveTest, MEMMOVETest6);

  suite_add_tcase(my_suite, StrStrTest);
  tcase_add_test(StrStrTest, STRSTRTest1);
  tcase_add_test(StrStrTest, STRSTRTest2);
  tcase_add_test(StrStrTest, STRSTRTest3);
  tcase_add_test(StrStrTest, STRSTRTest4);
  tcase_add_test(StrStrTest, STRSTRTest5);
  tcase_add_test(StrStrTest, STRSTRTest6);
  tcase_add_test(StrStrTest, STRSTRTest7);
  tcase_add_test(StrStrTest, STRSTRTest8);

  suite_add_tcase(my_suite, StrCmpTest);
  tcase_add_test(StrCmpTest, STRCMPTest1);
  tcase_add_test(StrCmpTest, STRCMPTest2);
  tcase_add_test(StrCmpTest, STRCMPTest3);
  tcase_add_test(StrCmpTest, STRCMPTest4);
  tcase_add_test(StrCmpTest, STRCMPTest5);
  tcase_add_test(StrCmpTest, STRCMPTest6);

  suite_add_tcase(my_suite, MemChrTest);
  tcase_add_test(MemChrTest, MEMCHRTest1);
  tcase_add_test(MemChrTest, MEMCHRTest2);
  tcase_add_test(MemChrTest, MEMCHRTest3);
  tcase_add_test(MemChrTest, MEMCHRTest4);
  tcase_add_test(MemChrTest, MEMCHRTest5);
  tcase_add_test(MemChrTest, MEMCHRTest6);

  suite_add_tcase(my_suite, StrPbrkTest);
  tcase_add_test(StrPbrkTest, STRPBRKTest1);
  tcase_add_test(StrPbrkTest, STRPBRKTest2);
  tcase_add_test(StrPbrkTest, STRPBRKTest3);
  tcase_add_test(StrPbrkTest, STRPBRKTest4);
  tcase_add_test(StrPbrkTest, STRPBRKTest5);

  suite_add_tcase(my_suite, StrNcmpTest);
  tcase_add_test(StrNcmpTest, STRNCMPTest1);
  tcase_add_test(StrNcmpTest, STRNCMPTest2);
  tcase_add_test(StrNcmpTest, STRNCMPTest3);
  tcase_add_test(StrNcmpTest, STRNCMPTest4);
  tcase_add_test(StrNcmpTest, STRNCMPTest5);
  tcase_add_test(StrNcmpTest, STRNCMPTest6);
  tcase_add_test(StrNcmpTest, STRNCMPTest7);
  tcase_add_test(StrNcmpTest, STRNCMPTest8);

  suite_add_tcase(my_suite, MemSetTest);
  tcase_add_test(MemSetTest, MEMSETTest1);
  tcase_add_test(MemSetTest, MEMSETTest2);
  tcase_add_test(MemSetTest, MEMSETTest3);
  tcase_add_test(MemSetTest, MEMSETTest4);
  tcase_add_test(MemSetTest, MEMSETTest5);
  tcase_add_test(MemSetTest, MEMSETTest6);
  tcase_add_test(MemSetTest, MEMSETTest7);

  suite_add_tcase(my_suite, StrTokTest);
  tcase_add_test(StrTokTest, STRTOKTest1);
  tcase_add_test(StrTokTest, STRTOKTest2);
  tcase_add_test(StrTokTest, STRTOKTest3);
  tcase_add_test(StrTokTest, STRTOKTest4);
  tcase_add_test(StrTokTest, STRTOKTest5);
  tcase_add_test(StrTokTest, STRTOKTest6);

  suite_add_tcase(my_suite, ToUpperTest);
  tcase_add_test(ToUpperTest, TOUPPERTest1);
  tcase_add_test(ToUpperTest, TOUPPERTest2);
  tcase_add_test(ToUpperTest, TOUPPERTest3);
  tcase_add_test(ToUpperTest, TOUPPERTest4);
  tcase_add_test(ToUpperTest, TOUPPERTest5);
  tcase_add_test(ToUpperTest, TOUPPERTest6);
  tcase_add_test(ToUpperTest, TOUPPERTest7);

  suite_add_tcase(my_suite, ToLowerTest);
  tcase_add_test(ToLowerTest, TOLOWERTest1);
  tcase_add_test(ToLowerTest, TOLOWERTest2);
  tcase_add_test(ToLowerTest, TOLOWERTest3);
  tcase_add_test(ToLowerTest, TOLOWERTest4);
  tcase_add_test(ToLowerTest, TOLOWERTest5);
  tcase_add_test(ToLowerTest, TOLOWERTest6);
  tcase_add_test(ToLowerTest, TOLOWERTest7);

  suite_add_tcase(my_suite, InsertTest);
  tcase_add_test(InsertTest, INSERTTest1);
  tcase_add_test(InsertTest, INSERTTest2);
  tcase_add_test(InsertTest, INSERTTest3);
  tcase_add_test(InsertTest, INSERTTest4);
  tcase_add_test(InsertTest, INSERTTest5);
  tcase_add_test(InsertTest, INSERTTest6);
  tcase_add_test(InsertTest, INSERTTest7);

  suite_add_tcase(my_suite, TrimTest);
  tcase_add_test(TrimTest, TRIMTest1);
  tcase_add_test(TrimTest, TRIMTest2);
  tcase_add_test(TrimTest, TRIMTest3);
  tcase_add_test(TrimTest, TRIMTest4);
  tcase_add_test(TrimTest, TRIMTest5);
  tcase_add_test(TrimTest, TRIMTest6);
  tcase_add_test(TrimTest, TRIMTest7);
  tcase_add_test(TrimTest, TRIMTest8);

  suite_add_tcase(my_suite, SprintfTest);
  tcase_add_test(SprintfTest, SPRINTFTest1);
  tcase_add_test(SprintfTest, SPRINTFTest2);
  tcase_add_test(SprintfTest, SPRINTFTest3);
  tcase_add_test(SprintfTest, SPRINTFTest4);
  tcase_add_test(SprintfTest, SPRINTFTest0);

  suite_add_tcase(my_suite, SscanfTest);
  tcase_add_test(SscanfTest, SSCANFTest1);
  tcase_add_test(SscanfTest, SSCANFTest2);
  tcase_add_test(SscanfTest, SSCANFTest3);
  tcase_add_test(SscanfTest, SSCANFTest4);
  tcase_add_test(SscanfTest, SSCANFTest5);
  tcase_add_test(SscanfTest, SSCANFTest6);
  tcase_add_test(SscanfTest, SSCANFTest7);
  tcase_add_test(SscanfTest, SSCANFTest8);
  tcase_add_test(SscanfTest, SSCANFTest9);
  tcase_add_test(SscanfTest, SSCANFTest10);
  tcase_add_test(SscanfTest, SSCANFTest11);
  tcase_add_test(SscanfTest, SSCANFTest12);
  tcase_add_test(SscanfTest, SSCANFTest13);
  tcase_add_test(SscanfTest, SSCANFTest14);
  tcase_add_test(SscanfTest, SSCANFTest15);
  tcase_add_test(SscanfTest, SSCANFTest16);
  tcase_add_test(SscanfTest, SSCANFTest17);
  tcase_add_test(SscanfTest, SSCANFTest18);
  tcase_add_test(SscanfTest, SSCANFTest19);
  tcase_add_test(SscanfTest, SSCANFTest20);
  tcase_add_test(SscanfTest, SSCANFTest0);
  return my_suite;
}

int main() {
  int number_failed;
  Suite *my_suite = my_suite_create();
  SRunner *sr = srunner_create(my_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
