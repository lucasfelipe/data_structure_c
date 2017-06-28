struct student {
    int registrationID;
    char name[30];
    float grade1,grade2,grade3;
};

typedef struct element* List;

List* create();

void free_list(List* li);

int size(List* li);

int empty(List* li);

int insert_begin(List* li, struct student stud);

int insert_end(List* li, struct student stud);

int insert_in_order(List* li, struct student stud);

void print_list(List* li);

int remove_begin(List* li);

int remove_end(List* li);

int remove_list(List* li, int mat);
