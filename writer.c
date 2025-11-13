
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>

int main() {
    int fd;
    char *fifo_path = "myfifo";   // Path to FIFO
    char message[100];

    // Create the FIFO (named pipe)
    mkfifo(fifo_path, 0666);

    // Open FIFO for writing
    fd = open(fifo_path, O_WRONLY);

    printf("Enter a message to send to the reader: ");
    fgets(message, sizeof(message), stdin);

    // Write the message to FIFO
    write(fd, message, strlen(message) + 1);
    printf("Message sent: %s\n", message);

    close(fd);  // Close FIFO
    return 0;
}

