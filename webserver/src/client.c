#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8081

/*


    while (1) {
        printf("You: ");
        fgets(buffer, sizeof(buffer), stdin);
        
        send(sock, buffer, strlen(buffer), 0);
        
        // Wait for server response
        memset(buffer, 0, sizeof(buffer));
        read(sock, buffer, sizeof(buffer));
        printf("Server: %s\n", buffer);

    }
 */



int main(int argc, char const* argv[])
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr))) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
  
    // subtract 1 for the null
    // terminator at the end
    //send(client_fd, hello, strlen(hello), 0);
    //printf("Hello message sent\n");
    
    printf("You: ");
    fgets(buffer, sizeof(buffer), stdin);  // Read from keyboard
    
    send(client_fd, buffer, strlen(buffer), 0);
    
    //: Wait for server response
    memset(buffer, 0, sizeof(buffer));  // Clear buffer
    read(client_fd, buffer, sizeof(buffer) - 1);
    printf("Client Message : %s\n", buffer);
    valread = read(client_fd, buffer,
                   1024 - 1); 
    printf("%s\n", buffer);

    // closing the connected socket
    close(client_fd);
    return 0;
}
