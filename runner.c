#include <stdio.h>
#include <stdlib.h>
#include "inputstream.h"

int main() {
  stream* s = open("testdata/inputfile.txt");
  int value;

  while (!eos(s)) {
    value = next(s);
    printf("Hello World: %d\n", value);
  }
  free(s);
}
