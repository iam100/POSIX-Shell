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


void back_check() {
    int sta;
    // wpid = waitpid(-1,&sta,WNOHANG);
    while ((wpid = waitpid(-1,&sta,WNOHANG))> 0) {
        
        int i = 0;
        while(i < n_back_proc) {
            if(bkg_proc[i].pid == wpid) {
                printf("DONE [%d]-\t\t%s\t\tPID:%d",bkg_proc[i].jid,bkg_proc[i].command,bkg_proc[i].pid);
            }
            i++;
        }        
    }
    
}