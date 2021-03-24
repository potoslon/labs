#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#ifdef vector1
#include "vector.h"
#endif

#ifdef list1
#include "list.h"
#endif

typedef struct Stack {
    velist* l;
} Stack;

Stack *stack_new();
void stack_delete(Stack *stack);
int stack_push(Stack *stack, char* data);
int stack_pop(Stack *stack, char **output);
void stack_print(const Stack *stack);

#endif // VECTOR_H_INCLUDED


