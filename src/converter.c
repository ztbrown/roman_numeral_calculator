#include <stdlib.h>
#include <string.h>
#include "converter.h"

int convert_to_arabic(char *number)
{
  int result = 0;
  char roman_numeral[512];

  strcpy(roman_numeral, number);

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

void extract_ones(char **numeral)
{
  *(*numeral) = 'I';
  *numeral += 1;
}

void extract_fives(char **numeral)
{
  *(*numeral) = 'V';
  *numeral += 1;
}

void (*numeral_operation[2])(char ** numeral) = {extract_fives, extract_ones};

char * convert_from_arabic(int number)
{
  // longest standard roman numeral is 15 characters
  char * result = malloc(16 * sizeof(char));
  char * ptr = result;

  int chunk[2] = {5, 1};

  int i;

  for(i = 0; i < 2; i++){
    int count = (number / chunk[i]);
    if (count > 0){
      number -= (count * chunk[i]);
      while(count--)
        (numeral_operation[i])(&ptr);
    }
  }

  *ptr++ = '\0';

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
