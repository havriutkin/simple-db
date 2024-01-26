#ifndef linkedlist_h
#define linkedlist_h

#include "datanode.h"

typedef struct linkedlist {
    datanode data;
    struct linkedlist* next;
} linkedlist;

// Inserts new node in list. Returns 1 if success, 0 if key already exists
int insert(linkedlist* head, datanode data);

// Returns value by given key, return -1 if there is no such a key
int get_value_by_key(linkedlist* head, int key);

// Returns 1 if removed successfully, returns 0 otherwise
int remove_element(linkedlist** head, int key);

// Free all nodes
void free_list(linkedlist* head);

#endif