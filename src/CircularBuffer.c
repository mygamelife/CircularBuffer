#include <stdio.h>
#include <malloc.h>
#include "CException.h"
#include "CircularBuffer.h"

CircularBuffer *circularBufferNew(int length)
{
	CircularBuffer *circularBuffer;

	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
	circularBuffer->length = length;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer ;
	circularBuffer->tail = circularBuffer->buffer ;
	return circularBuffer;
}

void circularBufferAdd(CircularBuffer *cb, int value)
{
	int result;
	
	if(cb->size == cb->length) //buffer full if buffer size is equal buffer length
		Throw(ERR_BUFFER_IS_FULL);
	
	*cb->head = value;
	cb->head++; //head point to next location when new data come in
	cb->size++; //size increase 1 to indicate 1 new data come in
	
	if(cb->head == &cb->buffer[cb->length]) //if head is pointing the last location of buffer length
	{
		cb->head = &cb->buffer[0];
		/*head go back to buffer first location
		  head now is pointing to the first location address of buffer */
	}
}

int circularBufferRemove(CircularBuffer *cb)
{	
	if(cb->size == 0)//if tail is pointing last location
	{
		Throw(ERR_BUFFER_IS_EMPTY);
	}
		
	*cb->tail = 0;

	cb->tail++; 
	cb->size--; //decrease element size because 1 element is free
	
	if(cb->tail == &cb->buffer[cb->length])
	{
		cb->tail = cb->buffer;
	}
	
	return 1; //1 indicade successfully remove
	
}

void circularBufferDel(CircularBuffer *circularBuffer)
{
	free(circularBuffer);
}