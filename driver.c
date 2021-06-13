#include <stdio.h>
#include "pipe.h"

int main() {

  // This will work on default settings with GCC compiler
  // For those who are using standard C, put these functions
  // outside of main
  int add(int x){ return x + 5; };
  int mult(int x){ return x * 3; };
  int div(int x){ return x / 3; };

  int (*funcs[])(int) = {&add, &mult, &div, NULL};

  int (*doStuff)(int) = (int*)pipe(funcs);
  printf("result: %d\n", doStuff(4));

  return 0;
}
