#include "DynamicStack.h"

int main(int argc, const char * argv[]) {
    Stack* stack = create_stack();
    if (stack != NULL) printf("Stack created! \n");
    int size = size_stack(stack);
    printf("Size of Stack: %d \n", size);
    
    struct student* stud = (struct student*) malloc(sizeof(struct student));
    stud->regID = 1;
    int ins = insert(stack, *stud);
    printf("Inserted: %d \n", ins);
    
    struct student student_searched;
    int search = search_data(stack, &student_searched);
    printf("Searched: %d \n Student: \n Mat: %d \n", search, student_searched.regID);
    
    int rem = remove_element(stack);
    printf("Removed: %d \n", rem);
    
    free_stack(stack);
    return 0;
}
