Writer Process

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>

int main() {
    int fd;
    char *fifo_path = "myfifo";  
    char message[100];

    
    mkfifo(fifo_path, 0666);

   
    fd = open(fifo_path, O_WRONLY);

    printf("Enter a message to send to the reader: ");
    fgets(message, sizeof(message), stdin);

   
    write(fd, message, strlen(message) + 1);
    printf("Message sent: %s\n", message);

    close(fd); 
    return 0;
}

