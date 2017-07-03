//
//  main.c
//  DS_CHAINED_DESCRITOR_LIST
//
//  Created by Dev on 03/07/17.
//  Copyright © 2017 Wooba. All rights reserved.
//

#include "ChainedDescriptorList.h"

int main(int argc, const char * argv[]) {
    List* li = create();
    printf("Size: %d \n\n", size(li));
    struct student* stud = (struct student*) malloc(sizeof(struct student));
    stud->registrationID = 1;
    printf("Insert beginning: %d \n\n", insert_begin(li, *stud));
    struct student* stud_end = (struct student*) malloc(sizeof(struct student));
    stud_end->registrationID = 2;
    printf("Insert end: %d \n\n", insert_end(li, *stud_end));
    printf("Remove beginning: %d \n\n", remove_begin(li));
    printf("Remove end: %d \n\n", remove_end(li));
    free_list(li);
    return 0;
}
