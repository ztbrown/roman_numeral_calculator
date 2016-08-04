#include <stdlib.h>
#include <check.h>
#include "check_calculator.h"
#include "../src/calculator.h"

START_TEST(it_adds_I_and_I_to_get_II)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("I", "I", result), "II");

   free(result);
 }
END_TEST

START_TEST(it_adds_III_and_I_to_get_IV)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("III", "I", result), "IV");

   free(result);
 }
END_TEST

START_TEST(it_adds_IV_and_I_to_get_V)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("IV", "I", result), "V");

   free(result);
 }
END_TEST

START_TEST(it_adds_III_and_VI_to_get_IX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("III", "VI", result), "IX");

   free(result);
 }
END_TEST

START_TEST(it_adds_V_and_V_to_get_X)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("V", "V", result), "X");

   free(result);
 }
END_TEST

START_TEST(it_adds_IX_and_IX_to_get_XVIII)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("IX", "IX", result), "XVIII");

   free(result);
 }
END_TEST

START_TEST(it_adds_IV_and_IV_to_get_VIII)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("IV", "IV", result), "VIII");

   free(result);
 }
END_TEST

START_TEST(it_adds_X_and_XXX_to_get_XL)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("X", "XXX", result), "XL");

   free(result);
 }
END_TEST

START_TEST(it_adds_X_and_XL_to_get_L)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("X", "XL", result), "L");

   free(result);
 }
END_TEST

START_TEST(it_adds_L_and_XL_to_get_XC)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("L", "XL", result), "XC");

   free(result);
 }
END_TEST

START_TEST(it_adds_L_and_L_to_get_C)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("L", "L", result), "C");

   free(result);
 }
END_TEST

START_TEST(it_adds_XC_and_XC_to_get_CLXXX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("XC", "XC", result), "CLXXX");

   free(result);
 }
END_TEST

START_TEST(it_adds_C_and_CCC_to_get_CD)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("C", "CCC", result), "CD");

   free(result);
 }
END_TEST

START_TEST(it_adds_CC_and_CCC_to_get_D)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("CC", "CCC", result), "D");

   free(result);
 }
END_TEST

START_TEST(it_adds_D_and_CD_to_get_CM)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("D", "CD", result), "CM");

   free(result);
 }
END_TEST

START_TEST(it_adds_D_and_D_to_get_M)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("D", "D", result), "M");

   free(result);
 }
END_TEST

START_TEST(it_can_handle_the_longest_standard_roman_numeral)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(add("MMDCCCLXXXVIII", "M", result), "MMMDCCCLXXXVIII");

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

START_TEST(it_subtracts_I_from_II_to_get_I)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("II", "I", result), "I");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_I_from_V_to_get_IV)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("V", "I", result), "IV");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_I_from_X_to_get_IX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("X", "I", result), "IX");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_IV_from_XIII_to_get_IX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("XIII", "IV", result), "IX");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_I_from_L_to_get_XLIX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("L", "I", result), "XLIX");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_I_from_C_to_get_XCIX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("C", "I", result), "XCIX");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_I_from_D_to_get_CDXCIX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("D", "I", result), "CDXCIX");

   free(result);
 }
END_TEST

START_TEST(it_subtracts_I_from_M_to_get_CMXCIX)
 {
   char * result = malloc(16 * sizeof(char));

   ck_assert_str_eq(subtract("M", "I", result), "CMXCIX");

   free(result);
 }
END_TEST

Suite * subtract_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("SubtractTwoNumbers");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, it_subtracts_I_from_II_to_get_I);
  tcase_add_test(tc_core, it_subtracts_I_from_V_to_get_IV);
  tcase_add_test(tc_core, it_subtracts_I_from_X_to_get_IX);
  tcase_add_test(tc_core, it_subtracts_I_from_L_to_get_XLIX);
  tcase_add_test(tc_core, it_subtracts_IV_from_XIII_to_get_IX);
  tcase_add_test(tc_core, it_subtracts_I_from_C_to_get_XCIX);
  tcase_add_test(tc_core, it_subtracts_I_from_D_to_get_CDXCIX);
  tcase_add_test(tc_core, it_subtracts_I_from_M_to_get_CMXCIX);

  suite_add_tcase(s, tc_core);

  return s;

}
