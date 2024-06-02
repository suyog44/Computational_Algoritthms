#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	size_t size;
	size_t top;
	size_t grow;
}Stack;

void 
stack_init(Stack *stack, size_t initial_size, size_t grow)
{
	stack->data = (int *) malloc (initial_size * sizeof(int));
	stack->size = initial_size;
	stack->top = 0;
	stack->grow = grow;
}

void 
stack_destroy(Stack *stack)
{
	free(stack->data);
}

void 
stack_grow(Stack *stack)
{
	stack->size += stack->grow;
	stack->data = (int *)realloc(stack->data, stack->size * sizeof(int));
}

int 
stack_push(Stack *stack, int *data)
{
	if(stack->top >= stack->size){
		if(stack->grow == 0 ){
			return 0;
		}
		stack_grow(stack);	
	}
	stack->data[stack->top] = *data;
	printf("Pushed: %02d\n", stack->data[stack->top]);
	stack->top = stack->top+1;
	return stack->size;
}

int 
stack_pop(Stack *stack, int *data)
{
	if(stack->top==0)
		return 0;
	*data = stack->data[--stack->top];
	return stack->top+1;
}

int
stack_peek(Stack *stack, int *data)
{
	if(stack->top == 0)
		return 0;
	*data = stack->data[stack->top-1];
	return stack->top;
}

int
stack_poke(Stack *stack, int *data)
{
	if(stack->top == 0)
		return 0;
	stack->data[stack->top-1] = *data;
	return stack->top;
}

int
main(int argc, char **argv)
{
	Stack stack;
	stack_init(&stack, 4, 4);
	printf("Stack init: %x %d %d %d\n", stack.data, stack.size, stack.top, stack.grow);

	int data = 10;
	int data1 = 1;
	int data2 = 1;
	int data3 = 1;
	int data4 = 1;
	stack_push(&stack, &data);
	stack_push(&stack, &data1);
	stack_push(&stack, &data2);
	stack_push(&stack, &data3);
	stack_push(&stack, &data4);

	int val;
	printf("Stack Top: %d Stack Peek: %d\n", stack_peek(&stack, &val), val);
	int val2 = 121;
	stack_poke(&stack, &val2);

	int value;
	for(int i=0;i<5;i++){
		stack_pop(&stack, &value);
		printf("Poped: %02d\n", value);
	}

	return 0;
}
