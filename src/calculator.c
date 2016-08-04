#include <stdlib.h>
#include "converter.h"
#include "calculator.h"

char * add(const char *a, const char *b, char * result) {
  return convert_from_arabic(convert_to_arabic(a) + convert_to_arabic(b), result);
}

char * subtract(const char *a, const char *b, char * result) {
  return convert_from_arabic(convert_to_arabic(a) - convert_to_arabic(b), result);
}
