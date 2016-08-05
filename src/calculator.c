#include <stdlib.h>
#include "converter.h"
#include "calculator.h"
#include "validator.h"

char * add(const char *a, const char *b, char * result)
{
  if (validate(a) == 0 && validate(b) == 0){
    convert_from_arabic(convert_to_arabic(a) + convert_to_arabic(b), result);
    if (validate(result) == 1 ){
      result = "Invalid Entry";
    }
  }

  return result;
}

char * subtract(const char *a, const char *b, char * result) {
  return convert_from_arabic(convert_to_arabic(a) - convert_to_arabic(b), result);
}
