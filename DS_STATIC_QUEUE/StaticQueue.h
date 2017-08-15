#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct student {
    int regID;
    char name[30];
    float n1, n2, n3;
};
typedef struct queue Queue;

Queue* create_queue();

void free_queue(Queue* queue);

int insert(Queue* queue, struct student stud);

int remove_element(Queue* queue);

int get_element(Queue* queue, struct student* stud);

