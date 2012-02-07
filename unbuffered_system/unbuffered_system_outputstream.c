#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../outputstream.h"

struct outputstream_t {
  int fd;
};

outputstream *create_output_stream(char* filename) {
  struct outputstream_t *s = malloc(sizeof(struct outputstream_t));
  s->fd = open(filename, O_WRONLY | O_CREAT);
  if (s->fd < 0) {
    printf("Could not write to file '%s' (%d)\n", filename, s->fd);
    exit(1);
  }
  return s;
}

void write_stream(outputstream *s, int datum) {
  int retval = write(s->fd, &datum, sizeof(int));

  if (retval != sizeof(int)) {
    printf("Could not write to output stream (%d)\n", retval);
    exit(1);
  }
}

void close_stream(outputstream *s) {
  close(s->fd);
}
