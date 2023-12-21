#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include "../priorityQueue.h"
#include "../toStringFunctions.h"
#include "../compareFunctions.h"

int testIntPriorityQueue() {
    PriorityQueue *greaterPQ = createPriorityQueue(greaterInt);
    PriorityQueue *smallerPQ = createPriorityQueue(smallerInt);
    int testValues[] = {44, 33, 22, 11, 0, -11, -22, -33, -44};
    int size = sizeof(testValues) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        pq_push(greaterPQ, &testValues[i]);
        pq_push(smallerPQ, &testValues[i]);
    }

    pq_displayOrdered(greaterPQ, toStringInt);
    pq_displayOrdered(smallerPQ, toStringInt);

    int sortedValues[] = {-44, -33, -22, -11, 0, 11, 22, 33, 44};
    int i = 0, j = size - 1;
    while (!pq_isEmpty(greaterPQ)) {
        int greaterTop = *(int *) pq_top(greaterPQ);
        int smallerTop = *(int *) pq_top(smallerPQ);

        if (greaterTop != sortedValues[j]) {
            fprintf(stderr, "Test Integers failed. Expected value: %d, Actual value: %d\n", sortedValues[j],
                    greaterTop);
            return 0;
        }
        if (smallerTop != sortedValues[i]) {
            fprintf(stderr, "Test Integers failed. Expected value: %d, Actual value: %d\n", sortedValues[i],
                    smallerTop);
            return 0;
        }

        ++i;
        --j;
        pq_pop(greaterPQ);
        pq_pop(smallerPQ);
    }
    return 1;
}

int testStringPriorityQueue() {
    PriorityQueue *greaterPQ = createPriorityQueue(greaterString);
    PriorityQueue *smallerPQ = createPriorityQueue(smallerString);
    char *testValues[] = {"Omar", "Ahmed", "Ali", "Mohamed", "Ziad", "Khaled", "Mahmoud", "Hassan", "Youssef"};
    int size = sizeof(testValues) / sizeof(char *);
    for (int i = 0; i < size; ++i) {
        pq_push(greaterPQ, testValues[i]);
        pq_push(smallerPQ, testValues[i]);
    }

    pq_displayOrdered(greaterPQ, toStringStr);
    pq_displayOrdered(smallerPQ, toStringStr);

    char *sortedValues[] = {"Ziad", "Youssef", "Omar", "Mohamed", "Mahmoud", "Khaled", "Hassan", "Ali", "Ahmed"};
    int i = 0, j = size - 1;
    while (!pq_isEmpty(greaterPQ)) {
        char *greaterTop = pq_top(greaterPQ);
        char *smallerTop = pq_top(smallerPQ);

        if (strcmp(greaterTop, sortedValues[i]) != 0) {
            fprintf(stderr, "Test Strings failed. Expected value: %s, Actual value: %s\n", sortedValues[i], greaterTop);
            return 0;
        }
        if (strcmp(smallerTop, sortedValues[j]) != 0) {
            fprintf(stderr, "Test Strings failed. Expected value: %s, Actual value: %s\n", sortedValues[j], smallerTop);
            return 0;
        }

        ++i;
        --j;
        pq_pop(greaterPQ);
        pq_pop(smallerPQ);
    }
    return 1;
}

int testFloatPriorityQueue() {
    PriorityQueue *greaterPQ = createPriorityQueue(greaterFloat);
    PriorityQueue *smallerPQ = createPriorityQueue(smallerFloat);
    float testValues[] = {44.0, 33.0, 22.0, 11.0, 0.0, -11.0, -22.0, -33.0, -44.0};
    int size = sizeof(testValues) / sizeof(float);
    for (int i = 0; i < size; ++i) {
        pq_push(greaterPQ, &testValues[i]);
        pq_push(smallerPQ, &testValues[i]);
    }

    pq_displayOrdered(greaterPQ, toStringFloat);
    pq_displayOrdered(smallerPQ, toStringFloat);

    float sortedValues[] = {-44.0, -33.0, -22.0, -11.0, 0.0, 11.0, 22.0, 33.0, 44.0};
    int i = 0, j = size - 1;
    while (!pq_isEmpty(greaterPQ)) {
        float greaterTop = *(float *) pq_top(greaterPQ);
        float smallerTop = *(float *) pq_top(smallerPQ);

        if (greaterTop != sortedValues[j]) {
            fprintf(stderr, "Test Floats failed. Expected value: %f, Actual value: %f\n", sortedValues[j], greaterTop);
            return 0;
        }
        if (smallerTop != sortedValues[i]) {
            fprintf(stderr, "Test Floats failed. Expected value: %f, Actual value: %f\n", sortedValues[i], smallerTop);
            return 0;
        }

        ++i;
        --j;
        pq_pop(greaterPQ);
        pq_pop(smallerPQ);
    }
    return 1;
}

int testCharPriorityQueue() {
    PriorityQueue *greaterPQ = createPriorityQueue(greaterChar);
    PriorityQueue *smallerPQ = createPriorityQueue(smallerChar);
    char testValues[] = {'O', 'A', 'a', 'M', 'Z', 'K', 'm', 'H', 'Y'};
    int size = sizeof(testValues) / sizeof(char);
    for (int i = 0; i < size; ++i) {
        pq_push(greaterPQ, &testValues[i]);
        pq_push(smallerPQ, &testValues[i]);
    }

    pq_displayOrdered(greaterPQ, toStringChar);
    pq_displayOrdered(smallerPQ, toStringChar);

    // sorted based on ascii values
    char sortedValues[] = {'A', 'H', 'K', 'M', 'O', 'Y', 'Z', 'a', 'm'};
    int i = 0, j = size - 1;
    while (!pq_isEmpty(greaterPQ)) {
        char greaterTop = *(char *) pq_top(greaterPQ);
        char smallerTop = *(char *) pq_top(smallerPQ);
        if (greaterTop != sortedValues[j]) {
            fprintf(stderr, "Test Chars failed. Expected value: %c, Actual value: %c\n", sortedValues[j], greaterTop);
            return 0;
        }
        if (smallerTop != sortedValues[i]) {
            fprintf(stderr, "Test Chars failed. Expected value: %c, Actual value: %c\n", sortedValues[i], smallerTop);
            return 0;
        }
        ++i;
        --j;
        pq_pop(greaterPQ);
        pq_pop(smallerPQ);
    }
    return 1;
}

int testIntPriorityQueueResize() {
    // initial capacity is 2, final capacity is 16
    int finalCapacity = 16;
    PriorityQueue *greaterPQ = createPriorityQueueWithCapacity(greaterInt, 2);
    PriorityQueue *smallerPQ = createPriorityQueueWithCapacity(smallerInt, 2);

    int testValues[] = {44, 33, 22, 11, 0, -11, -22, -33, -44};
    int size = sizeof(testValues) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        pq_push(greaterPQ, &testValues[i]);
        pq_push(smallerPQ, &testValues[i]);
    }

    pq_displayOrdered(greaterPQ, toStringInt);
    pq_displayOrdered(smallerPQ, toStringInt);

    if (greaterPQ->capacity != finalCapacity) {
        fprintf(stderr, "Test Resize failed. Expected capacity for greaterPQ: %d, Actual capacity: %d\n", finalCapacity,
                greaterPQ->capacity);
        return 0;
    }
    if (smallerPQ->capacity != finalCapacity) {
        fprintf(stderr, "Test Resize failed. Expected capacity for smallerPQ: %d, Actual capacity: %d\n", finalCapacity,
                smallerPQ->capacity);
        return 0;
    }

    int sortedValues[] = {-44, -33, -22, -11, 0, 11, 22, 33, 44};
    int i = 0, j = size - 1;
    while (!pq_isEmpty(greaterPQ)) {
        int greaterTop = *(int *) pq_top(greaterPQ);
        int smallerTop = *(int *) pq_top(smallerPQ);
        if (greaterTop != sortedValues[j]) {
            fprintf(stderr, "Test Resize failed. Expected value: %d, Actual value: %d\n", sortedValues[j], greaterTop);
            return 0;
        }
        if (smallerTop != sortedValues[i]) {
            fprintf(stderr, "Test Resize failed. Expected value: %d, Actual value: %d\n", sortedValues[i], smallerTop);
            return 0;
        }
        ++i;
        --j;
        pq_pop(greaterPQ);
        pq_pop(smallerPQ);
    }
    return 1;
}

int main() {
    printf("\t%s\n\n", (testIntPriorityQueue()) ? "Test Integers passed." : "Test Integers failed.");
    printf("\t%s\n\n", (testStringPriorityQueue()) ? "Test Strings passed." : "Test Strings failed.");
    printf("\t%s\n\n", (testFloatPriorityQueue()) ? "Test Floats passed." : "Test Floats failed.");
    printf("\t%s\n\n", (testCharPriorityQueue()) ? "Test Chars passed." : "Test Chars failed.");
    printf("\t%s\n\n",
           (testIntPriorityQueueResize()) ? "Test Integers Resize passed." : "Test Integers Resize failed.");
    return 0;
}