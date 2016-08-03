#ifndef CONVERTER_H
#define CONVERTER_H

// 'public' interface
int convert_to_arabic(const char *number);
char * convert_from_arabic(int number);

// internal functions
void gsub(char *str, const char *pattern, const char *repl);
void rewrite_to_ignore_subtraction_rules(char *roman_numeral);
void extract(char **numeral, char nums[2], int num_size);
void add_to_buffer(char nums[2], int size, char ** ptr);

struct conversion_table {
    char arr[2];
    size_t len;
};

#endif
