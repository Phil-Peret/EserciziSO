#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid,retc;
    pid = fork();
    if(pid == 0){
        execl("./randexit", NULL);
    }
    int status;
    waitpid(pid, &status, 0);
    if(WIFEXITED(status)){
        int exit_status = WEXITSTATUS(status);
        printf("Valore di uscita del programma: %d\n", exit_status);
    }
    return 0;
}