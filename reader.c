
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>

int main() {
    int fd;
    char *fifo_path = "mkfifo";   // Same FIFO path as writer
    char message[100];

    // Create the FIFO (if not already created)
    mkfifo(fifo_path, 0666);

    // Open FIFO for reading
    fd = open(fifo_path, O_RDONLY);

    // Read message from FIFO
    read(fd, message, sizeof(message));
    printf("Message received from writer: %s\n", message);

    close(fd);  // Close FIFO
    return 0;
}
