#include "SqStack.h"

// Initialize your SqStack structure with a certain size
#define STACK_INIT_SIZE 100 // initial storage capacity
#define STACKINCREMENT 10   // Incremental amount of stack growth

Status InitStack(SqStack* S) {
    S->base = (ElementType*) malloc(STACK_INIT_SIZE * sizeof(ElementType));
    if(!S->base) {
        exit(OVERFLOW); // Storage allocation failed
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return SUCCESS;
}

int StackLength(SqStack S) {
    return S.top - S.base;
}

Status GetTop(SqStack S, ElementType* e) {
    if(S.top > S.base) {
        *e = *(S.top - 1); // Get the top element, without removing it
        return SUCCESS;
    } else {
        return FAIL;
    }
}

Status Push(SqStack* S, ElementType e) {
    if(S->top - S->base >= S->stacksize) { // Stack is full, need to allocate more space
        ElementType* newbase = (ElementType*) realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElementType));
        if(!newbase) {
            return OVERFLOW;
        }
        S->base = newbase; // Reset base to new storage
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top++) = e; // Push element and increment top pointer
    return SUCCESS;
}

Status Pop(SqStack* S, ElementType* e) {
    if(S->top == S->base) {
        return EMPTY; // Stack is empty, cannot pop
    }
    *e = *(--S->top); // Decrement top pointer and get top element
    return SUCCESS;
}