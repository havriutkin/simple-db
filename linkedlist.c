#include "stdlib.h"
#include "datanode.h"
#include "linkedlist.h"


void insert(linkedlist* head, datanode data) {
    // Traverse to the last node
    linkedlist* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    
    // Allocate memory
    current->next = (linkedlist*) malloc(sizeof(linkedlist));

    // Initialise new node
    current->next->data = data;
    current->next->next = NULL;
}

int get_value_by_key(linkedlist* head, int key){
    linkedlist* current = head;

    while (current != NULL && current->data.key != key) {
       current = current->next;
    }

    if (current == NULL) return -1;
    
    return current->data.value;
}

int remove(linkedlist** head, int key) {
    // List is empty
    if (*head == NULL) return 0;
    
    linkedlist* current = *head;

    // Sought element is first
    if (current->data.key == key){
        *head = current->next;
        free(current);
        return 1;
    }

    // Traverse through list
    while (current->next != NULL && current->next->data.key != key) {
        current = current->next;
    }

    // There is no such an element
    if (current->next == NULL) return 0;

    // Remove sought element
    linkedlist* sought_element = current->next;
    current->next = sought_element->next;
    free(sought_element);

    return 1;
}