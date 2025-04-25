#include <stdio.h>
#include "lib_2.h"

uint8_t global_var;

void lib2_print_global_var(void)
{
    printf("global_var = %d\n", global_var);
}

void lib2_set_global_var(uint8_t value)
{
    global_var = value;
}