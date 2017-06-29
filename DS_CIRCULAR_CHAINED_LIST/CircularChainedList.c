#include "CircularChainedList.h"

struct element {
    struct student data;
    struct element* next;
};

typedef struct element Elem;

List* create() {
    List* li = (List*) malloc(sizeof(List));
    if (li != NULL)
        *li = NULL;
    return li;
}

void free_list(List* li) {
    if (li != NULL && (*li) != NULL) {
        Elem* aux, *node = *li;
        while ((*li) != node->next) {
            aux = node;
            node = node->next;
            free(aux);
        }
        free(node);
        free(li);
    }
}

int size(List* li) {
    if (li == NULL || (*li) == NULL) return 0;
    int count = 0;
    Elem* node = (*li);
    do {
        count++;
        node = node->next;
    } while ((*li) != node);
    return count;
}

int is_full(List* li) {
    return 0;
}

int empty(List* li) {
    if (li == NULL || (*li) == NULL) return 1;
    return 0;
}

int insert_begin(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    node->data = stud;
    if ((*li) == NULL) {
        *li = node;
        node->next = node;
    } else {
        Elem* aux = *li;
        while (aux->next != (*li)) {
            aux = aux->next;
        }
        aux->next = node;
        node->next = *li;
        *li = node;
    }
    return 1;
    
}

int insert_end(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    if ((*li) == NULL) {
        *li = node;
        node->next = node;
    } else {
        Elem* aux = *li;
        while (aux->next != (*li)) {
            aux = aux->next;
        }
        aux->next = node;
        node->next = *li;
    }
    return 1;
}

int insert_order(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    if ((*li) == NULL) { // my node is the first one
        *li = node;
        node->next = node;
    } else {
        if ((*li)->data.registrationID > stud.registrationID) { // my node needs to be the first element in the list
            Elem* current = *li;
            while (current->next != (*li)) {
                current = current->next;
            }
            node->next = (*li);
            current->next = node;
            *li = node;
            return 1;
        }
        Elem* before = *li, *current = (*li)->next;
        while (current != (*li) && current->data.registrationID < stud.registrationID) { // my node can stay in the middle or in the end
            before = current;
            current = current->next;
        }
        before->next = node;
        node->next = current;
    }
    return 1;
}
