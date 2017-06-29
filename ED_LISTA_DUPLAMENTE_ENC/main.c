//
//  main.c
//  ED_LISTA_DUPLAMENTE_ENC
//
//  Created by Dev on 28/06/17.
//  Copyright © 2017 Wooba. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(int argc, const char * argv[]) {
    List *li = create();
    printf("%d\n", empty(li));
    struct student *stud = (struct student*) malloc(sizeof(struct student));
    stud->registrationID = 1;
    printf("%d\n", insert_begin(li, *stud));
    struct student *stud_end = (struct student*) malloc(sizeof(struct student));
    stud_end->registrationID = 3;
    printf("%d\n", insert_end(li, *stud_end));
    struct student *stud_order = (struct student*) malloc(sizeof(struct student));
    stud_order->registrationID = 2;
    printf("%d\n\n\n\n", insert_in_order(li, *stud_order));
    
    print_list(li);
    
    printf("\n%d\n\n", remove_begin(li));
    
    print_list(li);
    
    printf("\n%d\n\n", remove_list(li, 2));
    
    print_list(li);
    
    struct student student_search;
    printf("\n%d\n\n", search_by_position(li, 1, &student_search));
    printf("\n%d\n\n", search_by_registry(li, 3, &student_search));
    
    free_list(li);
    return 0;
}
