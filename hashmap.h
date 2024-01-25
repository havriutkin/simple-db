#ifndef hashmap_h
#define hashmap_h

#include "datanode.h"
#include "linkedlist.h"

typedef struct {
    linkedlist** data;       // Array of linked lists with key-value pairs
    int capacity;           // Allocated memory
    int size;               // Number of elements in array
} hashmap;

// Hashing function
int hash_function(int prime, int value);

// Returns value by given key, returns -1 if there is no such a key;
int get_value(hashmap* map, int key);

// Inserts value to the given key. Returns 1 if success, 0 if error (key already exists)
int insert_value(hashmap* map, int key, int value);

// Rehash map with a bigger prime number
void rehash(hashmap* map);


#endif