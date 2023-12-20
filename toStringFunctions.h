//
// Created by Omar on 20/12/2023.
//

#ifndef CPRIORITYQUEUE_TOSTRINGFUNCTIONS_H
#define CPRIORITYQUEUE_TOSTRINGFUNCTIONS_H

typedef char *(*ToStringFunction)(void *);

char *toStringInt(void *a);

char *toStringStr(void *a);

char *toStringFloat(void *a);

char *toStringLongLong(void *a);

char *toStringDouble(void *a);

char *toStringShort(void *a);

char *toStringChar(void *a);

#endif //CPRIORITYQUEUE_TOSTRINGFUNCTIONS_H
