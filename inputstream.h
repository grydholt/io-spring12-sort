#ifndef INPUTSTREAM_HEADER_SEEN
#define INPUTSTREAM_HEADER_SEEN

typedef struct inputstream_t inputstream;

inputstream *open_input_stream(char* filename);
int read_next(inputstream* s);
int end_of_stream(inputstream* s);

#endif /* !INPUTSTREAM_HEADER_SEEN */
