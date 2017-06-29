#include "DoubleChainedList.h"

struct element {
    struct element *before;
    struct student data;
    struct element *next;
};

typedef struct element Elem;

List* create() {
    List* li = (List*) malloc(sizeof(List));
    if (li != NULL)
        *li = NULL;
    return li;
}

void free_list(List* li) {
    if (li != NULL) {
        Elem* node;
        while ((*li) != NULL) {
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li);
    }
}

int size(List* li) {
    if (li == NULL) return 0;
    int count = 0;
    Elem* node = (*li);
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

int full(List* li) {
    return 0;
}

int empty(List* li) {
    if (li == NULL) return 1;
    if (*li == NULL) return 1;
    return 0;
}

int insert_begin(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    node->next = (*li);
    node->before = NULL;
    if (*li != NULL)
        (*li)->before = node;
    *li = node;
    return 1;
}

int insert_end(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->next = NULL;
    node->data = stud;
    if ((*li) == NULL) {
        node->before = NULL;
        *li = node;
    } else {
        Elem* aux = (*li);
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
        node->before = aux;
    }
    return 1;
}

int insert_in_order(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    if (empty(li)) { // if the list is empty the next and before will be NULL
        node->next = NULL;
        node->before = NULL;
        *li = node;
    } else {
        Elem *before = (*li), *current = (*li);
        while (current != NULL && current->data.registrationID < stud.registrationID) { // find the current element (can be the last one (NULL)) or (the middle element)
            before = current;
            current = current->next;
        }
        if (current == (*li)) { // the current is the first one - insert in the beginning
            node->before = NULL;
            node->next = (*li);
            (*li)->before = node;
            *li = node;
        } else { // the current is in the middle or the last (NULL)
            node->next = before->next; // current if NULL we are inserting in the end of the list
            node->before = before;
            before->next = node;
            if (current != NULL) // current is in the middle and we need to point to the inserted node on the previous node;
                current->before = node;
        }
    }
    return 1;
}

int remove_begin(List* li) {
    if (empty(li)) return 0;
    Elem* node = (*li);
    *li = node->next;
    if (node->next != NULL)
        node->next->before = NULL;
    free(node);
    return 1;
}

int remove_end(List* li) {
    if (empty(li)) return 0;
    Elem* node = *li;
    while (node->next != NULL)
        node = node->next;
    if (node->before == NULL)
        *li = node->next;
    else
        node->before->next = NULL;
    free(node);
    return 1;
}

int remove_by_registry(List* li, int regID) {
    if (empty(li)) return 0;
    Elem* node = (*li);
    while (node->next != NULL && node->data.registrationID != regID)
        node = node->next;
    if (node == NULL)
        return 0;
    if (node->before == NULL)
        *li = node->next;
    else
        node->before->next = node->next;
    if (node->next != NULL) // is not the last
        node->next->before = node->before;
    free(node);
    return 1;
}

int search_by_position(List* li, int position, struct student* stud) {
    if (empty(li) || position <= 0) return 0;
    Elem* node = (*li);
    int i = 1;
    while (node != NULL && i < position) {
        node = node->next;
        i++;
    }
    if (node == NULL)
        return 0;
    else {
        *stud = node->data;
        return 1;
    }
}

int search_by_registry(List* li, int regID, struct student* stud) {
    if (empty(li)) return 0;
    Elem* node = (*li);
    while (node != NULL && node->data.registrationID != regID) {
        node = node->next;
    }
    if (node == NULL) return 0;
    else {
        *stud = node->data;
        return 1;
    }
}
