#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"

int count_from_files(int count, ...);

int main(int argc, char const *argv[]) {
  printf("%d\n",count_from_files(3, "blah.txt", "new.txt", "smth.txt"));

  return 0;
}

int count_from_files(int count, ...) {
  va_list arg;
  char* i;
  char* s;
  int number_of_words = 0;
  FILE* file;
  va_start(arg, count);
  for (size_t j = 0; j < count; j++) {
    i = va_arg(arg, char*);
    file = fopen(i, "r");
    while (fscanf(file, "%s", &s) != EOF) {
      number_of_words++;
    }
    fclose(file);
  }
  va_end(arg);
  return number_of_words;
}
