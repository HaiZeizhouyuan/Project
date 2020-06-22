#include <stdio.h>
#include "roman.h"
int main(int argc, char *argv[]) {
    if (argc == 1) return 0;
    int type = (argv[1][1] == 'd');
    FILE *fin = stdin;
    FILE *fout = stdout;
    if (argc >= 3) {
        fin = fopen(argv[2], "r");
    }
    if (argc == 4) {
        fout = fopen(argv[3], "w");
    }
    char str[1000];
    int line_num = 1;
    while (fscanf(fin, "%[^\n]s", str) != EOF) {
        fgetc(fin);
        if (type) {
            fprintf(fout, "%d\t%s\n", line_num++, str);
        } else {
            char dst[25];
            to_roman_numeral(dst, line_num++);
            fprintf(fout, "%s\t%s\n", dst, str);
        }
        str[0] = 0;
    }
	return 0;
}
