#include <stdio.h>
#include <stdlib.h>

struct student {
    int registrationID;
    char name[30];
    float grade1, grade2, grade3;
};

typedef struct descriptor List;

List* create();

void free_list(List* li);

int size(List* li);

int insert_begin(List* li, struct student stud);

int insert_end(List* li, struct student stud);

int remove_begin(List* li);

int remove_end(List* li);
