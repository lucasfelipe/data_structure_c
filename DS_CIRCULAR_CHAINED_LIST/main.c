//
//  main.c
//  DS_CIRCULAR_CHAINED_LIST
//
//  Created by Dev on 29/06/17.
//  Copyright © 2017 Wooba. All rights reserved.
//

#include "CircularChainedList.h"

int main(int argc, const char * argv[]) {
    List* li = create();

    printf("Size of list: %d \n\n", size(li));
    printf("List is empty: %d \n\n", empty(li));
    
    struct student* stud = (struct student*) malloc(sizeof(struct student));
    stud->registrationID = 1;
    printf("Insert in the beginning: %d\n\n", insert_begin(li, *stud));
    
    struct student* stud_end = (struct student*) malloc(sizeof(struct student));
    stud_end->registrationID = 3;
    printf("Insert in the end: %d\n\n", insert_end(li, *stud_end));
    
    struct student* stud_order = (struct student*) malloc(sizeof(struct student));
    stud_order->registrationID = 2;
    printf("Insert in order: %d\n\n", insert_order(li, *stud_order));
    
    print_list(li);
    
    struct student stud_pos;
    printf("Search by position: %d\n\n", search_by_position(li, 2, &stud_pos));
    struct student stud_reg;
    printf("Search by position: %d\n\n", search_by_registry(li, 3, &stud_reg));
    
    
    printf("Remove first: %d\n\n", remove_first(li));
    printf("Remove end: %d\n\n", remove_end(li));
    printf("Remove list: %d\n\n", remove_list(li, 2));
    
    free_list(li);
    return 0;
}
