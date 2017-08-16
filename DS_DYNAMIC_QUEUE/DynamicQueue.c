#include "DynamicQueue.h"

struct queue {
    struct element* begin;
    struct element* end;
};

struct element {
    struct student data;
    struct element* next;
};

typedef struct element Elem;

Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue*));
    if (queue != NULL) {
        queue->begin = NULL;
        queue->end = NULL;
    }
    return queue;
}

void free_queue(Queue* queue) {
    if (queue != NULL) {
        Elem* node;
        while (queue->begin != NULL) {
            node = queue->begin;
            queue->begin = queue->begin->next;
            free(node);
        }
        free(queue);
    }
}

int size_of_queue(Queue* queue) {
    if (queue == NULL) return 0;
    int size = 0;
    Elem* node = queue->begin;
    while (node != NULL) {
        size++;
        node = queue->begin->next;
    }
    return size;
}

int empty_queue(Queue* queue) {
    if (queue == NULL) return 1;
    if (queue->begin == NULL) return 1;
    return 0;
}

int insert(Queue* queue, struct student stud) {
    if (queue == NULL) return 0;
    Elem* node = (Elem*) malloc(sizeof(Elem*));
    if (node == NULL) return 0;
    node->data = stud;
    node->next = NULL;
    if (queue->end == NULL)  // empty list
        queue->begin = node;
    else
        queue->end->next = node;
    queue->end = node;
    return 1;
}

int remove_element(Queue* queue) {
    if (queue == NULL) return 0;
    if (queue->begin == NULL) return 0;
    Elem* node = queue->begin;
    queue->begin = queue->begin->next;
    if (queue->begin == NULL) // queue becomes empty
        queue->end = NULL;
    free(node);
    return 1;
}

int search_studend(Queue* queue, struct student* stud) {
    if (queue == NULL) return 0;
    if (queue->begin == NULL) return 0; // empty list
    *stud = queue->begin->data;
    return 1;
}
