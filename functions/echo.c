#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include "declarations.h"

void echo_fun(void) {
    if(args[1] == NULL) {
        printf("\n");
    }
    else {
        int i;
        for(i = 1; i < 30; i++){
            if (args[i] == NULL) break;
            else {
                printf("%s ",args[i]); 
                // printf(" ");
            }
        }
        printf("\n");
    }
}

