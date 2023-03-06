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

char *get_permissions(char *path) {
    struct stat f1;
    stat(path,&f1);
    // size = 0;
    for(int i = 0; i<10;i++) {
        permissions[i] = '-';
    }
    permissions[10] = '\0';
    // printf("%s  ",permissions);
    if(f1.st_mode & S_IFDIR) {
        permissions[0] = 'd';
    }
    if(f1.st_mode & S_IRUSR){
        permissions[1] = 'r';
    }
    if(f1.st_mode & S_IWUSR){
        permissions[2] = 'w';
    }
    if(f1.st_mode & S_IXUSR){
        permissions[3] = 'x';
    }
    if(f1.st_mode & S_IRGRP){
        permissions[4] = 'r';
    }
    if(f1.st_mode & S_IWGRP){
        permissions[5] = 'w';
    }
    if(f1.st_mode & S_IXGRP){
        permissions[6] = 'x';
    }
    if(f1.st_mode & S_IROTH){
        permissions[7] = 'r';
    }
    if(f1.st_mode & S_IWOTH){
        permissions[8] = 'w';
    }
    if(f1.st_mode & S_IXOTH){
        permissions[9] = 'x';
    }
    // printf("%s\n",permissions);
    // size = f1.st_size;
    // strcat(permissions,"\t");
    // strcat(permissions,size);
    char *p = permissions;
    return p;
}
