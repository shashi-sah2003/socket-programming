#include<cstring>
#include<iostream>
#include<sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main(){
    
    //creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    //specifying the address of the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //binding the socket to the specified IP and port
    bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));

    //listening for incoming connections
    listen(serverSocket, 5);

    //accepting the incoming connection
    int clientSocket = accept(serverSocket, NULL, NULL);

    //receive the message from the client
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout<< "Message from client: "<< buffer << endl;

    //close the socket
    close(serverSocket);

    return 0;
}