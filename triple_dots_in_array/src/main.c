#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
    int a[ARRAY_SIZE] = {
        [0 ... (ARRAY_SIZE - 1)] = 3}; // all the elements are initialized to 3

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}