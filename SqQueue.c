#include "SqQueue.h"   

Status SqInitQueue(SqQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    (*Q).base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
    if(!(*Q).base) {
        exit(OVERFLOW);
    }
    (*Q).front = (*Q).rear = 0;
    return OK;
}

int SqQueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status SqEnQueue(SqQueue* Q, QElemType e) {
    if((Q->rear + 1) % MAXQSIZE == Q->front) {
        return ERROR; // Queue is full
    }
    Q->base[Q->rear] = e; // Insert new element
    Q->rear = (Q->rear + 1) % MAXQSIZE; // Update rear position
    return OK;
}

Status SqDeQueue(SqQueue* Q, QElemType* e) {
    if(Q->front == Q->rear) {
        return ERROR; // Queue is empty
    }
    *e = Q->base[Q->front]; // Retrieve front element
    Q->front = (Q->front + 1) % MAXQSIZE; // Update front position
    return OK;
}

Status SqGetHead(SqQueue Q, QElemType* e) {
    if(Q.front == Q.rear) return ERROR; // Queue is empty
    *e = Q.base[Q.front];
    return OK;
}

Status SqQueueEmpty(SqQueue Q) {
    return (Q.front == Q.rear) ? TRUE : FALSE;
}

Status SqClearQueue(SqQueue* Q) {
    Q->front = Q->rear = 0;
    return OK;
}
// Implement GetHead, DestroyQueue, ClearQueue, QueueEmpty, and QueueTraverse as per your requirement.