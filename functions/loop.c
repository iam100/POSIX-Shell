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


void loop() {
    // char* commands;
    // char** args;
    // read the commands entered by the user 
    // it will parse the commands 
    //execute the commands
    // char tmp[1000],temp[2000];
    while (status) {
        // printf("%d\n\n",status);
        get_user();
        printf(COLOR_GREEN "%s" COLOR_RESET,uname);
        valid_command = true;
        // strcpy(tmp,present_working_directory());
        // strcpy(temp,uname);
        // strcat(temp,tmp);
        // strcat(temp,"$ ");
        printf(COLOR_BLUE"%s$ "COLOR_RESET ,present_working_directory());
        back_check();
        read_input();
        if(n_args != 0) {
            if(strcmp(args[n_args-1],"&") == 0) {
                background = true;
                // printf("%s\n",args[n_args-1]);
            }
            else {
                background = false;
            }
        }
        // arguments is an array of strings
        if(!background) {
            if(args[0] == NULL) {
                valid_command = false;
                continue;
            }
            else if(strcmp(args[0],"cd") == 0) {
                dir_change(args[1]);
            }
            else if(strcmp(args[0],"pwd") == 0) {
                printf("%s\n",present_working_directory());
            }
            else if(strcmp(args[0],"echo") == 0) {
                echo_fun();
            }
            else if(strcmp(args[0],"exit") == 0) {
                status = 0;
            }
            else if(strcmp(args[0],"ls") == 0) {
                list_fi();
            }
            else if(strcmp(args[0],"pinfo") == 0) {
                pinfo();
            }
            // else if(strcmp(args[0],"history") == 0) {
            //     hist();
            // }
        // else if(strcmp(args[0],"clear") == 0) {
        //     clear();
        // }
            else {
                background_proc();
                // printf("Unkown command\n");
            }
        }
        else {
            background_proc();
        }
        if(valid_command) {
            // printf("\n\n\nWORKING\n\n");
            // strcpy(history[command_no],args[0]);
            // printf("%s\n\n",history[command_no]);
            // command_no++;
        }
        for(int i = 0;i < 30;i++ ){
                args[i] = NULL;
        }
        n_args = 0;
        background = false;
    }
    
}