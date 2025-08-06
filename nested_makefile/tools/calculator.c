// Calculator tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math_utils.h"

int main(int argc, char* argv[]) {
    printf("=== Calculator Tool ===\n");
    
    if (argc != 4) {
        printf("Usage: %s <num1> <operation> <num2>\n", argv[0]);
        printf("Operations: add, multiply, power\n");
        printf("Example: %s 5 add 3\n", argv[0]);
        return 1;
    }
    
    int num1 = atoi(argv[1]);
    char* operation = argv[2];
    int num2 = atoi(argv[3]);
    
    if (strcmp(operation, "add") == 0) {
        printf("%d + %d = %d\n", num1, num2, add(num1, num2));
    } else if (strcmp(operation, "multiply") == 0) {
        printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
    } else if (strcmp(operation, "power") == 0) {
        printf("%d ^ %d = %.2f\n", num1, num2, power(num1, num2));
    } else {
        printf("Unknown operation: %s\n", operation);
        return 1;
    }
    
    return 0;
}
