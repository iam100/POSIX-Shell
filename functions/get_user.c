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

void get_user() {
    struct passwd *p;
    p = getpwuid(geteuid());
    username = p->pw_name;
    gethostname(hostname,1000);
    strcpy(uname,username);
    strcat(uname,"@");
    strcat(uname,hostname);
    strcat(uname,":");
    // tmp = strcat(temp,":");
}