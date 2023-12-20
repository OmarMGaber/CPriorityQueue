//
// Created by Omar on 03/12/2023.
//

#ifndef CPU_SCHEDULING_SIMULATOR_PRIORITY_QUEUE_H
#define CPU_SCHEDULING_SIMULATOR_PRIORITY_QUEUE_H

#include <stdio.h>
#include <malloc.h>
#include "compareFunctions.h"

// priority queue exit codes and messages
#define EMPTY_PRIORITY_QUEUE_ERROR_MESSAGE "Priority queue is empty."
#define OUT_OF_MEMORY_ERROR_MESSAGE "Out of memory."
#define REPORT_ERROR_AND_EXIT(MESSAGE, EXIT_CODE) fprintf(stderr, MESSAGE); \
                                                                exit(EXIT_CODE);
#define ENSURE_NON_NULL(ptr, MESSAGE, EXIT_CODE) if (ptr == NULL) { \
                                                    fprintf(stderr, MESSAGE); \
                                                    exit(EXIT_CODE); \
                                                }

// priority queue function-like macros and constants
#define DEFAULT_PRIORITY_QUEUE_CAPACITY 100
#define getParentIndex(i) ((i - 1) / 2)
#define getLeftChildIndex(i) ((2 * i) + 1)
#define getRightChildIndex(i) ((2 * i) + 2)
#define hasHigherPriority(pq, parentIndex, childIndex) pq->compare(pq->heapArray[parentIndex], pq->heapArray[childIndex]) < 0
#define pq_isEmpty(priorityQueue) (priorityQueue->size == 0)
#define hasReachedCapacity(priorityQueue) (priorityQueue->size == priorityQueue->capacity)
#define hasParent(i) (i > 0)
#define hasLeftChild(priorityQueue, i) (getLeftChildIndex(i) < priorityQueue->size)
#define hasRightChild(priorityQueue, i) (getRightChildIndex(i) < priorityQueue->size)
#define getLeftChild(priorityQueue, i) (priorityQueue->heapArray[getLeftChildIndex(i)])
#define getRightChild(priorityQueue, i) (priorityQueue->heapArray[getRightChildIndex(i)])
#define getParent(priorityQueue, i) (priorityQueue->heapArray[getParentIndex(i)])
#define SWAP_VALUES(priorityQueue, i, j) {void *temp = priorityQueue->heapArray[i]; \
                                    priorityQueue->heapArray[i] = priorityQueue->heapArray[j];               \
                                    priorityQueue->heapArray[j] = temp;}

typedef struct {
    void **heapArray;
    size_t size;
    size_t capacity;
    int indexOfLastElement;
    CompareFunction compare;
} PriorityQueue;

// Function prototypes
PriorityQueue *createPriorityQueue(CompareFunction compare);

PriorityQueue *createPriorityQueueWithCapacity(CompareFunction compare, size_t capacity);

// pq_ prefix stands for priority queue functions to avoid name collisions
void pq_push(PriorityQueue *pq, void *element);

void *pq_top(PriorityQueue *pq);

void pq_pop(PriorityQueue *pq);

PriorityQueue *pq_copy(PriorityQueue *pq);

char *pq_toString(PriorityQueue *pq, char *(*toStringFunction)(void *));

char *pq_toStringOrdered(PriorityQueue *pq, char *(*toStringFunction)(void *));

void pq_display(PriorityQueue *pq, char *(*toStringFunction)(void *));

void pq_displayOrdered(PriorityQueue *pq, char *(*toStringFunction)(void *));

// TODO: implement heapSort
//void heapSort(void *array, size_t size, size_t sizeOfElement, CompareFunction compare);

void pq_destroy(PriorityQueue *pq);

void printHeapTree(PriorityQueue *pq, char *(*toStringFunction)(void *));


#endif //CPU_SCHEDULING_SIMULATOR_PRIORITY_QUEUE_H
