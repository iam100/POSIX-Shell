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


void dir_change(char* path) {
    char tmp[1000];
    int flag = 0;
    if(strcmp(path,"..") == 0){
        strcpy(tmp,present_working_directory());
        // int len = sizeof(path);
        // char* new_path;
        int len = strlen(tmp);
        for(int i=len-1;i>0;i--) {
            if(path[i] == '/') {
                printf("%s\n",path[i]);
                path[i] = '\0';
                i = -22;
            }
        }
        flag = chdir(path);
        // printf("%s\n",path);

    }
    else if(strcmp(path,".") == 0) {
        printf("");
    }
    else {
        flag = chdir(path);
        // printf("%s\n",path);
    }
    if(flag) {
        valid_command = false;
        perror("Error in cd");
    }
}
