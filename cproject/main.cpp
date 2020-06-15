/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun Jun 14 13:38:12 2020
 ************************************************************************/

#include<stdio.h>
#include<haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST (testFunc, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_NE(add(3, 6), 8);
    EXPECT_GE(add(2, 7), 9);
}
TEST (testFunc, add2) {
    EXPECT_LT(add(1, 2), 3);
    EXPECT_LE(add(2, 3), 6);
    
}
int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
