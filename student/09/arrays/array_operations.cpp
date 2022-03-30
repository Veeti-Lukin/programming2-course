#include "array_operations.hh"
#include <iostream>
int greatest_v1(int *itemptr, int size) {
    int* arraypointer = itemptr;
    int greatest = -__INT_MAX__;

    while ( arraypointer < itemptr + size) {
        if (*arraypointer > greatest) {
            greatest = *arraypointer;
        }
        ++arraypointer;
    }

    return greatest;
}

int greatest_v2(int *itemptr, int *endptr) {
    int* arraypointer = itemptr;
    int greatest = -__INT_MAX__;

    while ( arraypointer < endptr) {
        if (*arraypointer > greatest) {
            greatest = *arraypointer;
        }
        ++arraypointer;
    }

    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr) {
    // check if both arrays are same size;
    if (!(sizeof(itemptr) == sizeof(targetptr))) {
        return;
    }
    int* arraypointer = itemptr;

    while ( arraypointer < endptr) {
        *targetptr = *arraypointer;
        arraypointer++, targetptr++;
    }
}

void reverse(int *leftptr, int *rightptr) {
    rightptr--;
    while (leftptr < rightptr) {
       int temp = *leftptr;
       *leftptr = *rightptr;
       *rightptr = temp;;
       leftptr++;
       rightptr--;
    }

}
