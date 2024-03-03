#include "stack.h"

#include <stdio.h>

int main() {
    Stack* stack = stack_create(10);

    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);

    stack_print(stack);
    printf("Stack size: %d\n", stack_size(stack));

    printf("Stack peek: ");
    element_print(stack_peek(stack));
    printf("\n");

    printf("Stack pop: ");
    element_print(stack_pop(stack));
    printf("\n");
    stack_print(stack);


    printf("Stack size: %d\n", stack_size(stack));

    stack_destroy(stack);

    return 0;
}