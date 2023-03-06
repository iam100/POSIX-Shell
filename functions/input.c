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

void read_input() {

    // free(args);
    fflush(stdout);
    size_t inp_size = 23;
    int len_args;

    // free(input);
    int length = getline(&input,&inp_size,stdin);
    input[length] = '\0';

    char* token = strtok(input,delimters);
    for(len_args = 0;token != NULL; len_args++) {
        args[len_args] = token;
        token = strtok(NULL,delimters);
        // printf("%s\n",args[len_args]);
    }
    // printf("%d\n",len_args);
    n_args = len_args;
    args[n_args] = NULL;
}

