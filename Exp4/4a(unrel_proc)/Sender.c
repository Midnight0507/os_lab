#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int res;
    res = open("fifo1", O_WRONLY); // Opens the named pipe for writing
    if (res < 0) {
        perror("open");
        return 1;
    }
    write(res, "Message", 7); // Writes "Message" to the pipe
    printf("Sender Process having PID %d, sent the data\n", getpid());
    close(res); // Close the pipe
    return 0;
}
