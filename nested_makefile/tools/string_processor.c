// String processor tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

int main(int argc, char* argv[]) {
    printf("=== String Processor Tool ===\n");
    
    if (argc != 3) {
        printf("Usage: %s <operation> <string>\n", argv[0]);
        printf("Operations: reverse, upper, length\n");
        printf("Example: %s reverse \"Hello World\"\n", argv[0]);
        return 1;
    }
    
    char* operation = argv[1];
    char* input_string = argv[2];
    
    if (strcmp(operation, "reverse") == 0) {
        char* result = string_reverse(input_string);
        printf("Original: %s\n", input_string);
        printf("Reversed: %s\n", result);
        free(result);
    } else if (strcmp(operation, "upper") == 0) {
        char* result = string_upper(input_string);
        printf("Original: %s\n", input_string);
        printf("Uppercase: %s\n", result);
        free(result);
    } else if (strcmp(operation, "length") == 0) {
        int length = string_length(input_string);
        printf("String: %s\n", input_string);
        printf("Length: %d\n", length);
    } else {
        printf("Unknown operation: %s\n", operation);
        return 1;
    }
    
    return 0;
}
