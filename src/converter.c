#include <stdlib.h>
#include <string.h>
#include "converter.h"

int convert_to_arabic(char *roman_numeral)
{
  int result = 0;

  for (int i = 0; i < (sizeof(roman_numeral) / sizeof(roman_numeral[0])); i++){
    if (roman_numeral[i] == 'I'){
      result += 1;
    }
  }

  return result;
}
