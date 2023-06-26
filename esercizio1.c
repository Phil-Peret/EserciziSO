#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#define PIPE_BUF 4096

int main(){
    pid_t pid;
    int mypipe[2];

    //crea piep
    if(pipe(mypipe)){
        fprintf(stderr, "Pipe failed");
        return EXIT_FAILURE;
    }

    pid = fork();

    if(pid == (pid_t) 0 ){
        //chiudo stdout per usare la dup
        //si puo usare anche il numero intero 1 per indicare lo stdout
        close(1);
        dup(mypipe[1]);
        close(mypipe[0]);
        execl("/bin/ls", "-alr", "/", NULL);
        perror("Error to execute execl");
        //dopo l'execl il programma non esegue niente
    }
    
    printf("MAX lenght atomic write: %i\n",PIPE_BUF);
    char out[PIPE_BUF]; 
    close(mypipe[1]);
    if(read(mypipe[0], out, sizeof(char)*PIPE_BUF) == 0){
        perror("Error in read data to pipe");
    }
    printf("%s",out);
    close(mypipe[0]);
    close(mypipe[1]);
    return 0;
}