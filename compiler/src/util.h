
#pragma once

#include <assert.h>

typedef char *string;
string String(char *);

typedef char cbool;

#define TRUE 1
#define FALSE 0

void *checked_malloc(int len) {
    void *p = malloc(len);
    assert(p);
    return p;
}
