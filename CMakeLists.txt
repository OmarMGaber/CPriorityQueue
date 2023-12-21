cmake_minimum_required(VERSION 3.26)
project(CPriorityQueue C)

set(CMAKE_C_STANDARD 23)

add_executable(CPriorityQueue test/test_priorityQueue.c
        priorityQueue.c
        priorityQueue.h
        compareFunctions.c
        compareFunctions.h
        toStringFunctions.h
        toStringFunctions.c
        priorityQueue.c
        priorityQueue.c
        priorityQueue.c
)
