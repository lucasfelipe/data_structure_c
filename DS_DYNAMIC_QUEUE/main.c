#include "DynamicQueue.h"

int main(int argc, const char * argv[]) {
    Queue* queue = create_queue();
    printf("Size: %d \n", size_of_queue(queue));
    
    struct student* stud = (struct student*) malloc(sizeof(struct student*));
    strcpy(stud->name, "Xablau!");
    stud->regID = 1;
    int ins = insert(queue, *stud);
    if (ins) printf("Inserted: %d \n", ins);
    
    struct student stud_search;
    int search = search_studend(queue, &stud_search);
    if (search) printf("Student \n RegID: %d \n Name: %s \n", stud_search.regID, stud_search.name);
    
    int remove = remove_element(queue);
    if (remove) printf("Removed: %d \n", remove);
    
    free_queue(queue);
    return 0;
}
