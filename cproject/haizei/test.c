#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <haizei/linklist.h>
Func func_head, *func_tail = &func_head;
Info haizei_test_info;

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
        Func *func = Head(p, Func, p);
        printf(GREEN_HL("[====RUN====]") RED(" %s\n"), func->str);
        haizei_test_info.total = haizei_test_info.success = 0;
        func->func();

        double rate = haizei_test_info.success * 100.0 / haizei_test_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate); 
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]"));
        printf(
            " total : %d  success : %d\n",
               haizei_test_info.total,
               haizei_test_info.success
              );

    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    Func *temp = (Func *)calloc(1, sizeof(Func));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
    
}
