#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Status is used for function returns.
typedef enum Status {
    SUCCESS, // Operation succeeded
    FAIL,    // Operation failed
    OVERFLOW,// Overflow occurred
    EMPTY,   // Empty structure
    ERROR,
    OK,
    TRUE,
    FALSE
} Status;

// ElementType could be adjusted based on specific requirements.
typedef int ElementType;

#endif //COMMON_H