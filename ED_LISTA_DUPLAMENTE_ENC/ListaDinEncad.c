//
//  ListaDinEncad.c
//  ED_LISTA_EST_05
//
//  Created by Dev on 28/06/17.
//  Copyright © 2017 Wooba. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "ListaDinEncad.h"

struct element {
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
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }
}

int size(List* li) {
    if (li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->next;
    }
    return cont;
}

int empty(List* li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

int insert_begin(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    node->next = (*li);
    *li = node;
    return 1;
}

int insert_end(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if (node == NULL) return 0;
    node->data = stud;
    node->next = NULL;
    Elem* aux = (*li);
    if ((*li) == NULL) {
        *li = node;
    } else {
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}

int insert_in_order(List* li, struct student stud) {
    if (li == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem));
    node->data = stud;
    if (empty(li)) {
        node->next = (*li);
        *li = node;
    } else {
        Elem *before = *li, *current = *li;
        while (current != NULL && current->data.registrationID < stud.registrationID) {
            before = current;
            current = current->next;
        }
        if (current == (*li)) {
            node->next = (*li);
            *li = node;
        } else {
            node->next = before->next;
            before->next = node;
        }
    }
    return 1;
}

void print_list(List* li) {
    Elem* node = (*li);
    while (node != NULL) {
        printf("%d\n", node->data.registrationID);
        node = node->next;
    }
}

int remove_begin(List* li) {
    if (empty(li)) return 0;
    Elem* node = (*li);
    *li = node->next;
    free(node);
    return 1;
}

int remove_end(List* li) {
    if (empty(li)) return 0;
    Elem *before = (*li), *current = (*li);
    while (current->next != NULL) {
        before = current;
        current = current->next;
    }
    if (current == (*li))
        *li = current->next;
    else
        before->next = current->next;
    free(current);
    return 1;
}

int remove_list(List* li, int regID) {
    if (empty(li)) return 0;
    Elem *before = (*li), *current = (*li);
    while (current != NULL && current->data.registrationID != regID) {
        before = current;
        current = current->next;
    }
    if ((*li) == current)
        *li = current->next;
     else
         before->next = current->next;
    free(current);
    return 1;
}

int search_by_position(List* li, int position, struct student *stud) {
    if (empty(li)) return 0;
    Elem* node = (*li);
    int i = 1;
    while (node != NULL && i < position) {
        node = node->next;
    }
    if (node == NULL) return 0;
    else {
        *stud = node->data;
        return 1;
    }
}

int search_by_registry(List* li, int regID, struct student *stud) {
    if (empty(li)) return 0;
    Elem *node = (*li);
    while (node != NULL && node->data.registrationID != regID) {
        node = node->next;
    }
    if (node == NULL) return 0;
    else {
        *stud = node->data;
        return 1;
    }
}
