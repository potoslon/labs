#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#ifdef vector1
#include "vector.h"
#endif

#ifdef list1
#include "list.h"
#endif


Stack *stack_new() {
    velist* l = velist_new();
    Stack* s = calloc(1, sizeof(Stack));
    s->l = l;
    return s;
}

void stack_delete(Stack *stack) {
    velist_delete(stack->l);
    free(stack);
}

int stack_push(Stack *stack, char* data) {
    int n = velist_push_forward(stack->l, data);
    return n;
}

int stack_pop(Stack *stack, char **output) {
    *output = velist_get(stack->l);
    if(*output){
        velist_remove(stack->l, *output);
        return 0;
    }
    return -1;
}

void stack_print(const Stack *stack) {
    velist_print(stack->l);
}
