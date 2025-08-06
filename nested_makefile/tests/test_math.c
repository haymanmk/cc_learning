// Math library tests
#include <stdio.h>
#include <assert.h>
#include "math_utils.h"
#include "test_math.h"

void test_add() {
    printf("  Testing add()...");
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
    printf(" PASSED\n");
}

void test_multiply() {
    printf("  Testing multiply()...");
    assert(multiply(3, 4) == 12);
    assert(multiply(-2, 3) == -6);
    assert(multiply(0, 5) == 0);
    printf(" PASSED\n");
}

void test_power() {
    printf("  Testing power()...");
    assert(power(2, 3) == 8.0);
    assert(power(5, 0) == 1.0);
    assert(power(10, 2) == 100.0);
    printf(" PASSED\n");
}

void test_factorial() {
    printf("  Testing factorial()...");
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
    printf(" PASSED\n");
}

void run_math_tests() {
    printf("Running Math Tests:\n");
    test_add();
    test_multiply();
    test_power();
    test_factorial();
    printf("All math tests passed!\n\n");
}
