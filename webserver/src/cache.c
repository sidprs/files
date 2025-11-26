
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define LISTADDR "0.0.0.0"

int srv_init(int portNum){
    int socket_val;
    struct sockaddr_in srv;
    socket_val = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_val < 0){
        return -1;
    }

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = INADDR_ANY;
    srv.sin_port = htons(portNum);

    if (bind(socket_val, (sockaddr *)&srv, sizeof(srv)) < 0){
        close(socket_val);
        return -2
    }

    if (listen(socket_val,5)){
        close(socket_val);
        return -3;
    }


}

typedef struct Node{
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
}Node;


typedef struct LinkedList{
    Node *head_;
    Node *tail_;
    int size_;
    int capacity_;
} LinkedList;


struct LRUCache{
    


}LRUCache; 
