#include <stdio.h>
#include "lib_1.h"

uint8_t global_var;

void lib1_print_global_var(void)
{
    printf("global_var = %d\n", global_var);
}

void lib1_set_global_var(uint8_t value)
{
    global_var = value;
}