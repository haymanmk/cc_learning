// Library source file - math utilities
#include "math_utils.h"
#include <math.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
