#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../inputstream.h"

struct inputstream_t {
  FILE *fp;
};

inputstream *open_input_stream(char* filename) {
  struct inputstream_t *s = malloc(sizeof(struct inputstream_t));
  s->fp = fopen(filename, "r");
  if (s->fp == NULL) {
    printf("Could not open input stream for file '%s' (%d)\n", filename, errno);
    exit(1);
  }
  return s;
}

int read_next(inputstream *s) {
  int temp = 0;
  int retval = fread(&temp, sizeof(int), 1, s->fp);
  if (ferror(s->fp)) {
    printf("Could not read from input stream (%d)\n", ferror(s->fp));
    exit(1);
  }
  return temp;
}

int end_of_stream(inputstream *s) {
  return feof(s->fp);
}
