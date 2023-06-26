#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>

int main(){
    printf("Programma in lettura su fifo\n");
    int ret_val = mkfifo("./myfifo",0666);
    if(ret_val == -1 && errno != EEXIST) perror("Error in mkfifo");
    int fd = open("./myfifo", O_RDONLY);
    char data[4096];
    read(fd, data, sizeof(char)*4096);
    printf("%s",data);
    
}