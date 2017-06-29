#include <stdio.h>
#include "DoubleChainedList.h"

int main(int argc, const char * argv[]) {
    List* li = create();

    printf("Size of List: %d \n\n", size(li));
    printf("List is empty: %d \n\n", empty(li));
    
    struct student *stud = (struct student*) malloc(sizeof(struct student));
    stud->registrationID = 1;
    printf("Insert in the beginning: %d \n\n", insert_begin(li, *stud));
    
    struct student *stud_end = (struct student*) malloc(sizeof(struct student));
    stud_end->registrationID = 3;
    printf("Insert in the end: %d \n\n", insert_end(li, *stud_end));
    
    struct student *stud_order = (struct student*) malloc(sizeof(struct student));
    stud_order->registrationID = 2;
    printf("Insert in order: %d \n\n", insert_in_order(li, *stud_order));
    
    struct student result_pos;
    printf("Search position: %d \n\n", search_by_position(li, 2, &result_pos));

    struct student result_reg;
    printf("Search registry: %d \n\n", search_by_registry(li, 3, &result_reg));

    
    printf("Remove begin: %d \n\n", remove_begin(li));
    printf("Remove end: %d \n\n", remove_end(li));
    printf("Remove by registry: %d \n\n", remove_by_registry(li, 2));

    
    
    free_list(li);
    return 0;
}
