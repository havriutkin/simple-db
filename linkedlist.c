#include "stdlib.h"
#include "datanode.h"
#include "linkedlist.h"


int insert(linkedlist* head, datanode data) {
    // List is empty
    if (head == NULL) {
        head = (linkedlist*) malloc(sizeof(linkedlist));
        head->data = data;
        head->next = NULL;
        return 1;
    }

    // Traverse to the last node
    linkedlist* current = head;
    while (current->next != NULL && current->data.key != data.key){
        current = current->next;
    }

    if (current->data.key == data.key) return 0;
    
    // Allocate memory
    current->next = (linkedlist*) malloc(sizeof(linkedlist));

    // Initialise new node
    current->next->data = data;
    current->next->next = NULL;

    return 1;
}

int get_value_by_key(linkedlist* head, int key){
    if (head == NULL) return -1;

    linkedlist* current = head;

    while (current != NULL && current->data.key != key) {
       current = current->next;
    }

    if (current == NULL) return -1;
    
    return current->data.value;
}

int remove_element(linkedlist** head, int key) {
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

void free_list(linkedlist* head){
    linkedlist* curr = head;

    while (curr != NULL){
        linkedlist* temp = curr;
        curr = curr->next;
        free(temp);
    }
}