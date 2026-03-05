#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//Pop, print (precisaria de mais informaçoes de tipo (um struct talvez)??)

void init_stack(Stack* ps, size_t element_size, int size){
	
	//Initialization of stack fields.
	ps->top = -1;
	ps->size = size;
	ps->element_size = element_size;
	
	//Allocates memory according to the data size;
	ps->data = malloc(element_size * size);
	
	if(ps->data == NULL){
		perror("Failed to allocate memory");
		exit(1);
	}
}

void stack_push(Stack* ps, void* data){
	
	if(is_full_s(*ps)){
		perror("Stack Overflow");
		exit(1);
	}
	
	//Increments the top of the stack ctrl counter.
	ps->top++;
	
	//The address of the top of the stack, where the new data will be stored.
	void* ptop = & ((char*)ps->data)[ps->top * ps->element_size];
	
	//Copies the data to the top of the stack;
	memcpy(ptop, data, ps->element_size);
}

void* stack_pop(Stack* ps){
	
	if(is_empty_s(*ps)){
		return NULL;
	}
	
	//Pops the element at the top.
	void* ptop = & ((char*)ps->data)[ps->top * ps->element_size];
	ps->top--;
	
	//Returns it.
	return ptop;
}

bool is_empty_s(Stack s){
	return (s.top == -1)? true : false;
}

bool is_full_s(Stack s){
	return (s.top == s.size - 1)? true : false;
}

void delete_stack(Stack* ps){
	ps->top = -1;
	ps->size = -1;
	
	free(ps->data);
	ps->data = NULL;
}