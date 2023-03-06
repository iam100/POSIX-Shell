#ifndef declarations
#define declarations


// #define _DEFAULT_SOURCE
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

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[92m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[94m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

struct bkg{
	pid_t pid;
    pid_t jid;
    int active;
    char status;
    char command[1000];
};

struct bkg bkg_proc[30];

pid_t pid,wpid;
char* input; 
char* args[30];
char* home;
char delimters[10];
char* username;
char hostname[1000],uname[1000],command_line[2000];
char permissions[100];
int n_args,command_no;
int n_back_proc;
char* history[30];
bool background,valid_command;
int status;

void back_check();
void background_proc();
void pinfo();
char* present_working_directory();
char *get_permissions(char *path);
void list_fi(void);
void echo_fun(void);
void read_input();
void dir_change(char* path);
void get_user();
void loop();


#endif