#include <stdlib.h>
#include <check.h>
#include "check_roman.h"
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

Suite * convert_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("ConvertSuite");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_converts_I_to_1);
  tcase_add_test(tc_core, it_converts_II_to_2);
  tcase_add_test(tc_core, it_converts_V_to_5);
  tcase_add_test(tc_core, it_converts_X_to_10);
  tcase_add_test(tc_core, it_converts_XX_to_20);
  suite_add_tcase(s, tc_core);

  return s;
}
