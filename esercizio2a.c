#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main(){
    //esercizio con le fifo
    printf("Scrittore su Fifo\n");
    int fd;
    fd = open("./myfifo", O_WRONLY);
    close(1);
    if(dup(fd) == -1){
        perror("Error in dup: ");
    }
    execl("/bin/ls", "-alr", "/", NULL);
    perror("Error in execl: ");
    return 0;
}