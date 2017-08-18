#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct student {
    int regID;
    char name[30];
    float n1, n2, n3;
};

typedef struct stack Stack;

Stack* create_stack();

void free_stack(Stack* stack);

int size_stack(Stack* stack);

int is_full(Stack* stack);

int is_empty(Stack* stack);

int insert_stack(Stack* stack, struct student student);

int remove_stack(Stack* stack);

int search_stack(Stack* stack, struct student* student);
