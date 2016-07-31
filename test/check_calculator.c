#include <stdlib.h>
#include <check.h>
#include "check_calculator.h"
#include "../src/calculator.h"

START_TEST(it_adds_I_and_I_to_get_II)
 {
   char * result = add("I", "I");

   ck_assert_str_eq(result, "II");

   free(result);
 }
END_TEST

START_TEST(it_adds_III_and_I_to_get_IV)
 {
   char * result = add("III", "I");

   ck_assert_str_eq(result, "IV");

   free(result);
 }
END_TEST

START_TEST(it_adds_IV_and_I_to_get_V)
 {
   char * result = add("IV", "I");

   ck_assert_str_eq(result, "V");

   free(result);
 }
END_TEST

START_TEST(it_adds_III_and_VI_to_get_IX)
 {
   char * result = add("III", "VI");

   ck_assert_str_eq(result, "IX");

   free(result);
 }
END_TEST

START_TEST(it_adds_V_and_V_to_get_X)
 {
   char * result = add("V", "V");

   ck_assert_str_eq(result, "X");

   free(result);
 }
END_TEST

START_TEST(it_adds_IX_and_IX_to_get_XVIII)
 {
   char * result = add("IX", "IX");

   ck_assert_str_eq(result, "XVIII");

   free(result);
 }
END_TEST

START_TEST(it_adds_IV_and_IV_to_get_VIII)
 {
   char * result = add("IV", "IV");

   ck_assert_str_eq(result, "VIII");

   free(result);
 }
END_TEST

START_TEST(it_adds_X_and_XXX_to_get_XL)
 {
   char * result = add("X", "XXX");

   ck_assert_str_eq(result, "XL");

   free(result);
 }
END_TEST

START_TEST(it_adds_X_and_XL_to_get_L)
 {
   char * result = add("X", "XL");

   ck_assert_str_eq(result, "L");

   free(result);
 }
END_TEST

START_TEST(it_adds_L_and_XL_to_get_XC)
 {
   char * result = add("L", "XL");

   ck_assert_str_eq(result, "XC");

   free(result);
 }
END_TEST

START_TEST(it_adds_L_and_L_to_get_C)
 {
   char * result = add("L", "L");

   ck_assert_str_eq(result, "C");

   free(result);
 }
END_TEST

START_TEST(it_adds_XC_and_XC_to_get_CLXXX)
 {
   char * result = add("XC", "XC");

   ck_assert_str_eq(result, "CLXXX");

   free(result);
 }
END_TEST

START_TEST(it_adds_C_and_CCC_to_get_CD)
 {
   char * result = add("C", "CCC");

   ck_assert_str_eq(result, "CD");

   free(result);
 }
END_TEST

START_TEST(it_adds_CC_and_CCC_to_get_D)
 {
   char * result = add("CC", "CCC");

   ck_assert_str_eq(result, "D");

   free(result);
 }
END_TEST

START_TEST(it_adds_D_and_CD_to_get_CM)
 {
   char * result = add("D", "CD");

   ck_assert_str_eq(result, "CM");

   free(result);
 }
END_TEST

START_TEST(it_adds_D_and_D_to_get_M)
 {
   char * result = add("D", "D");

   ck_assert_str_eq(result, "M");

   free(result);
 }
END_TEST

START_TEST(it_can_handle_the_longest_standard_roman_numeral)
 {
   char * result = add("MMDCCCLXXXVIII", "M");

   ck_assert_str_eq(result, "MMMDCCCLXXXVIII");

   free(result);
 }
END_TEST

Suite * add_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("AddTwoNumbers");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_adds_I_and_I_to_get_II);
  tcase_add_test(tc_core, it_adds_III_and_I_to_get_IV);
  tcase_add_test(tc_core, it_adds_III_and_VI_to_get_IX);
  tcase_add_test(tc_core, it_adds_IV_and_I_to_get_V);
  tcase_add_test(tc_core, it_adds_V_and_V_to_get_X);
  tcase_add_test(tc_core, it_adds_IX_and_IX_to_get_XVIII);
  tcase_add_test(tc_core, it_adds_IV_and_IV_to_get_VIII);
  tcase_add_test(tc_core, it_adds_X_and_XXX_to_get_XL);
  tcase_add_test(tc_core, it_adds_X_and_XL_to_get_L);
  tcase_add_test(tc_core, it_adds_L_and_XL_to_get_XC);
  tcase_add_test(tc_core, it_adds_L_and_L_to_get_C);
  tcase_add_test(tc_core, it_adds_XC_and_XC_to_get_CLXXX);
  tcase_add_test(tc_core, it_adds_CC_and_CCC_to_get_D);
  tcase_add_test(tc_core, it_adds_C_and_CCC_to_get_CD);
  tcase_add_test(tc_core, it_adds_D_and_CD_to_get_CM);
  tcase_add_test(tc_core, it_adds_D_and_D_to_get_M);
  tcase_add_test(tc_core, it_can_handle_the_longest_standard_roman_numeral);

  suite_add_tcase(s, tc_core);

  return s;

}
