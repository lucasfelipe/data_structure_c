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


int remove_first(List* li) {
    if (empty(li)) return 0;
    if ((*li) == (*li)->next) {
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem* current = *li;
    while (current->next != (*li)) {
        current = current->next;
    }
    Elem* node = *li;
    current->next = node->next;
    *li = node->next;
    free(node);
    return 1;
}

int remove_end(List* li) {
    if (empty(li)) return 0;
    if ((*li) == (*li)->next) {
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem* current = *li, *before = NULL;
    while (current->next != (*li)) {
        before = current;
        current = current->next;
    }
    before->next = current->next;
    free(current);
    return 1;
}

int remove_list(List* li, int regID) {
    if (empty(li)) return 0;
    Elem* node = *li;
    if (node->data.registrationID == regID) {
        if (node->next == node) {
            free(node);
            *li = NULL;
            return 1;
        }
        Elem* last = *li;
        while (last->next != *li) {
            last = last->next;
        }
        last->next = (*li)->next;
        *li = (*li)->next;
        free(node);
        return 1;
    }
    Elem *before = node;
    node = node->next;
    while (node != (*li) && node->data.registrationID != regID) {
        before = node;
        node = node->next;
    }
    if (node == *li) return 0; // not find
    before->next = node->next;
    free(node);
    return 1;
}

void print_list(List* li) {
    if (!empty(li)) {
        Elem* node = (*li);
        while (node->next != *li) {
            printf("Student - RegID: %d \n", node->data.registrationID);
            node = node->next;
        }
        printf("Student - RegID: %d \n", node->data.registrationID);
    } else printf("empty!");
}

int search_by_position(List* li, int position, struct student *stud) {
    if (empty(li) || position <= 0) return 0;
    Elem* node = *li;
    int count = 1;
    while (node->next != (*li) && count < position) {
        node = node->next;
        count++;
    }
    if (count != position) return 0;
    else {
        *stud = node->data;
        return 1;
    }
}

int search_by_registry(List* li, int regID, struct student *stud) {
    if (empty(li)) return 0;
    Elem* node = *li;
    while (node->next != (*li) && node->data.registrationID != regID) {
        node = node->next;
    }
    if (node->data.registrationID != regID) return 0;
    else {
        *stud = node->data;
        return 1;
    }
}
