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

void background_proc() {
    char tmp[30][1000];
    for(int i = 0; i< n_args;i++) strcpy(tmp[i],args[i]);
    if(strcmp(args[n_args-1],"&") == 0 && args[n_args-1] != NULL) {
        background = true;
        args[n_args-1] = NULL;
        n_args--;
        // printf("%d",n_args);
    }
    // printf("%d\n\n",n_args);
    int sta;
    pid = fork();
    pid_t wpid;
    if(pid < 0) {
        valid_command = false;
        perror("Error in fork");
        return;
    }
    else if(pid == 0) {
        for(int i = 0; i< n_args;i++) strcpy(args[i],tmp[i]);
        if(background) {
            setpgid(0,0);
        }

    //    printf("%s\n\n",args[0]);
       if(execvp(args[0],args) == -1) {
        valid_command = false;
           perror("Error in execvp");
           exit(0);
           return;
       }
    //    printf("%s\n\n",args[0]);

       exit(0);
    }
    else {
        if(!background) {
            wpid = waitpid(pid,&sta,WUNTRACED);
            while (!background) {
                if(WIFEXITED(sta) && WIFSIGNALED(sta)) wpid = waitpid(pid,&sta,WUNTRACED);
                else break;
            }
        }
        else {
            bkg_proc[n_back_proc].pid = pid;
            bkg_proc[n_back_proc].active = true;
            bkg_proc[n_back_proc].jid = n_back_proc + 1;

            strcpy(bkg_proc[n_back_proc].command,args[0]);

            printf("BEGUN [%d]+\t\t%s\t\tPID:%d\n",n_back_proc++,args[0],pid);
            pid = 0;
        }
    }
}