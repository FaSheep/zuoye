#include "SqStack.h"

// Destroy the stack
Status DestroyStack(SqStack* S) {
    if (S->base) {
        free(S->base);
        S->base = NULL;
        S->top = NULL;
        S->stacksize = 0;
    }
    return SUCCESS;
}

// Clear the stack
Status ClearStack(SqStack* S) {
    S->top = S->base;
    return SUCCESS;
}

// Check if the stack is empty
Status StackEmpty(SqStack S) {
    return S.top == S.base ? TRUE : FALSE;
}

// Get the length of the stack (number of elements)
int StackLength(SqStack S) {
    return S.top - S.base;
}

// Get the top element of the stack
Status GetTop(SqStack S, SElemType* e) {
    if (S.top == S.base) return ERROR;
    *e = *(S.top - 1);
    return SUCCESS;
}

// Traverse the stack and apply the function Visit to each element
Status StackTraverse(SqStack S, void(Visit)(SElemType)) {
    SElemType* p = S.base;
    while (p != S.top) {
        Visit(*p++);
    }
    return SUCCESS;
}

// Initialize a stack
Status InitStack(SqStack* S) {
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) {
        exit(OVERFLOW); // If allocation fails, exit program
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return SUCCESS;
}

// Push an element onto the stack
Status Push(SqStack* S, SElemType e) {
    if (S->top - S->base >= S->stacksize) { // Stack is full, need to allocate more space
        SElemType* newBase = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!newBase) {
            return OVERFLOW; // If reallocation fails
        }
        S->base = newBase; // Update base pointer to the new allocated memory
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top++) = e; // Place new element on top of the stack
    return SUCCESS;
}

// Pop an element from the stack
Status Pop(SqStack* S, SElemType* e) {
    if (S->top == S->base) {
        return ERROR;  // Stack is empty, nothing to pop
    }
    *e = *(--S->top); // Retrieve the top element and adjust the top pointer
    return SUCCESS;
}