#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "hashmap.h"

#define MAX_INPUT_LENGTH 1024
/*
TODO: 
    - REPL
    - SAVING IN MEMORY
    ....
    ....
    - SAVING IN FILE
*/

int main(){
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("mydb> ");
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL){
            printf("error");
            break;  // Error occured
        } 

        input[strcspn(input, "\n")] = 0;    // Delete new line character

        if (strcmp(input, ".exit") == 0) {
            break;
        } else {
            printf("mydb> %s \n", input);
        }
    }
    

    return 0;
}