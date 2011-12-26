typedef struct stream_t stream;

stream *open(char* filename);
int next(stream* s);
int eof(stream* s);
