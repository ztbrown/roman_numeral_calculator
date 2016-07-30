#include <stdlib.h>
#include <string.h>
#include "converter.h"

int convert_to_arabic(char *roman_numeral)
{
  int result = 0;

  for (int i = 0; i < (sizeof(roman_numeral) / sizeof(roman_numeral[0])); i++){
    if (roman_numeral[i] == 'I'){
      result += 1;
    } else if (roman_numeral[i] == 'V'){
      result += 5;
    } else if (roman_numeral[i] == 'X'){
      result += 10;
    } else if (roman_numeral[i] == 'L'){
      result += 50;
    }
  }

  return result;
}
