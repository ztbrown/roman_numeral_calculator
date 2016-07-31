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
  tcase_add_test(tc_core, it_converts_10_to_X);
  tcase_add_test(tc_core, it_converts_20_to_XX);
  tcase_add_test(tc_core, it_converts_40_to_XL);
  tcase_add_test(tc_core, it_converts_50_to_L);

  suite_add_tcase(s, tc_core);

  return s;
}
