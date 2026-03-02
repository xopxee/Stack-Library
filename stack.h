#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	void* data;
	size_t element_size;
	int top;
	int size;
	
}Stack;

void init_stack(Stack* ps, size_t element_size, int size);

void stack_push(Stack* ps, void* data);

void* stack_pop(Stack* ps);

bool is_empty(Stack s);

bool is_full(Stack s);

void delete_stack(Stack* ps);

#endif
