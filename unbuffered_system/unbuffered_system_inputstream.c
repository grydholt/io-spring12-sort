#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inputstream.h"

struct inputstream_t {
  int fd;
  int eof;
};

inputstream *open_input_stream(char* filename) {
  struct inputstream_t *s = malloc(sizeof(struct inputstream_t));
  s->fd = open(filename, O_RDONLY);
  if (s->fd < 0) {
    printf("Could not open input stream for file '%s' (%d)\n", filename, s->fd);
    exit(1);
  }
  s->eof = 0;
  return s;
}

int read_next(inputstream *s) {
  int temp = 0;
  int retval = read(s->fd, &temp, sizeof(int));
  if (retval < 0) {
    printf("Could not read from input stream (%d)\n", retval);
    exit(1);
  }
  s->eof = retval == 0;
  return temp;
}

int end_of_stream(inputstream *s) {
  return s->eof;
}
