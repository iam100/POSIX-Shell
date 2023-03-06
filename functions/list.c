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

void list_fi(void) {
    struct dirent **dir_list;
    int n;
    char path[100];
    int flag = 0;
    path[0] = '.';
    path[1] = '/';
    path[2] = '\0';
    if(args[1] != NULL) {
        if(strcmp(args[1],"-l") != 0 && strcmp(args[1],"-a") != 0 && strcmp(args[1],"-la") !=0 && strcmp(args[1],"-al") !=0 ) {
            if(args[1][0] == '-') {
                valid_command = false;
                printf("Unknown flag\n");
                return;
            }
            else if(strcmp(args[1],"~") != 0) {
                strcpy(path,args[1]);
            // printf("%c\n",args[1][0]);
            }
            else {
                strcpy(path,home);
            }
            flag = 1;
        }
        else if(args[2] != NULL) {
            strcpy(path,args[2]);
        }
    }
    for(int i = 0;i<100;i++) {
        if(path[i] == '\0') {
            if(path[i-1] == '/') {
                break;
            }
            else if(path[i-1] != '/') {
                path[i] = '/';
                path[i+1] = '\0';
                break;
            }
        }
    }
    if(args[1] == NULL || flag == 1) {
        n = scandir(path,&dir_list,0,alphasort);
        if (n==-1) {
        valid_command = false;
            perror("Error in scandir");
            return;
        }
        while(n--) {
            if(dir_list[n]->d_name[0] != '.')
            {
                if(dir_list[n]->d_type == DT_DIR) {
                    printf(COLOR_BLUE "%s  " COLOR_RESET,dir_list[n]->d_name);
                }
                else {
                    printf("%s  ",dir_list[n]->d_name);
                }
            }
            free(dir_list[n]);
        }
        free(dir_list);
    }
    else if(strcmp(args[1],"-a") == 0) {
        n = scandir(path,&dir_list,0,alphasort);
        if (n==-1) {
        valid_command = false;
            perror("Error in scandir");
            return;
        }
        while(n--) {
            if(dir_list[n]->d_type == DT_DIR) {
                    printf(COLOR_BLUE "%s  " COLOR_RESET,dir_list[n]->d_name);
            }
            else {
                printf("%s  ",dir_list[n]->d_name);
            }
            free(dir_list[n]);
        }
        free(dir_list);
    }
    else if(strcmp(args[1],"-l") == 0) {
        // struct stat **dir_info;
        int size = 0;
        struct stat f1;
        n = scandir(path,&dir_list,0,alphasort);
        char ppath[100];
        if (n==-1) {
        valid_command = false;
            perror("Error in scandir");
            return;
        }
        while (n--) {
            // get_permissions(dir_list[n]->d_name);
            if(dir_list[n]->d_name[0] != '.') {
                strcpy(ppath,path);
                strcat(ppath,dir_list[n]->d_name);
                stat(ppath,&f1);
                time_t t = f1.st_mtime;
                struct tm lt;
                localtime_r(&t, &lt);
                char timbuf[80];
                strftime(timbuf, sizeof(timbuf), "%c", &lt);
                printf("%s\t%d\t%s\t%s\n",get_permissions(ppath),f1.st_size,timbuf,dir_list[n]->d_name);
            }
        } 
    }
    else if(strcmp(args[1],"-la") == 0 || strcmp(args[1],"-al") == 0) {
        int size = 0;
        struct stat f1;
        n = scandir(path,&dir_list,0,alphasort);
        char ppath[100];
        if (n==-1) {
        valid_command = false;
            perror("Error in scandir");
            return;
        }
        while (n--) {
            // get_permissions(dir_list[n]->d_name);
            // if(dir_list[n]->d_name[0] != '.') {
                strcpy(ppath,path);
                strcat(ppath,dir_list[n]->d_name);
                stat(ppath,&f1);
                time_t t = f1.st_mtime;
                struct tm lt;
                localtime_r(&t, &lt);
                char timbuf[80];
                strftime(timbuf, sizeof(timbuf), "%c", &lt);
                printf("%s\t%d\t%s\t%s\n",get_permissions(ppath),f1.st_size,timbuf,dir_list[n]->d_name);
        
        } 
    }
    printf("\n");
} 