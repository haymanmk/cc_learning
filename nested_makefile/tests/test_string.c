// String library tests
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "string_utils.h"
#include "test_string.h"

void test_string_reverse() {
    printf("  Testing string_reverse()...");
    
    char* result = string_reverse("hello");
    assert(strcmp(result, "olleh") == 0);
    free(result);
    
    result = string_reverse("a");
    assert(strcmp(result, "a") == 0);
    free(result);
    
    result = string_reverse("");
    assert(strcmp(result, "") == 0);
    free(result);
    
    printf(" PASSED\n");
}

void test_string_upper() {
    printf("  Testing string_upper()...");
    
    char* result = string_upper("hello");
    assert(strcmp(result, "HELLO") == 0);
    free(result);
    
    result = string_upper("Hello World!");
    assert(strcmp(result, "HELLO WORLD!") == 0);
    free(result);
    
    result = string_upper("");
    assert(strcmp(result, "") == 0);
    free(result);
    
    printf(" PASSED\n");
}

void test_string_length() {
    printf("  Testing string_length()...");
    assert(string_length("hello") == 5);
    assert(string_length("") == 0);
    assert(string_length("a") == 1);
    assert(string_length(NULL) == 0);
    printf(" PASSED\n");
}

void run_string_tests() {
    printf("Running String Tests:\n");
    test_string_reverse();
    test_string_upper();
    test_string_length();
    printf("All string tests passed!\n\n");
}
