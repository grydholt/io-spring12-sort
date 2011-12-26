#include <stdio.h>
#include <stdlib.h>
#include "../inputstream.h"

struct stream_t {
  FILE *fp;
};

stream *open(char* filename) {
  struct stream_t *stream = malloc(sizeof(struct stream_t));
  FILE *fp = fopen(filename, "r");
  stream->fp = fp;
  return stream;
}

