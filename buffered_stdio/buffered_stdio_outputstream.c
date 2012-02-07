#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../outputstream.h"

struct outputstream_t {
  FILE *fp;
};

outputstream *create_output_stream(char* filename) {
  struct outputstream_t *s = malloc(sizeof(struct outputstream_t));
  s->fp = fopen(filename, "w");
  if (s->fp == NULL) {
    printf("Could not write to file '%s'\n", filename);
    exit(1);
  }
  return s;
}

void write_stream(outputstream *s, int datum) {
  int retval = fwrite(&datum, sizeof(int), 1, s->fp);
  if (retval != 1) {
    printf("Could not write to output stream (%d)\n", retval);
    exit(1);
  }
}

void close_stream(outputstream *s) {
  fclose(s->fp);
}
