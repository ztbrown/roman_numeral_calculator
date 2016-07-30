#include <stdlib.h>
#include <string.h>
#include "converter.h"

int convert_to_arabic(char *arg)
{
  int result = 0;
  char roman_numeral[512];

  strcpy(roman_numeral, arg);

  rewrite_to_ignore_subtraction_rules(roman_numeral);

  for (int i = 0; roman_numeral[i]; i++){
    if (roman_numeral[i] == 'I'){
      result += 1;
    } else if (roman_numeral[i] == 'V'){
      result += 5;
    } else if (roman_numeral[i] == 'X'){
      result += 10;
    } else if (roman_numeral[i] == 'L'){
      result += 50;
    } else if (roman_numeral[i] == 'C'){
      result += 100;
    } else if (roman_numeral[i] == 'D'){
      result += 500;
    } else if (roman_numeral[i] == 'M'){
      result += 1000;
    }
  }

  return result;
}

void rewrite_to_ignore_subtraction_rules(char *roman_numeral)
{
	const char * const patterns[] = {"CM", "CD", "XC", "XL", "IX", "IV"};
	const char * const repl[] = {"DCD", "CCCC", "LXL", "XXXX", "VIV", "IIII"};
	int i;

	for (i = 0; i < (sizeof(patterns)/sizeof(patterns[0])); i++)
		gsub(roman_numeral, patterns[i], repl[i]);
}

void gsub(char *str, const char *pattern, const char *repl)
{
	char *sub_ptr, *p2, *p3;
	char temp[2048];
	const char *repl_ptr;

	while((sub_ptr = strstr(str, pattern)))
	{
		// reset pointers
		p3 = temp;
	  repl_ptr = repl;

		// get pointer to address following replacement
		p2 = sub_ptr + (strlen(pattern));

		// copy after pattern to temp
		while((*p3++ = *p2++));

		// str cpy
		while((*sub_ptr++ = *repl_ptr++));

		strcat(str, temp);
	}
}
