#include <stdlib.h>
#include <check.h>
#include "check_from_arabic.h"
#include "../src/converter.h"

START_TEST(it_converts_1_to_I)
 {
   char * result = convert_from_arabic(1);

   ck_assert_str_eq(result, "I");

   free(result);
 }
END_TEST

START_TEST(it_converts_2_to_II)
 {
   char * result = convert_from_arabic(2);

   ck_assert_str_eq(result, "II");

   free(result);
 }
END_TEST

START_TEST(it_converts_5_to_V)
 {
   char * result = convert_from_arabic(5);

   ck_assert_str_eq(result, "V");

   free(result);
 }
END_TEST

START_TEST(it_converts_4_to_IV)
 {
   char * result = convert_from_arabic(4);

   ck_assert_str_eq(result, "IV");

   free(result);
 }
END_TEST

START_TEST(it_converts_9_to_IX)
 {
   char * result = convert_from_arabic(9);

   ck_assert_str_eq(result, "IX");

   free(result);
 }
END_TEST

START_TEST(it_converts_10_to_X)
 {
   char * result = convert_from_arabic(10);

   ck_assert_str_eq(result, "X");

   free(result);
 }
END_TEST

START_TEST(it_converts_20_to_XX)
 {
   char * result = convert_from_arabic(20);

   ck_assert_str_eq(result, "XX");

   free(result);
 }
END_TEST

START_TEST(it_converts_40_to_XL)
 {
   char * result = convert_from_arabic(40);

   ck_assert_str_eq(result, "XL");

   free(result);
 }
END_TEST

START_TEST(it_converts_50_to_L)
 {
   char * result = convert_from_arabic(50);

   ck_assert_str_eq(result, "L");

   free(result);
 }
END_TEST

START_TEST(it_converts_90_to_XC)
 {
   char * result = convert_from_arabic(90);

   ck_assert_str_eq(result, "XC");

   free(result);
 }
END_TEST

START_TEST(it_converts_100_to_C)
 {
   char * result = convert_from_arabic(100);

   ck_assert_str_eq(result, "C");

   free(result);
 }
END_TEST

START_TEST(it_converts_200_to_CC)
 {
   char * result = convert_from_arabic(200);

   ck_assert_str_eq(result, "CC");

   free(result);
 }
END_TEST

START_TEST(it_converts_400_to_CD)
 {
   char * result = convert_from_arabic(400);

   ck_assert_str_eq(result, "CD");

   free(result);
 }
END_TEST

START_TEST(it_converts_500_to_D)
 {
   char * result = convert_from_arabic(500);

   ck_assert_str_eq(result, "D");

   free(result);
 }
END_TEST

START_TEST(it_converts_900_to_CM)
 {
   char * result = convert_from_arabic(900);

   ck_assert_str_eq(result, "CM");

   free(result);
 }
END_TEST

START_TEST(it_converts_1000_to_M)
 {
   char * result = convert_from_arabic(1000);

   ck_assert_str_eq(result, "M");

   free(result);
 }
END_TEST

START_TEST(it_converts_2000_to_MM)
 {
   char * result = convert_from_arabic(2000);

   ck_assert_str_eq(result, "MM");

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
