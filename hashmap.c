#include "stdlib.h"
#include "hashmap.h"
#include "utils.h"

int hash_function(int prime, int value){
    return (value % prime);
}

int get_value(hashmap* map, int key){
    int index = hash_function(map->capacity, key);
    return get_value_by_key(*(map->data + index), key);
}

int insert_value(hashmap* map, int key, int value){
    int index = hash_function(map->capacity, key);

    datanode data;
    data.key = key;
    data.value = value;

    if (insert(*(map->data + index), data) == 1){
        map->size += 1;
        return 1;
    } else {
        return 0;
    }
}

void rehash(hashmap* map){
    int old_capacity = map->capacity;
    linkedlist** old_data = map->data;

    map->size = 0;
    map->capacity = get_next_prime(map->capacity);
    map->data = (linkedlist**) malloc(map->capacity * sizeof(linkedlist*));

    // Initialize the new data array with NULL values
    for (int i = 0; i < map->capacity; i++) {
        *(map->data + i) = NULL;
    }

    for (size_t i = 0; i < old_capacity; i++) {
        linkedlist* curr = *(old_data + i);
        while (curr != NULL){
            insert_value(map, curr->data.key, curr->data.value);
            linkedlist* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(old_data);    
}