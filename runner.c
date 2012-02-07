#include <stdio.h>
#include <stdlib.h>
#include "inputstream.h"
#include "outputstream.h"

int main() {
  outputstream* os = create_output_stream("/tmp/test.bin");
  write_stream(os, 100);
  write_stream(os, 1000);
  close_stream(os);

  inputstream* is = open_input_stream("/tmp/test.bin");
  int value;

  value = read_next(is);
  while (!end_of_stream(is)) {
    printf("Hello World: %d\n", value);
    value = read_next(is);
  }

  free(is);
  free(os);
}
