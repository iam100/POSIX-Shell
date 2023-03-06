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

char* present_working_directory() {
    char* pwd;
    char t[1000],a[1000];
    pwd = getcwd(t,sizeof(t));
    if(pwd == NULL) {
        valid_command = false;
        perror("Error in getcwd");
        return NULL;
    }
    else if (strcmp(pwd,home) == 0) {
        return "~";
    }
    else if(strstr(pwd,home) != NULL) {
        // printf("%s\n\n\n",strstr(pwd,home));
        strcpy(a,home);
        strcpy(t,pwd);
        int i,diffrom;
        for(i = 0; i < strlen(pwd);i++ ) {
            if(a[i] == t[i]) {
                continue;
            }
            else{
                diffrom = i;
                break;
            }
        }
        a[0] = '~';
        for(i=diffrom;i<strlen(pwd);i++) {
            a[i-diffrom+1] = t[i];
        }
        a[strlen(pwd) - diffrom+1] = '\0';
        char* pp = a;
        // strcat(pp,pp1);
        return pp;
    }
    else {
        // printf("%s",pwd);
        // printf("\n\n\n%s\n%s\n\n\n",pwd,home);
        return pwd;
    }
}