#import <stdlib.h>

struct student {
    int registrationID;
    char name[30];
    float grade1, grade2, grade3;
};

typedef struct element* List;

List* create();

void free_list(List* li);

int size(List* li);

int is_full(List* li);

int empty(List* li);

int insert_begin(List* li, struct student stud);

int insert_end(List* li, struct student stud);

int insert_order(List* li, struct student stud);
