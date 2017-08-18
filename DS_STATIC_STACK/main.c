#include "SequencialStack.h"
#include "string.h"

int main(int argc, const char * argv[]) {
    Stack* stack = create_stack();
    int size = size_stack(stack);
    printf("Size of Stack: %d \n", size);
    if (is_full(stack)) printf("The stack is full! \n");
    if (is_empty(stack)) printf("The stack is empty! \n");
    struct student* student = (struct student*) malloc(sizeof(struct student*));
    student->regID = 1;
    strcpy(student->name, "Xablau!");
    int insert = insert_stack(stack, *student);
    printf("Student inserted: %d \n", insert);
    struct student student_search;
    int search = search_stack(stack, &student_search);
    printf("Student Searched: \n ID: %d, Name: %s \n", student_search.regID, student_search.name);
    int remove = remove_stack(stack);
    printf("Remove value: %d \n", remove);
    free_stack(stack);
    return 0;
}
