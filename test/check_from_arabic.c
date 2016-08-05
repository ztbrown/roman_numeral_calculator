#include <stdlib.h>
#include <check.h>
#include "check_from_arabic.h"
#include "../src/converter.h"

START_TEST(it_converts_1_to_I)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(1, result), "I");

   free(result);
 }
END_TEST

START_TEST(it_converts_2_to_II)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(2, result), "II");

   free(result);
 }
END_TEST

START_TEST(it_converts_5_to_V)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(5, result), "V");

   free(result);
 }
END_TEST

START_TEST(it_converts_4_to_IV)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(4, result), "IV");

   free(result);
 }
END_TEST

START_TEST(it_converts_9_to_IX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(9, result), "IX");

   free(result);
 }
END_TEST

START_TEST(it_converts_10_to_X)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(10, result), "X");

   free(result);
 }
END_TEST

START_TEST(it_converts_20_to_XX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(20, result), "XX");

   free(result);
 }
END_TEST

START_TEST(it_converts_40_to_XL)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(40, result), "XL");

   free(result);
 }
END_TEST

START_TEST(it_converts_50_to_L)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(50, result), "L");

   free(result);
 }
END_TEST

START_TEST(it_converts_90_to_XC)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(90, result), "XC");

   free(result);
 }
END_TEST

START_TEST(it_converts_100_to_C)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(100, result), "C");

   free(result);
 }
END_TEST

START_TEST(it_converts_200_to_CC)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(200, result), "CC");

   free(result);
 }
END_TEST

START_TEST(it_converts_400_to_CD)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(400, result), "CD");

   free(result);
 }
END_TEST

START_TEST(it_converts_500_to_D)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(500, result), "D");

   free(result);
 }
END_TEST

START_TEST(it_converts_900_to_CM)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(900, result), "CM");

   free(result);
 }
END_TEST

START_TEST(it_converts_1000_to_M)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(1000, result), "M");

   free(result);
 }
END_TEST

START_TEST(it_converts_2000_to_MM)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(convert_from_arabic(2000, result), "MM");

   free(result);
 }
END_TEST

Suite * from_arabic_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("ConvertFromArabicSuite");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_converts_1_to_I);
  tcase_add_test(tc_core, it_converts_2_to_II);
  tcase_add_test(tc_core, it_converts_4_to_IV);
  tcase_add_test(tc_core, it_converts_5_to_V);
  tcase_add_test(tc_core, it_converts_9_to_IX);
  tcase_add_test(tc_core, it_converts_10_to_X);
  tcase_add_test(tc_core, it_converts_20_to_XX);
  tcase_add_test(tc_core, it_converts_40_to_XL);
  tcase_add_test(tc_core, it_converts_50_to_L);
  tcase_add_test(tc_core, it_converts_90_to_XC);
  tcase_add_test(tc_core, it_converts_100_to_C);
  tcase_add_test(tc_core, it_converts_200_to_CC);
  tcase_add_test(tc_core, it_converts_400_to_CD);
  tcase_add_test(tc_core, it_converts_500_to_D);
  tcase_add_test(tc_core, it_converts_900_to_CM);
  tcase_add_test(tc_core, it_converts_1000_to_M);
  tcase_add_test(tc_core, it_converts_2000_to_MM);

  suite_add_tcase(s, tc_core);

  return s;
}
