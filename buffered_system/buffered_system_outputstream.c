#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../outputstream.h"

#define BUFFER_SIZE 1024

struct outputstream_t {
  int fd;
  int buffer[BUFFER_SIZE];
  uint position;
};

outputstream *create_output_stream(char* filename) {
  struct outputstream_t *s = malloc(sizeof(struct outputstream_t));
  s->fd = open(filename, O_WRONLY | O_CREAT);
  if (s->fd < 0) {
    printf("Could not write to file '%s' (%d)\n", filename, s->fd);
    exit(1);
  }
  s->position = 0;
  return s;
}

void flush_output_stream(outputstream *s) {
  int retval = write(s->fd, s->buffer, sizeof(int) * s->position);
  if (retval != s->position * sizeof(int)) {
    printf("Could not write to output stream (%d)\n", retval);
    exit(1);
  }

}
void write_stream(outputstream *s, int datum) {
  s->buffer[s->position++] = datum;
  if (s->position % BUFFER_SIZE == 0) {
    flush_output_stream(s);
  }
}


void close_stream(outputstream *s) {
  flush_output_stream(s);
  close(s->fd);
}
