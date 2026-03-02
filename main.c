#include <stdio.h>
#include "stack.h"

int main(){
	
	Stack s;
	init_stack(&s, sizeof(char), 10);
	
	for(char c = 'a'; c < 'f'; c++){
		stack_push(&s, &c);
	}
	
	for(int i = s.top; i >= 0; i--){
		
		void* pc = stack_pop(&s);
		printf("%c ", *((char*)pc));
	}
	printf("\n");
	
	delete_stack(&s);
	
	return 0;
}