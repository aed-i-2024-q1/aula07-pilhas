#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    Element *elements;
};

Stack* stack_create(int capacity) {
    Stack* stack = malloc(sizeof(Stack));

    stack->top = -1;
    stack->capacity = capacity;
    stack->elements = malloc(capacity * sizeof(Element));

    return stack;
}

void stack_destroy(Stack* stack) {
    free(stack->elements);
    free(stack);
}

bool stack_push(Stack* stack, Element value) {
    if (stack_is_full(stack)) {
        return false;
    }

    stack->elements[++stack->top] = value;

    return true;
}

Element stack_pop(Stack* stack) {
    if (stack_isEmpty(stack)) {
        return ELEMENT_NULL;
    }

    return stack->elements[stack->top--];
}

Element stack_peek(Stack* stack) {
    if (stack_isEmpty(stack)) {
        return ELEMENT_NULL;
    }

    return stack->elements[stack->top];
}

bool stack_isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool stack_is_full(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int stack_size(Stack* stack) {
    return stack->top + 1;
}

void stack_print(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        element_print(stack->elements[i]);
        printf(" ");
    }
    printf("\n");
}