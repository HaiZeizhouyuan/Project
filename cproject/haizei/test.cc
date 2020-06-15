#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
Function func_arr[100];
int func_cnt = 0;

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf(GREEN("[===RUN===]")  RED_HL("%s\n"), func_arr[i].str);
        printf(GREEN("[----------]") "\n");
        func_arr[i].func();
        printf(BLUE_HL("End Run\n"));
    }
    printf("GREEN('[  %d  ]') total : %d  success : %d", p, t, s);
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return ;
    
}
