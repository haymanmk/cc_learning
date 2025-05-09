#include <stdio.h>
#include <string.h>
#include "utils.h"

#define A(id, _) UTIL_CAT(a, id)

const int a0 = 0;
const int a1 = 1;
const int a2 = 2;
const int a3 = 3;
const int a4 = 4;
const int a5 = 5;

int arr[6] = { LISTIFY(6, A, (,)) };

void main(void) {
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

}