#ifndef linkedlist_h
#define linkedlist_h

#include "datanode.h"

typedef struct {
    datanode data;
    linkedlist* next;
} linkedlist;

// Inserts new node in list
void insert(linkedlist* head, datanode data);

// Returns value by given key, return -1 if there is no such a key
int get_value_by_key(linkedlist* head, int key);

// Returns 1 if removed successfully, returns 0 otherwise
int remove(linkedlist** head, int key);

#endif