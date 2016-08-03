#include <stdlib.h>
#include <check.h>
#include "check_validator.h"
#include "../src/validator.h"

START_TEST(it_validates_I_and_returns_success)
{
  ck_assert_int_eq(validate("I"), 0);
}
END_TEST

START_TEST(it_validates_IIII_and_returns_failure)
{
  ck_assert_int_eq(validate("IIII"), 1);
}
END_TEST

START_TEST(it_validates_II_and_returns_success)
{
  ck_assert_int_eq(validate("II"), 0);
}
END_TEST

START_TEST(it_validates_V_and_returns_success)
{
  ck_assert_int_eq(validate("V"), 0);
}
END_TEST

START_TEST(it_validates_VI_and_returns_success)
{
  ck_assert_int_eq(validate("VI"), 0);
}
END_TEST

START_TEST(it_validates_IV_and_returns_success)
{
  ck_assert_int_eq(validate("IV"), 0);
}
END_TEST

START_TEST(it_validates_IX_and_returns_success)
{
  ck_assert_int_eq(validate("IX"), 0);
}
END_TEST

START_TEST(it_validates_X_and_returns_success)
{
  ck_assert_int_eq(validate("X"), 0);
}
END_TEST

START_TEST(it_validates_XX_and_returns_success)
{
  ck_assert_int_eq(validate("XX"), 0);
}
END_TEST

START_TEST(it_validates_XXX_and_returns_success)
{
  ck_assert_int_eq(validate("XXX"), 0);
}
END_TEST

START_TEST(it_validates_XL_and_returns_success)
{
  ck_assert_int_eq(validate("XL"), 0);
}
END_TEST

START_TEST(it_validates_XC_and_returns_success)
{
  ck_assert_int_eq(validate("XC"), 0);
}
END_TEST

START_TEST(it_validates_C_and_returns_success)
{
  ck_assert_int_eq(validate("C"), 0);
}
END_TEST

START_TEST(it_validates_CC_and_returns_success)
{
  ck_assert_int_eq(validate("CC"), 0);
}
END_TEST

START_TEST(it_validates_CCC_and_returns_success)
{
  ck_assert_int_eq(validate("CCC"), 0);
}
END_TEST

START_TEST(it_validates_CD_and_returns_success)
{
  ck_assert_int_eq(validate("CD"), 0);
}
END_TEST

START_TEST(it_validates_CM_and_returns_success)
{
  ck_assert_int_eq(validate("CM"), 0);
}
END_TEST

START_TEST(it_validates_M_and_returns_success)
{
  ck_assert_int_eq(validate("M"), 0);
}
END_TEST

START_TEST(it_validates_MM_and_returns_success)
{
  ck_assert_int_eq(validate("MM"), 0);
}
END_TEST

START_TEST(it_validates_MMM_and_returns_success)
{
  ck_assert_int_eq(validate("MMM"), 0);
}
END_TEST

Suite * validator_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Validation");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_validates_I_and_returns_success);
  tcase_add_test(tc_core, it_validates_IIII_and_returns_failure);
  tcase_add_test(tc_core, it_validates_II_and_returns_success);
  tcase_add_test(tc_core, it_validates_V_and_returns_success);
  tcase_add_test(tc_core, it_validates_VI_and_returns_success);
  tcase_add_test(tc_core, it_validates_IV_and_returns_success);
  tcase_add_test(tc_core, it_validates_IX_and_returns_success);
  tcase_add_test(tc_core, it_validates_X_and_returns_success);
  tcase_add_test(tc_core, it_validates_XX_and_returns_success);
  tcase_add_test(tc_core, it_validates_XXX_and_returns_success);
  tcase_add_test(tc_core, it_validates_XL_and_returns_success);
  tcase_add_test(tc_core, it_validates_XC_and_returns_success);
  tcase_add_test(tc_core, it_validates_C_and_returns_success);
  tcase_add_test(tc_core, it_validates_CC_and_returns_success);
  tcase_add_test(tc_core, it_validates_CCC_and_returns_success);
  tcase_add_test(tc_core, it_validates_CD_and_returns_success);
  tcase_add_test(tc_core, it_validates_CM_and_returns_success);
  tcase_add_test(tc_core, it_validates_M_and_returns_success);
  tcase_add_test(tc_core, it_validates_MM_and_returns_success);
  tcase_add_test(tc_core, it_validates_MMM_and_returns_success);

  suite_add_tcase(s, tc_core);

  return s;
}
