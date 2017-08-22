#include "DynamicStack.h"

struct element {
    struct student data;
    struct element* next;
};

Stack* create_stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack != NULL)
        *stack = NULL;
    return stack;
}

void free_stack(Stack* stack) {
    if (stack != NULL) {
        Stack* node;
        while ((*stack) != NULL) {
            node = (*stack);
            *stack = (*stack)->next;
            free(node);
        }
        free(stack);
    }
}

int size_stack(Stack* stack) {
    if (stack == NULL) return 0;
    Stack node = (*stack);
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

int is_full(Stack* stack) {
    return 0;
}

int is_empty(Stack* stack) {
    if (stack == NULL)
        return 1;
    if (*stack == NULL)
        return 1;
    return 0;
}

int insert(Stack* stack, struct student student) {
    if (stack == NULL) return 0;
    Stack node = (Stack) malloc(sizeof(Stack));
    if (node == NULL) return 0;
    node->data = student;
    node->next = (*stack);
    *stack = node;
    return 1;
}

int remove_element(Stack* stack) {
    if (is_empty(stack)) return 0;
    Stack node = *stack;
    *stack = node->next;
    free(node);
    return 1;
}

int search_data(Stack* stack, struct student* student) {
    if (is_empty(stack)) return 0;
    *student = (*stack)->data;
    return 1;
}
