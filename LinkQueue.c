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
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) { // Check memory allocation
        exit(OVERFLOW);     
    }
    p->data = e; // Set the data part
    p->next = NULL; // Set the next part to NULL
    Q->rear->next = p; // Insert the new node into the queue
    Q->rear = p; // Update the rear pointer
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

// Implement GetHead and other operations as per your requirement.