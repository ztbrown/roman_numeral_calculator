#include <stdlib.h>
#include <check.h>
#include "check_validator.h"
#include "../src/validator.h"

START_TEST(it_validates_I_and_returns_success)
{
  ck_assert_int_eq(validate("I"), 0);
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

START_TEST(it_validates_L_and_returns_success)
{
  ck_assert_int_eq(validate("L"), 0);
}
END_TEST

START_TEST(it_validates_LX_and_returns_success)
{
  ck_assert_int_eq(validate("LX"), 0);
}
END_TEST

START_TEST(it_validates_D_and_returns_success)
{
  ck_assert_int_eq(validate("D"), 0);
}
END_TEST

START_TEST(it_validates_empty_string_and_returns_failure)
{
  ck_assert_int_eq(validate(""), 1);
}
END_TEST

START_TEST(it_validates_NULL_and_returns_failure)
{
  ck_assert_int_eq(validate(NULL), 1);
}
END_TEST

START_TEST(it_validates_IIII_and_returns_failure)
{
  ck_assert_int_eq(validate("IIII"), 1);
}
END_TEST

START_TEST(it_validates_VIIII_and_returns_failure)
{
  ck_assert_int_eq(validate("VIIII"), 1);
}
END_TEST

START_TEST(it_validates_XXXX_and_returns_failure)
{
  ck_assert_int_eq(validate("XXXX"), 1);
}
END_TEST

START_TEST(it_validates_LXXXX_and_returns_failure)
{
  ck_assert_int_eq(validate("LXXXX"), 1);
}
END_TEST

START_TEST(it_validates_CCCC_and_returns_failure)
{
  ck_assert_int_eq(validate("CCCC"), 1);
}
END_TEST

START_TEST(it_validates_DCCCC_and_returns_failure)
{
  ck_assert_int_eq(validate("DCCCC"), 1);
}
END_TEST

START_TEST(it_validates_MMMM_and_returns_failure)
{
  ck_assert_int_eq(validate("MMMM"), 1);
}
END_TEST

START_TEST(it_validates_LL_and_returns_failure)
{
  ck_assert_int_eq(validate("LL"), 1);
}
END_TEST

START_TEST(it_validates_DD_and_returns_failure)
{
  ck_assert_int_eq(validate("DD"), 1);
}
END_TEST

START_TEST(it_validates_VV_and_returns_failure)
{
  ck_assert_int_eq(validate("VV"), 1);
}
END_TEST

Suite * validator_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Validation");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_validates_I_and_returns_success);
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
  tcase_add_test(tc_core, it_validates_L_and_returns_success);
  tcase_add_test(tc_core, it_validates_LX_and_returns_success);
  tcase_add_test(tc_core, it_validates_D_and_returns_success);
  tcase_add_test(tc_core, it_validates_empty_string_and_returns_failure);
  tcase_add_test(tc_core, it_validates_NULL_and_returns_failure);
  tcase_add_test(tc_core, it_validates_IIII_and_returns_failure);
  tcase_add_test(tc_core, it_validates_VIIII_and_returns_failure);
  tcase_add_test(tc_core, it_validates_XXXX_and_returns_failure);
  tcase_add_test(tc_core, it_validates_LXXXX_and_returns_failure);
  tcase_add_test(tc_core, it_validates_CCCC_and_returns_failure);
  tcase_add_test(tc_core, it_validates_DCCCC_and_returns_failure);
  tcase_add_test(tc_core, it_validates_MMMM_and_returns_failure);
  tcase_add_test(tc_core, it_validates_LL_and_returns_failure);
  tcase_add_test(tc_core, it_validates_VV_and_returns_failure);
  tcase_add_test(tc_core, it_validates_DD_and_returns_failure);

  suite_add_tcase(s, tc_core);

  return s;
}
