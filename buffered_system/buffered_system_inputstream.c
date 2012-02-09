#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inputstream.h"

#define BUFFER_SIZE 1024

struct inputstream_t {
  int fd;
  int last;
  int buffer[BUFFER_SIZE];
  uint position;
};

inputstream *open_input_stream(char* filename) {
  struct inputstream_t *s = malloc(sizeof(struct inputstream_t));
  s->fd = open(filename, O_RDONLY);
  if (s->fd < 0) {
    printf("Could not open input stream for file '%s' (%d)\n", filename, s->fd);
    exit(1);
  }
  s->last = 0;
  s->position = 0;
  return s;
}

int read_next(inputstream *s) {
  int temp = 0;
  if (s->position % BUFFER_SIZE == 0) {
      int retval = read(s->fd, s->buffer, sizeof(int) * BUFFER_SIZE);
      if (retval < 0) {
	printf("Could not read from input stream (%d)\n", retval);
	exit(1);
      }
      s->last = BUFFER_SIZE - retval/sizeof(int);
    }
  return s->buffer[s->position++];
}

int end_of_stream(inputstream *s) {
  return s->last && BUFFER_SIZE - s->last < s->position % BUFFER_SIZE;
}
