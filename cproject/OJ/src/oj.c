#include <stdio.h>
#include<string.h>
#include "run.h"

int main()
{
	const char *name_program = "./program";
	const char *name_in = "./in.txt";
	const char *name_out = "./out.txt";
	const char *name_right = "./right.txt";
	run(name_program, name_in, name_out);
	FILE *fpright = fopen(name_right, "r");
	FILE *fpout = fopen(name_out, "r");

	// Input your code here.
    char str1, str2;
    int ret1, ret2;
    int flag = 1;
    while(flag == 1) {
        ret1 = fscanf(fpright, "%c", &str1);
        ret2 = fscanf(fpout, "%c", &str2);
        if (ret1 == EOF ||ret2 == EOF) break;
        if (str1 != str2) flag = 0;
    }

    if (flag == 1) {
        if (ret1 != EOF || ret2 != EOF) {
            if ((ret1 != EOF && str1 == '\n') ||( ret2 != EOF && str2 == '\n')) {
                ret1 = fscanf((ret1 != EOF ? fpright : fpout), "%c", &str1);
                flag = (ret1 == EOF ? 1 : 0);
            } else {
                flag = 0;
            }
        }
    }
    printf("%s", flag ? "Accept" : "Wrong Answer");
	fclose(fpout);
	fclose(fpright);
	return 0;
}
