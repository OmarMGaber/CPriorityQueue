//
// Created by Omar on 20/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "toStringFunctions.h"


char *toStringInt(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%d", *(int *) element);
    return string;
}

char *toStringFloat(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%f", *(float *) element);
    return string;
}

char *toStringLongLong(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%lld", *(long long *) element);
    return string;
}

char *toStringDouble(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%lf", *(double *) element);
    return string;
}

char *toStringShort(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%hd", *(short *) element);
    return string;
}

char *toStringStr(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%s", (char *) element);
    return string;
}

char *toStringChar(void *element) {
    char *string = (char *) malloc(12 * sizeof(char));
    sprintf(string, "%c", *(char *) element);
    return string;
}
