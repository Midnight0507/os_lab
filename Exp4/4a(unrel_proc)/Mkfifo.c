#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int res;
    res = mkfifo("fifo1", 0777); // Creates a named pipe with the name fifo1
    if (res == 0) {
        printf("Named pipe created\n");
    } else {
        perror("mkfifo");
    }
    return 0;
}

/*
gcc Mkfifo.c -o Mkfifo
gcc Sender.c -o Sender
gcc Receiver.c -o Receiver

./Mkfifo
./Receiver
./Sender
*/
