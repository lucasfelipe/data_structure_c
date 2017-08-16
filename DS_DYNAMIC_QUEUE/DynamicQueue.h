#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int regID;
    char name[30];
    float n1, n2, n3;
};

typedef struct queue Queue;

Queue* create_queue();

void free_queue(Queue* queue);

int size_of_queue(Queue* queue);

int empty_queue(Queue* queue);

int insert(Queue* queue, struct student stud);

int remove_element(Queue* queue);

int search_studend(Queue* queue, struct student* stud);
