#include "stdlib.h"
#include "utils.h"
#include "math.h"

int is_prime(int number){

    if (number == 1) return 0;

    int square_root = ceil(sqrt(number));
    for (int i = 2; i < square_root; i++){
        if (number % i == 0) return 0;
    }

    return 1;
}

int get_next_prime(int number){
    int curr = number + 1;
    while (is_prime(curr) != 1) {
       curr += 1;
    }
    return curr;
}

