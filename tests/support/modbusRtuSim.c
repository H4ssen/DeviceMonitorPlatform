#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc , char*argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <master-fd>\n",argv[0]);
        return 1;
    }

    int masterFD = atoi(argv[1]);

    if (masterFD <0) {
        fprintf(stderr," Invalid file descriptor ");
        return 1;
    }

    printf(" Modbus started connection with %d\n",masterFD);


    //verify that the file descriptor actually exists 

    if(fcntl(masterFD, F_GETFD) == -1 ) {
        perror("fcntl");
        return 1;
    }

    puts("Start listening ...");

    return 0; 
}