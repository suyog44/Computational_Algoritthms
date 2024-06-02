#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
	int *data;
	size_t size;
	size_t count;
	size_t writepos;
	size_t readpos;
}Ringbuffer;

Ringbuffer *create_ring_buffer(size_t size)
{
	Ringbuffer *rb = (Ringbuffer *)malloc(sizeof(Ringbuffer));
	rb->data = (int *)malloc(sizeof(int));
	rb->size = size;
	rb->count = 0;
	rb->writepos = 0;
	rb->readpos = 0;
}

void insert_ring_buffer(Ringbuffer *buf, int data)
{
	buf->data[buf->writepos] = data;
	buf->writepos = (buf->writepos+1)%buf->size;
	
	if(buf->count < buf->size){
		buf->count++;
	}
	else{
		buf->readpos = (buf->readpos+1)%buf->size;
	}
}

int read_ring_buffer(Ringbuffer *buf, size_t index, int *data)
{
	if(index >= buf->count)
		return -1; //Out of bound
	size_t pos = (buf->readpos+index)%buf->size;
	*data = buf->data[pos];
	return 0; //success
}

void destroy_ring_buffer(Ringbuffer *buf)
{
	free(buf->data);
	free(buf);
}

int
main(int argc, char **argv)
{
	Ringbuffer *buf = create_ring_buffer(4);
	insert_ring_buffer(buf, 'A');
	insert_ring_buffer(buf, 'B');
	insert_ring_buffer(buf, 'C');
	insert_ring_buffer(buf, 'D');

	int val;
	for(int i=0; i<buf->size; i++){
		read_ring_buffer(buf, i, &val);
		printf("Index: %d Data: %c\n", i, val);
	}
	
	insert_ring_buffer(buf, 'E');
	insert_ring_buffer(buf, 'F');
	insert_ring_buffer(buf, 'G');
	insert_ring_buffer(buf, 'H');
	printf("\n===============================\n");	
	for(int i=0; i<buf->size; i++){
		read_ring_buffer(buf, i, &val);
		printf("Index: %d Data: %c\n", i, val);
	}

	destroy_ring_buffer(buf);
	return 0;
}
