#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT    8080
#define SERVER_ADDRESS "127.0.0.1"
#define BUFFER_SIZE    1024

int main() {

    int client_socket;
    struct sockaddr_in server_address_info;
    char message_to_send[BUFFER_SIZE];
    char message_received[BUFFER_SIZE];
    int bytes_received;

    /* Step 1 — Create a socket */
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        printf("Error: Could not create socket.\n");
        return 1;
    }
    printf("Socket created successfully.\n");

    /* Step 2 — Set up server address details */
    server_address_info.sin_family      = AF_INET;
    server_address_info.sin_port        = htons(SERVER_PORT);
    server_address_info.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    /* Step 3 — Connect to the server */
    if (connect(client_socket, 
                (struct sockaddr *)&server_address_info, 
                sizeof(server_address_info)) < 0) {
        printf("Error: Connection to server failed.\n");
        return 1;
    }
    printf("Connected to server at %s on port %d\n", 
           SERVER_ADDRESS, SERVER_PORT);

    /* Step 4 — Get message from user */
    printf("Enter message to send: ");
    fgets(message_to_send, BUFFER_SIZE, stdin);

    /* Step 5 — Send message to server */
    send(client_socket, message_to_send, strlen(message_to_send), 0);
    printf("Message sent: %s", message_to_send);

    /* Step 6 — Receive reply from server */
    bytes_received = recv(client_socket, 
                          message_received, 
                          BUFFER_SIZE, 0);

    message_received[bytes_received] = '\0';
    printf("Reply from server: %s\n", message_received);

    /* Step 7 — Close the socket */
    close(client_socket);
    printf("Connection closed.\n");

    return 0;
}