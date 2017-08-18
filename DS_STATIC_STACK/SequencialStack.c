#include "SequencialStack.h"

struct stack {
    int quantity;
    struct student data[MAX];
};

Stack* create_stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack*));
    if (stack != NULL)
        stack->quantity = 0;
    return stack;
}

void free_stack(Stack* stack) {
    free(stack);
}

int size_stack(Stack* stack) {
    if (stack == NULL) return -1;
    return stack->quantity;
}

int is_full(Stack* stack) {
    if (stack == NULL) return -1;
    return (stack->quantity == MAX);
}

int is_empty(Stack* stack) {
    if (stack == NULL) return -1;
    return (stack->quantity == 0);
}

int insert_stack(Stack* stack, struct student student) {
    if (stack == NULL) return 0;
    if (is_full(stack)) return 0;
    stack->data[stack->quantity] = student;
    stack->quantity++;
    return 1;
}

int remove_stack(Stack* stack) {
    if (is_empty(stack)) return 0;
    stack->quantity--;
    return 1;
}

int search_stack(Stack* stack, struct student* student) {
    if (is_empty(stack)) return 0;
    *student = stack->data[stack->quantity-1];
    return 1;
}
