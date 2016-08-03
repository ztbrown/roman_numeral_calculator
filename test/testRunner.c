#include <stdlib.h>
#include <check.h>
#include "check_to_arabic.h"
#include "check_from_arabic.h"
#include "check_calculator.h"
#include "check_validator.h"

int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = to_arabic_suite();

  sr = srunner_create(s);
  srunner_add_suite(sr, from_arabic_suite());
  srunner_add_suite(sr, add_suite());
  srunner_add_suite(sr, subtract_suite());
  srunner_add_suite(sr, validator_suite());

  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
