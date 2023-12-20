//
// Created by Omar on 03/12/2023.
//

/*
 *
 * Priority Queue
 * This is a generic priority queue implementation using a heap.
 * It has compare functions for the C data types: int, float, double, long long, short, and char *.
 *
 * GitHub: OmarMGaber
 */

#include <stdio.h>
#include <stdlib.h>
#include "compareFunctions.h"
#include "toStringFunctions.h"
#include "priorityQueue.h"
#include <string.h>

void heapifyUp(PriorityQueue *pq, int childIndex);

void heapifyDown(PriorityQueue *pq, int parentIndex);

PriorityQueue *createPriorityQueue(CompareFunction compare) {
    return createPriorityQueueWithCapacity(compare, DEFAULT_PRIORITY_QUEUE_CAPACITY);
}

PriorityQueue *createPriorityQueueWithCapacity(CompareFunction compare, size_t capacity) {
    PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    ENSURE_NON_NULL(pq, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    pq->heapArray = (void **) malloc(capacity * sizeof(void *));
    ENSURE_NON_NULL(pq->heapArray, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    pq->size = 0;
    pq->indexOfLastElement = 0;
    pq->capacity = capacity;
    pq->compare = compare;
    return pq;
}

void *resizePriorityQueue(PriorityQueue *pq) {
    pq->capacity *= 2;
    pq->heapArray = realloc(pq->heapArray, pq->capacity * sizeof(void *));
    ENSURE_NON_NULL(pq->heapArray, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    return NULL;
}

void *pq_top(PriorityQueue *pq) {
    if (pq_isEmpty(pq)) {
        REPORT_ERROR_AND_EXIT(EMPTY_PRIORITY_QUEUE_ERROR_MESSAGE, EXIT_FAILURE)
    }

    return pq->heapArray[0];
}

void pq_pop(PriorityQueue *pq) {
    if (pq_isEmpty(pq)) {
        REPORT_ERROR_AND_EXIT(EMPTY_PRIORITY_QUEUE_ERROR_MESSAGE, EXIT_FAILURE)
    }

    pq->heapArray[0] = pq->heapArray[pq->indexOfLastElement - 1];
    --pq->indexOfLastElement;
    --pq->size;
    heapifyDown(pq, 0);
}

void pq_push(PriorityQueue *pq, void *element) {
    if (hasReachedCapacity(pq))
        resizePriorityQueue(pq);

    pq->heapArray[pq->indexOfLastElement] = element;
    heapifyUp(pq, pq->indexOfLastElement);
    ++pq->size;
    ++pq->indexOfLastElement;
}

void heapifyUp(PriorityQueue *pq, int childIndex) {
    int parentIndex = getParentIndex(childIndex);
    while (hasParent(childIndex) && hasHigherPriority(pq, childIndex, parentIndex)) {
        SWAP_VALUES(pq, parentIndex, childIndex);
        childIndex = parentIndex;
        parentIndex = getParentIndex(childIndex);
    }
}

void heapifyDown(PriorityQueue *pq, int parentIndex) {
    while (hasLeftChild(pq, parentIndex)) {
        int higherPriorityChildIndex = getLeftChildIndex(parentIndex);
        if (hasRightChild(pq, parentIndex) &&
            hasHigherPriority(pq, getRightChildIndex(parentIndex), higherPriorityChildIndex))
            higherPriorityChildIndex = getRightChildIndex(parentIndex);

        if (hasHigherPriority(pq, parentIndex, higherPriorityChildIndex))
            break;
        else SWAP_VALUES(pq, parentIndex, higherPriorityChildIndex);

        parentIndex = higherPriorityChildIndex;
    }
}

// Debugging function
void printHeapTree(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    int level = 0;
    int levelSize = 1;
    int index = 0;
    while (index < pq->size) {
        for (int i = 0; i < levelSize && index < pq->size; i++) {
            printf("%s ", toStringFunction(pq->heapArray[index]));
            index++;
        }
        printf("\n");
        level++;
        levelSize *= 2;
    }
}

PriorityQueue *pq_copy(PriorityQueue *pq) {
    PriorityQueue *copy = createPriorityQueueWithCapacity(pq->compare, pq->capacity);
    copy->size = pq->size;
    copy->indexOfLastElement = pq->indexOfLastElement;
    for (int i = 0; i < pq->size; ++i) {
        copy->heapArray[i] = pq->heapArray[i];
    }

    return copy;
}

char *pq_toStringOrdered(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    PriorityQueue *copy = pq_copy(pq);
    char *string = malloc(1); // 1 byte for the null terminator
    ENSURE_NON_NULL(string, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    string[0] = '\0';
    while (!pq_isEmpty(copy)) {
        char *elementString = toStringFunction(pq_top(copy));
        string = realloc(string, strlen(string) + strlen(elementString) + 1);
        ENSURE_NON_NULL(string, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

        strcat(string, elementString);
        strcat(string, " ");
        free(elementString);
        pq_pop(copy);
    }

    pq_destroy(copy);
    return string;
}

void pq_displayOrdered(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    printf("Priority Queue: %s\n", pq_toStringOrdered(pq, toStringFunction));
}

void pq_display(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    printf("Priority Queue: %s\n", pq_toString(pq, toStringFunction));
}

char *pq_toString(PriorityQueue *pq, char *(*toStringFunction)(void *)) {
    char *string = malloc(1); // 1 byte for the null terminator
    ENSURE_NON_NULL(string, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

    string[0] = '\0';
    for (int i = 0; i < pq->size; ++i) {
        char *elementString = toStringFunction(pq->heapArray[i]);
        string = realloc(string, strlen(string) + strlen(elementString) + 1);
        ENSURE_NON_NULL(string, OUT_OF_MEMORY_ERROR_MESSAGE, EXIT_FAILURE)

        strcat(string, elementString);
        strcat(string, " ");
        free(elementString);
    }

    return string;
}

void pq_destroy(PriorityQueue *pq) {
    free(pq->heapArray);
    free(pq);
}
