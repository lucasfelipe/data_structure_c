#import <stdlib.h>
#import <stdio.h>

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

int remove_first(List* li);

int remove_end(List* li);

int remove_list(List* li, int regID);

void print_list(List* li);

int search_by_position(List* li, int position, struct student *stud);

int search_by_registry(List* li, int regID, struct student *stud);
