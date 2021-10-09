#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <cctype>

int main(int argc, char *argv[])
{
    char grep_by_name[120] = "";

    if (argc>1 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        printf("usage: %s [proc_name]\n", argv[0]);
        return 0;
    }

    if (argc>1) {
        sprintf(grep_by_name, "| grep %s", argv[1]);
    }

    char cmd[512];
    sprintf(cmd, "ps -eLo \"psr stat pid lwp cmd\" %s", grep_by_name);

    printf("will execute: %s\n", cmd);

    FILE* fp = NULL;
    if ((fp = popen(cmd, "r")) == NULL){
        printf("read failed.\n");
    }

    constexpr int cores = 48;
    constexpr char stat_patterns[] = "RSD";
    constexpr char const *explain[] = {"runnable", "interruptible", "uninterruptible", "total"};

    int count[cores+1][sizeof(stat_patterns)] = {};
    int total = 0;

    while(fgets(cmd, sizeof(cmd), fp)) {
        if (isalpha(cmd[0])) { // table header
            continue;
        }
        int psr;
        char stat[10];
        
        sscanf(cmd, "%d %s", &psr, stat);
        //printf("psr = %d, stat=%s\n", psr, stat);
        
        ++total;
        for (int i=0; i<sizeof(stat_patterns)-1; ++i) {
            if (strchr(stat, stat_patterns[i])) {
                count[psr][i]++;
                count[psr][sizeof(stat_patterns)-1]++;
                count[cores][i]++;
                count[cores][sizeof(stat_patterns)-1]++;
            }
        }
    }
    
    printf("total %d threads\n", total);
    for (int i=0; i<=cores; ++i) {
        if (i<cores) {
            printf("cpu %2d: ", i);
        } else {
            printf(" total: ", i);
        }
        
        for (int j=0; j<sizeof(stat_patterns); ++j) {
            printf("%s:%-2d   ", explain[j], count[i][j]);
        }
        printf("\n");
    }

    pclose(fp);

    return 0;
}
