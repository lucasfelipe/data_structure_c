#include "StaticQueue.h"

struct queue {
    int begin, end, quantity;
    struct student data[MAX];
};

Queue* create_queue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue*));
    if (queue != NULL) {
        queue->begin = 0;
        queue->end = 0;
        queue->quantity = 0;
    }
    return queue;
}

void free_queue(Queue* queue) {
    free(queue);
}

int insert(Queue* queue, struct student stud) {
    if (queue == NULL) return 0;
    if (isFull(queue)) return 0;
    queue->data[queue->end] = stud;
    queue->end = (queue->end + 1) % MAX;
    queue->quantity++;
    return 1;
}

int isFull(Queue* queue) {
    return queue->quantity == MAX;
}

int remove_element(Queue* queue) {
    if (queue == NULL || isEmpty(queue)) return 0;
    queue->begin = (queue->begin + 1) % MAX;
    return 1;
}

int isEmpty(Queue* queue) {
    return queue->quantity == 0;
}

int get_element(Queue* queue, struct student* stud) {
    if (queue == NULL || isEmpty(queue)) return 0;
    *stud = queue->data[queue->begin];
    return 1;
}
