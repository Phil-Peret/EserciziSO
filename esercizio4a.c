#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int ret = rand()%128;
    printf("Numero generato: %i\n", ret);
    exit(ret);
    return 0;
}