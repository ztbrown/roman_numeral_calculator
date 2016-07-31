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

void extract(char **numeral, char nums[2], int num_size)
{
  for(int i = 0; i < num_size; i++){
    *(*numeral) = nums[i];
    *numeral += 1;
  }
}

void extract_ones(char **numeral)
{
  char nums[1] = {'I'};
  extract(numeral, nums, 1);
}

void extract_fours(char **numeral)
{
  char nums[2] = {'I', 'V'};
  extract(numeral, nums, 2);
}

void extract_fives(char **numeral)
{
  char nums[1] = {'V'};
  extract(numeral, nums, 1);
}

void extract_tens(char **numeral)
{
  char nums[1] = {'X'};
  extract(numeral, nums, 1);
}

void extract_forties(char **numeral)
{
  char nums[2] = {'X', 'L'};
  extract(numeral, nums, 2);
}

void extract_fifties(char **numeral)
{
  char nums[1] = {'L'};
  extract(numeral, nums, 1);
}

void extract_nineties(char **numeral)
{
  char nums[2] = {'X', 'C'};
  extract(numeral, nums, 2);
}

void extract_hundreds(char **numeral)
{
  char nums[1] = {'C'};
  extract(numeral, nums, 1);
}

void (*numeral_operation[8])(char ** numeral) = {
  extract_hundreds,
  extract_nineties,
  extract_fifties,
  extract_forties,
  extract_tens,
  extract_fives,
  extract_fours,
  extract_ones
};

char * convert_from_arabic(int number)
{
  // longest standard roman numeral is 15 characters
  char * result = malloc(16 * sizeof(char));
  char * ptr = result;

  int chunk[8] = {100, 90, 50, 40, 10, 5, 4, 1};

  int i;

  for(i = 0; i < sizeof(chunk)/sizeof(int); i++){
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
