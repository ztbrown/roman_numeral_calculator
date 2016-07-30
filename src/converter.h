#ifndef CONVERTER_H
#define CONVERTER_H

int convert_to_arabic(char *number);
char * convert_from_arabic(int number); 
void gsub(char *str, const char *pattern, const char *repl);
void rewrite_to_ignore_subtraction_rules(char *roman_numeral);

#endif
