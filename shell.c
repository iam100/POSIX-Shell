#include "functions/declarations.h"


// void hist() {
//     // history[command_no] = args;
//     // command_no++;
//     int len = 0;
//     // printf("%s",history[0][0]);
//     if(args[1] == NULL) {
//         // printf("");
//         for(int i = 0; i< command_no;i++) {
//             if(history[i] == NULL) {
//                 break;
//             }
//             for(int j = 0; j < 30;j++) {
//                 // if(history[command_no])
//                 // if(history[i][j] == NULL) {
//                 //     break;
//                 // }
//                 // else {
//                     printf("%s\n",history[i][j]);
//                 // }
//             }
//         }
//     }
// }

int main(int argc,char* argv[]) {
    home = "~";
    strcpy(delimters," \n\t\r\v\f");
    n_args = 0;
    command_no = 0;
    n_back_proc = 0;
    status = 1;
    int shell_pid = getpid();
    char t[100];
    home = getcwd(t,sizeof(t));
    // printf("\n\n%s\n\n",home);
    // int temp;
    // userid = geteuid()
    
    //load configuration files

    //run a REPL loop
    loop();
    printf("BYE\n");
    exit(0);
    // free(history);
   //form a cleanup
    // return 0;
}