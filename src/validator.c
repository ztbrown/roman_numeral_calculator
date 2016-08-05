#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "validator.h"

regex_t regex;
int reti;

int validate(const char *a) {
  // return 0 on success
  int return_value = 1;

  reti = regcomp(&regex, "^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", REG_EXTENDED);
  if (reti || strlen(a) == 0) {
    return 1;
  }

  reti = regexec(&regex, a, 0, NULL, 0);
  if (!reti) {
    return_value = 0;
  }

  regfree(&regex);

  return return_value;
}
