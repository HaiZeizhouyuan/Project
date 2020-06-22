/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sun Jun 21 19:13:24 2020
 ************************************************************************/

#include<stdio.h>

int add(int a, int b) {
    return a + b;
}

int ret_odd(int n) {
    return 2 * n + 1;
}

int ret_even(int n) {
    return n / 2;
}

int main() {
    int ret = add(3, 5);
    if (ret & 1) {
        printf("ret = %d\n", ret_odd(ret));
    } else {
        printf("ret = %d\n", ret_even(ret));
    }
}
