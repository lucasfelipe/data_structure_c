#include "ChainedDescriptorList.h"

struct element {
    struct student data;
    struct element* next;
};

typedef struct element Elem;

struct descriptor {
    struct element *first;
    struct element *last;
    int quantity;
};

List* create() {
    List* li = (List*) malloc(sizeof(List));
    if (li != NULL) {
        li->first = NULL;
        li->last = NULL;
        li->quantity = 0;
    }
    return li;
}

void free_list(List* li) {
    if (li != NULL) {
        Elem* node;
        while ((li->first) != NULL) {
            node = li->first;
            li->first = li->first->next;
            free(node);
        }
        free(li);
    }
}

int size(List* li) {
    if (li == NULL) return 0;
    return li->quantity;
}

int insert_begin(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    node->next = li->first;
    if (li->first == NULL)
        li->last = node;
    li->first = node;
    li->quantity++;
    return 1;
}

int insert_end(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    node->next = NULL;
    if (li->first == NULL)
        li->first = node;
    else
        li->last->next = node;
    li->last = node;
    li->quantity++;
    return 1;
}

int remove_begin(List* li) {
    if (li == NULL) return 0;
    if (li->first == NULL) return 0;
    Elem* node = li->first;
    li->first = node->next;
    free(node);
    if (li->first == NULL)
        li->last = NULL;
    li->quantity--;
    return 1;
}

int remove_end(List* li) {
    if (li == NULL) return 0;
    if (li->first == NULL) return 0;
    Elem* before = NULL, *node = li->first;
    while (node->next != NULL) {
        before = node;
        node = node->next;
    }
    if (node == li->first) {
        li->first = NULL;
        li->last = NULL;
    } else {
        before->next = node->next;
        li->last = before;
    }
    free(node);
    li->quantity--;
    return 1;
}
