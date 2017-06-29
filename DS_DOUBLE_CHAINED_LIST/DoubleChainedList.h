#include <stdlib.h>

struct student {
    int registrationID;
    char name[30];
    float grade1, grade2, grade3;
};

typedef struct element* List;

List* create();

void free_list(List* li);

int size(List* li);

int full(List* li);

int empty(List* li);

int insert_begin(List* li, struct student stud);

int insert_end(List* li, struct student stud);

int insert_in_order(List* li, struct student stud);

int remove_begin(List* li);

int remove_end(List* li);

int remove_by_registry(List* li, int regID);

int search_by_position(List* li, int position, struct student* stud);

int search_by_registry(List* li, int regID, struct student* stud);
