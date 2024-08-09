#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;

struct dqueue{
	int *data;
	ulong allocate_size;
	ulong curr_entries;
	ulong first_pos;
	ulong last_pos;
	ulong grow;
};

struct dqueue *dqueue_create(ulong size_of_queue, ulong grow){
	struct dqueue *dqueue_t = (struct dqueue *)malloc (sizeof(struct dqueue));
	dqueue_t->data = (int *)malloc(sizeof(int));
	dqueue_t->allocate_size=size_of_queue;
	dqueue_t->first_pos=0;
	dqueue_t->last_pos=0;
	dqueue_t->grow=grow;
	return dqueue_t;
}

void dqueue_destroy(struct dqueue *dqueue_t)
{
	free(dqueue_t->data);
	free(dqueue_t);
}

ulong dqueue_entries(struct dqueue *dqueue_t)
{
	return dqueue_t->curr_entries;
}

void grow_dqueue(struct dqueue *dqueue_t)
{
	ulong new_size = dqueue_t->allocate_siz
}

ulong dqueue_insert_first(struct dqueue *dqueue_t, int data)
{

}


