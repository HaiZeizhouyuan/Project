/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Sun Jun 14 13:46:29 2020
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b)\
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()

#define COLOR(a, b)  "\003[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033{1;" #b "m" a"\033[0m"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR(a, 32)
#define RED_HL(a) COLOR(a, 31)
#define BLUE_HL(a) COLOR(a, 34)
#define YELLOW_HL(a) COLOR(a, 33)
#define EXPECT(a, b, comp) {\
    printf(GREEN("[-----------]") " " #a " " #comp " " #b);\
    printf("%s\n", (a) comp (b) ? GREEN("True") : RED("False"));\
    t++;\
    if (((a) comp (b) ? "True" : "False") == "True") s++;\
    p = 100 * s % t;\
}\

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
typedef void(*TestFuncT)();

struct Function {
    TestFuncT func;
    const char *str;
};

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
#endif
