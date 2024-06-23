#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;

struct queue {
	int *data;
	ulong allocated_size;
	ulong curr_entries;
	ulong next_write_pos;
	ulong next_read_pos;
	ulong grow;
};

struct queue *queue_create(ulong allocate, ulong grow_t)
{
	struct queue *queue_t = (struct queue *) malloc (sizeof(struct queue));
	queue_t->data=(int *)malloc (sizeof(int));
	queue_t->allocated_size=allocate;
	queue_t->curr_entries=0;
	queue_t->next_write_pos=0;
	queue_t->next_read_pos=0;
	queue_t->grow=grow_t;

	return queue_t;
}

void queue_delete(struct queue *queue_t)
{
	free(queue_t->data);
	free(queue_t);
}

ulong queue_elements(struct queue *queue_t){
	return queue_t->curr_entries;
}

ulong push(struct queue *queue_t, int data)
{
	if(queue_t->curr_entries >= queue_t->allocated_size)
	{
		if(queue_t->grow == 0)
		{
			return 0;
		}
		ulong new_size = queue_t->allocated_size + queue_t->grow;
		int *new_x = (int *)malloc(new_size*sizeof(int));
		for(ulong i=0; i < queue_t->curr_entries; ++i){
			new_x[i] = queue_t->data[(queue_t->next_read_pos+i)%queue_t->allocated_size];
		}
		free(queue_t->data);
		queue_t->data=new_x;
		queue_t->allocated_size=new_size;
		queue_t->next_write_pos=queue_t->curr_entries;
		queue_t->next_read_pos=0;
	}
	queue_t->data[queue_t->next_write_pos] = data;
	queue_t->next_write_pos = (queue_t->next_write_pos+1)%queue_t->allocated_size;
	queue_t->curr_entries++;
	return queue_t->curr_entries;
}

ulong peak(struct queue *queue_t, int *element)
{
	if(queue_t->curr_entries==0)
	{
		return 0;
	}
	*element = queue_t->data[queue_t->next_read_pos];
	return queue_t->curr_entries;
}

ulong pop(struct queue *queue_t, int *element)
{
	ulong ret = queue_t->curr_entries;
	if(queue_t->curr_entries!=0)
	{
		*element = queue_t->data[queue_t->next_read_pos];
		queue_t->next_read_pos = (queue_t->next_read_pos+1)%queue_t->allocated_size;
		queue_t->curr_entries--;
	}
	return ret;
}

void display_data(struct queue *queue_t){
	for(int i=0; i<queue_t->curr_entries; i++){
		printf("Queue data[%d]=%d\n",i,queue_t->data[i]);
	}
}

int main(int argc, char *argv[])
{
	int val;
	struct queue *queue_var = queue_create(5,3);
	push(queue_var, 1);
	push(queue_var, 2);
	push(queue_var, 3);
	display_data(queue_var);
	push(queue_var, 4);
	push(queue_var, 5);
	display_data(queue_var);
	pop(queue_var,&val);
	display_data(queue_var);
	pop(queue_var,&val);
	display_data(queue_var);
	queue_delete(queue_var);
	return 0;
}
