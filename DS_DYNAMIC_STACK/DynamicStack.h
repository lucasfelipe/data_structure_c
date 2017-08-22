#include <stdio.h>
#include <stdlib.h>

struct student {
    int regID;
    char name[30];
    float n1, n2, n3;
};

typedef struct element* Stack;

Stack* create_stack();

void free_stack(Stack* stack);

int size_stack(Stack* stack);

int is_full(Stack* stack);

int is_empty(Stack* stack);

int insert(Stack* stack, struct student student);

int remove_element(Stack* stack);

int search_data(Stack* stack, struct student* student);
