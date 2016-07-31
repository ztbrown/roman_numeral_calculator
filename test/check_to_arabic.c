#include <stdlib.h>
#include <check.h>
#include "check_to_arabic.h"
#include "../src/converter.h"

START_TEST(it_converts_I_to_1)
 {
   ck_assert_int_eq(convert_to_arabic("I"), 1);
 }
END_TEST

START_TEST(it_converts_II_to_2)
 {
   ck_assert_int_eq(convert_to_arabic("II"), 2);
 }
END_TEST

START_TEST(it_converts_V_to_5)
 {
   ck_assert_int_eq(convert_to_arabic("V"), 5);
 }
END_TEST

START_TEST(it_converts_X_to_10)
 {
   ck_assert_int_eq(convert_to_arabic("X"), 10);
 }
END_TEST

START_TEST(it_converts_XX_to_20)
 {
   ck_assert_int_eq(convert_to_arabic("X"), 10);
 }
END_TEST

START_TEST(it_converts_L_to_50)
 {
   ck_assert_int_eq(convert_to_arabic("L"), 50);
 }
END_TEST

START_TEST(it_converts_C_to_100)
 {
   ck_assert_int_eq(convert_to_arabic("C"), 100);
 }
END_TEST

START_TEST(it_converts_CC_to_200)
 {
   ck_assert_int_eq(convert_to_arabic("CC"), 200);
 }
END_TEST

START_TEST(it_converts_D_to_500)
 {
   ck_assert_int_eq(convert_to_arabic("D"), 500);
 }
END_TEST

START_TEST(it_converts_M_to_1000)
 {
   ck_assert_int_eq(convert_to_arabic("M"), 1000);
 }
END_TEST

START_TEST(it_converts_MM_to_2000)
 {
   ck_assert_int_eq(convert_to_arabic("MM"), 2000);
 }
END_TEST

START_TEST(it_converts_IV_to_4)
 {
   ck_assert_int_eq(convert_to_arabic("IV"), 4);
 }
END_TEST

START_TEST(it_converts_IX_to_9)
 {
   ck_assert_int_eq(convert_to_arabic("IX"), 9);
 }
END_TEST

START_TEST(it_converts_XL_to_40)
 {
   ck_assert_int_eq(convert_to_arabic("XL"), 40);
 }
END_TEST

START_TEST(it_converts_XC_to_90)
 {
   ck_assert_int_eq(convert_to_arabic("XC"), 90);
 }
END_TEST

START_TEST(it_converts_CD_to_400)
 {
   ck_assert_int_eq(convert_to_arabic("CD"), 400);
 }
END_TEST

START_TEST(it_converts_CM_to_900)
 {
   ck_assert_int_eq(convert_to_arabic("CM"), 900);
 }
END_TEST

Suite * to_arabic_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("ConvertToArabicSuite");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_converts_I_to_1);
  tcase_add_test(tc_core, it_converts_II_to_2);
  tcase_add_test(tc_core, it_converts_V_to_5);
  tcase_add_test(tc_core, it_converts_X_to_10);
  tcase_add_test(tc_core, it_converts_XX_to_20);
  tcase_add_test(tc_core, it_converts_L_to_50);
  tcase_add_test(tc_core, it_converts_C_to_100);
  tcase_add_test(tc_core, it_converts_CC_to_200);
  tcase_add_test(tc_core, it_converts_D_to_500);
  tcase_add_test(tc_core, it_converts_M_to_1000);
  tcase_add_test(tc_core, it_converts_MM_to_2000);

  // numerals involving RN subtraciton rules
  tcase_add_test(tc_core, it_converts_IV_to_4);
  tcase_add_test(tc_core, it_converts_IX_to_9);
  tcase_add_test(tc_core, it_converts_XL_to_40);
  tcase_add_test(tc_core, it_converts_XC_to_90);
  tcase_add_test(tc_core, it_converts_CD_to_400);
  tcase_add_test(tc_core, it_converts_CM_to_900);

  suite_add_tcase(s, tc_core);

  return s;
}
