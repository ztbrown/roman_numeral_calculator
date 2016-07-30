#include <stdlib.h>
#include <check.h>
#include "check_roman.h"

START_TEST(zero_equals_one)
 {
   ck_assert_int_eq(0, 1);
 }
END_TEST

Suite * add_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("AddSuite");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, zero_equals_one);
  suite_add_tcase(s, tc_core);

  return s;
}
