#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int pid,fd_stdout,fd_stderr;
    //create file
    fd_stdout = open("./file_stdout", 0666 | O_CREAT);
    if(fd_stdout == -1){
        perror("Error open");
    }
    fd_stderr = open("./file_stderr", 0666 | O_CREAT);
    if(fd_stderr == -1){
        perror("Error open");
    }
    close(1);
    dup(fd_stdout);
    close(STDERR_FILENO);
    dup(fd_stderr);
    pid = fork();
    if(pid == 0){
        execl("/bin/ls", "-alr" , "/", NULL);
    }
    return 0;
}