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

void pinfo() {
    char name[500],a[200],t[200];
    int id,size;
    char stat[100];
    char process[100];
    char virtm[100];
    char exec[100];
    if(args[1] == NULL) {
        strcpy(process,"/proc/self/stat");
        strcpy(virtm,"/proc/self/statm");
        strcpy(exec,"/proc/self/exe");
    }
    else {
        strcpy(process,"/proc/");
        strcpy(virtm,"/proc/");
        strcpy(exec,"/proc/");
        strcat(process,args[1]);
        strcat(virtm,args[1]);
        strcat(exec,args[1]);
        strcat(process,"/stat");
        strcat(virtm,"/statm");
        strcat(exec,"/exe");
    }
        FILE* n = fopen(process,"r");
        if(n == NULL) {
            valid_command = false;
            perror("Error in fopen");
            return;
        }
        else {
            fscanf(n,"%d %s %s",&id,name,stat);
            printf("pid\t%d\n",id);
            printf("Process Status\t%s\n",stat);
        }
        fclose(n);
        n = fopen(virtm,"r");
        if (n == NULL) {
        valid_command = false;
            perror("Error in fopen");
            return;
        }
        else {
            fscanf(n,"%d",&size);
            printf("memory\t%d\n",size);
        }
        fclose(n);
        for(int i = 0;i < sizeof(name) ; i++) {
            name[i] = '\0';
        }
        readlink(exec,name,sizeof(name));
        // printf("%d\n",sizeof(name));
        // char* name1 = name;
        if(strstr(name,home) != NULL) {
            strcpy(a,home);
            strcpy(t,name);
            int i,diffrom;
            for(i = 0; i < strlen(name);i++ ) {
                if(a[i] == t[i]) {
                    printf("%c\t%c\n",a[i],t[i]);
                    continue;
                }
                else{
                    diffrom = i;
                    break;
                }
            }
            a[0] = '~';
            // printf("%d\n",diffrom);
            for(i=diffrom;i<strlen(name);i++) {
                a[i-diffrom+1] = t[i];
            }
            a[strlen(name)-diffrom+1] = '\0';
        }
        else {
            strcpy(a,name);
        }
    printf("Executable path\t%s\n",a);
}