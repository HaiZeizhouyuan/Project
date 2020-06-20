/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Sun Jun 14 13:46:29 2020
 ************************************************************************/
#ifndef _TEST_H
#define _TEST_H
//__attribute__是优先展开后面内容，
//__attribute__((constructor))优先展这个宏构造后面的函数
#include <haizei/linklist.h>

#define TEST(a, b)\
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()

#define COLOR(a, b)  "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TYPE_STR(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    const char * : "%s",\
    long long : "%lld";\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), "%d");\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    haizei_test_info.total += 1;\
    if (_a comp _b) haizei_test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " "#comp" "#b "\n\t\t" "actual :"));\
        P(_a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(_b,YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------]") " " #a " " #comp " " #b);\
    printf(" %s\n", (a) comp (b) ? GREEN("True") : RED("False"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
typedef void(*TestFuncT)();

typedef struct Function {
    TestFuncT func;
    const char *str;
    Node p;
}Func;

typedef struct FunctionInfo{
    int total, success;
}Info;

extern struct FunctionInfo haizei_test_info;
int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
#endif
