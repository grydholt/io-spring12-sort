#ifndef OUTPUTSTREAM_HEADER_SEEN
#define OUTPUTSTREAM_HEADER_SEEN

typedef struct outputstream_t outputstream;

outputstream *create_output_stream(char* filename);
void write_stream(outputstream* s, int datum);
void close_stream(outputstream* s);

#endif /* !OUTPUTSTREAM_HEADER_SEEN */
