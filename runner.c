#include <stdio.h>
#include <stdlib.h>
#include "inputstream.h"

int main() {
  stream* stream = open("hello");
  printf("Hello World\n");
  free(stream);
}
