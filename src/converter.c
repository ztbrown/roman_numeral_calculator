#include <stdlib.h>
#include <string.h>
#include "converter.h"

static void substitute(char *str, const char *pattern, const char *replacement);
static void rewrite_subtraction(char *roman_numeral);
static void add_to_buffer(char nums[2], int size, char ** ptr);
static int arabic_value(char roman_value);

static const int MAX_ROMAN_NUMERAL_SIZE = 16;

struct conversion_table {
    char arr[2];
    size_t len;
    int value;
};

int convert_to_arabic(const char *number)
{
  int result = 0;
  char roman_numeral[MAX_ROMAN_NUMERAL_SIZE];

  strcpy(roman_numeral, number);

  rewrite_subtraction(roman_numeral);

  for (int i = 0; roman_numeral[i]; i++){
    result += arabic_value(roman_numeral[i]);
  }

  return result;
}

char * convert_from_arabic(int number, char * result)
{
  // longest standard roman numeral is 15 characters
  //char * result = malloc(MAX_ROMAN_NUMERAL_SIZE * sizeof(char));
  char * ptr = result;

  struct conversion_table roman_conv[13] = {
    {{'M'}, 1, 1000},
    {{'C', 'M'}, 2, 900},
    {{'D'}, 1, 500},
    {{'C','D'}, 2, 400},
    {{'C'}, 1, 100},
    {{'X','C'}, 2, 90},
    {{'L'}, 1, 50},
    {{'X','L'}, 2, 40},
    {{'X'}, 1, 10},
    {{'I', 'X'}, 2, 9},
    {{'V'}, 1, 5},
    {{'I','V'}, 2, 4},
    {{'I'}, 1, 1}
  };

  for(int i = 0; i < sizeof(roman_conv)/sizeof(roman_conv[0]); i++){
    int count = (number / roman_conv[i].value);
    if (count > 0){
      number -= (count * roman_conv[i].value);
      while(count--){
        add_to_buffer(roman_conv[i].arr, roman_conv[i].len, &ptr);
      }
    }
  }

  *ptr++ = '\0';

  return result;
}

static void add_to_buffer(char nums[2], int size, char ** numeral)
{
    for(int i = 0; i < size; i++){
      *(*numeral) = nums[i];
      *numeral += 1;
    }
}

static void rewrite_subtraction(char *roman_numeral)
{
	const char * const patterns[] = {"CM", "CD", "XC", "XL", "IX", "IV"};
	const char * const replacement[] = {"DCD", "CCCC", "LXL", "XXXX", "VIV", "IIII"};
	int i;

	for (i = 0; i < (sizeof(patterns)/sizeof(patterns[0])); i++)
		substitute(roman_numeral, patterns[i], replacement[i]);
}

static void substitute(char *str, const char *pattern, const char *replacement)
{
	char *sub_ptr, *p2, *p3;
	char temp[MAX_ROMAN_NUMERAL_SIZE];
	const char *repl_ptr;

	while((sub_ptr = strstr(str, pattern)))
	{
		// reset pointers
		p3 = temp;
	  repl_ptr = replacement;

		// get pointer to address following replacement
		p2 = sub_ptr + (strlen(pattern));

		// copy after pattern to temp
    strcpy(p3, p2);
    strcpy(sub_ptr, repl_ptr);

		strcat(str, temp);
	}
}

static int arabic_value(char roman_value) {
  int val = 0;

  if (roman_value == 'I'){
    val = 1;
  } else if (roman_value == 'V'){
    val = 5;
  } else if (roman_value == 'X'){
    val = 10;
  } else if (roman_value == 'L'){
    val = 50;
  } else if (roman_value == 'C'){
    val = 100;
  } else if (roman_value == 'D'){
    val = 500;
  } else if (roman_value == 'M'){
    val = 1000;
  }

  return val;
}
