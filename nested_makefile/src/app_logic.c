// Application logic
#include "app_logic.h"
#include "math_utils.h"
#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

void run_app_logic() {
    printf("Running application-specific logic...\n");
    
    // Demonstrate combining library functions
    int result = multiply(add(3, 4), 2);
    printf("Complex calculation: multiply(add(3, 4), 2) = %d\n", result);
    
    // String processing
    const char* message = "nested makefiles";
    char* upper_message = string_upper(message);
    char* reversed_message = string_reverse(upper_message);
    
    printf("Processing message: '%s'\n", message);
    printf("After uppercase: '%s'\n", upper_message);
    printf("After reverse: '%s'\n", reversed_message);
    
    free(upper_message);
    free(reversed_message);
    
    printf("Application logic completed!\n");
}
