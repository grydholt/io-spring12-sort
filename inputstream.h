#ifndef INPUTSTREAM_HEADER_SEEN
#define INPUTSTREAM_HEADER_SEEN

typedef struct stream_t stream;

stream *open(char* filename);
int next(stream* s);
int eos(stream* s);

#endif /* !INPUTSTREAM_HEADER_SEEN */
