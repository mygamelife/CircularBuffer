#ifndef CircularBuffer_H
#define CircularBuffer_H

typedef enum {ERR_NO_ERROR, 
			  ERR_BUFFER_IS_FULL,
			  ERR_BUFFER_IS_EMPTY
			 } ErrorCode;

typedef struct 
{
	int *head;
	int *tail;
	int size;
	int length;
	int *buffer;
}CircularBuffer;

CircularBuffer *circularBufferNew(int length);
void circularBufferAdd(CircularBuffer *cb, int value);
int circularBufferRemove(CircularBuffer *cb);
void circularBufferDel(CircularBuffer *circularBuffer);

#endif // CircularBuffer_H
