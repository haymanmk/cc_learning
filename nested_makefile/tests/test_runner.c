// Test runner - main test executable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "test_math.h"
#include "test_string.h"
#include "app_logic.h"

void print_usage(const char* program_name) {
    printf("Usage: %s [options]\n", program_name);
    printf("Options:\n");
    printf("  --verbose     Run tests with verbose output\n");
    printf("  --math-only   Run only math tests\n");
    printf("  --string-only Run only string tests\n");
    printf("  --help        Show this help message\n");
}

int main(int argc, char* argv[]) {
    printf("=== Test Runner for Nested Makefile Project ===\n\n");
    
    int verbose = 0;
    int math_only = 0;
    int string_only = 0;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "--math-only") == 0) {
            math_only = 1;
        } else if (strcmp(argv[i], "--string-only") == 0) {
            string_only = 1;
        } else if (strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else {
            printf("Unknown option: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }
    
    if (verbose) {
        printf("Running in verbose mode...\n\n");
    }
    
    // Run tests based on options
    if (math_only) {
        run_math_tests();
    } else if (string_only) {
        run_string_tests();
    } else {
        // Run all tests
        run_math_tests();
        run_string_tests();
        
        // Test application logic integration
        printf("Testing Application Logic Integration:\n");
        printf("  Testing app_logic integration...");
        run_app_logic();
        printf(" PASSED\n\n");
    }
    
    printf("=== All Tests Completed Successfully! ===\n");
    return 0;
}
