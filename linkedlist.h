#ifndef linkedlist_h
#define linkedlist_h

#include "datanode.h"

typedef struct {
    datanode data;
    linkedlist* next;
} linkedlist;

void insert(linkedlist* head, datanode data);

// Returns 1 if removed successfully, returns 0 otherwise
int remove(linkedlist** head, int key);

#endif