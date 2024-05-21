#include "LinkQueue.h"

Status LinkInitQueue(LinkQueue* Q) {
    if(Q == NULL) {
        return ERROR;
    }
    (*Q).front = (*Q).rear = (QueuePtr) malloc(sizeof(QNode));
    if(!(*Q).front) {
        exit(OVERFLOW);
    }
    (*Q).front->next = NULL; // Ensure the next pointer of the head node is NULL
    return OK;
}

Status LinkDestroyQueue(LinkQueue* Q) {
    // Traversal pointer for node deletion
    while(Q->front) {
        Q->rear = Q->front->next; // Save the next node
        free(Q->front); // Free the current node
        Q->front = Q->rear; // Move to next node
    }
    return OK;
}

Status LinkClearQueue(LinkQueue* Q) {
    QueuePtr p, q;
    p = Q->front->next; // P points to the first node
    Q->front->next = NULL; // Head node points to NULL
    Q->rear = Q->front; // Reset rear to front
    while(p) {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

Status LinkEnQueue(LinkQueue* Q, QElemType e) {
    QueuePtr p;
    if(Q == NULL || (*Q).front == NULL) {
        return ERROR;
    }
    
    p = (QueuePtr) malloc(sizeof(QNode));
    if(!p) {
        exit(OVERFLOW);
    }

    p->data = e; // Set the data of the new node
    p->next = NULL; // The new node will be the last node, so its next pointer is NULL
    
    // If the queue is empty, insert the new node after the front
    if((*Q).rear == (*Q).front) {
        (*Q).front->next = p;
    } else {
        // Otherwise, insert it after the current last node
        (*Q).rear->next = p;
    }
    
    // Update the rear pointer of the queue
    (*Q).rear = p;
    return OK;
}

Status LinkDeQueue(LinkQueue* Q, QElemType* e) {
    if (Q->front == Q->rear) {
        return ERROR; // Queue is empty
    }
    QueuePtr p = Q->front->next; // Pointer to the first element
    *e = p->data; // Set value to *e
    Q->front->next = p->next; // Remove the first element from the queue
    if (Q->rear == p) {
        Q->rear = Q->front; // If the queue was only one element long, reset the rear
    }
    free(p); // Free the removed node
    return OK;
}

Status LinkGetHead(LinkQueue Q, QElemType* e) {
    if(Q.front == Q.rear) return ERROR; // Queue is empty
    *e = Q.front->next->data;
    return OK;
}

int LinkQueueLength(LinkQueue Q) {
    int count = 0;
    QueuePtr p = Q.front;
    while(p->next) {
        count++;
        p = p->next;
    }
    return count;
}

Status LinkQueueEmpty(LinkQueue Q) {
    return (Q.front == Q.rear) ? EMPTY : FALSE;
}
// Implement GetHead and other operations as per your requirement.