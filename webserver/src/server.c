#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8081




int main(int argc, char *argv[]){
    printf("hello world\n");

    struct sockaddr_in address;

    int server_fd, new_socket;
    ssize_t valread;
    int opt = 1;

    socklen_t addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char* message = "Hello from server = sid";


    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        // if server_fd is less than 0 then error 
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    int establish = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (establish != 0 ) {
        perror("we not good\n");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  &addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
  
    // subtract 1 for the null
    // terminator at the end
    valread = read(new_socket, buffer,
                   1024 - 1); 
    printf("%s\n", buffer);
    send(new_socket, message , strlen(message), 0);
    printf("Message sent- server side\n");

    // closing the connected socket
    close(new_socket);
  
    // closing the listening socket
    close(server_fd);
    printf("closing server_fd\n");
    return 0;

}

