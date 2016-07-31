#include <stdlib.h>
#include "converter.h"
#include "calculator.h"

char * add(char *a, char *b) {
  return convert_from_arabic(convert_to_arabic(a) + convert_to_arabic(b));
}
