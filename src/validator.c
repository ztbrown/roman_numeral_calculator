#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "validator.h"

regex_t regex;
int reti;

int is_null_or_empty(const char *input);

int validate(const char *input) {
  // return 0 on success
  int return_value = 1;

  reti = regcomp(&regex, "^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", REG_EXTENDED);
  if (reti || is_null_or_empty(input)) {
    return 1;
  }

  reti = regexec(&regex, input, 0, NULL, 0);
  if (!reti) {
    return_value = 0;
  }

  regfree(&regex);

  return return_value;
}

int is_null_or_empty(const char *input)
{
  return input == NULL || strlen(input) == 0;
}
