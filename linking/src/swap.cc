#include <iostream>

extern int buf[];

int *p_buf_0 {&buf[0]};
int *p_buf_1;

void swap() {
    int temp;

    p_buf_1 = &buf[1];
    temp = *p_buf_0;
    *p_buf_0 = *p_buf_1;
    *p_buf_1 = temp;
}