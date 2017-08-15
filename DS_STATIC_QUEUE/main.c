
#include "StaticQueue.h"
#include <string.h>

int main(int argc, const char * argv[]) {
    Queue* queue = create_queue();
    struct student* student = (struct student*) malloc(sizeof(struct student*));
    strcpy(student->name, "Charles Henrique");
    student->regID = 1;
    printf("insert: %d\n", insert(queue, *student));
    struct student stud_search;
    int get = get_element(queue, &stud_search);
    printf("get: %d\n", get);
    printf("Student \n ID-%d, Name-%s. \n", stud_search.regID, stud_search.name);
    printf("remove: %d\n", remove_element(queue));
    free_queue(queue);
    return 0;
}
