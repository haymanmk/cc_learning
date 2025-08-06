// Main application file
#include <stdio.h>
#include <stdlib.h>
#include "math_utils.h"
#include "string_utils.h"
#include "app_logic.h"

int main() {
    printf("=== Nested Makefile Example Application ===\n\n");
    
    // Test math functions from library
    printf("Math Library Tests:\n");
    printf("add(5, 3) = %d\n", add(5, 3));
    printf("multiply(4, 7) = %d\n", multiply(4, 7));
    printf("power(2, 3) = %.2f\n", power(2, 3));
    printf("factorial(5) = %d\n", factorial(5));
    
    printf("\n");
    
    // Test string functions from library
    printf("String Library Tests:\n");
    const char* test_str = "Hello World";
    printf("Original string: %s\n", test_str);
    printf("Length: %d\n", string_length(test_str));
    
    char* reversed = string_reverse(test_str);
    printf("Reversed: %s\n", reversed);
    free(reversed);
    
    char* upper = string_upper(test_str);
    printf("Uppercase: %s\n", upper);
    free(upper);
    
    printf("\n");
    
    // Test application logic
    printf("Application Logic Tests:\n");
    run_app_logic();
    
    return 0;
}
