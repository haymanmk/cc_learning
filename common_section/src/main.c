#include "lib_1.h"
#include "lib_2.h"

int main(void)
{
    lib1_set_global_var(1);
    lib2_set_global_var(2);
    lib1_print_global_var();
    lib2_print_global_var();
    return 0;
}