#include <iostream>

int f() {
    static int x = 0;
    return x++;
}

int g() {
    static int x;
    return x++;
}