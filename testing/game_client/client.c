#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 11244
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        return 1;
    }

    // 게임 단계 선택
    printf("Select game stage (1: Maze Game, 2: Obstacle Game, 3: Puzzle Game, 4: Pattern Game): ");
    int game_stage;
    scanf("%d", &game_stage);
    sprintf(buffer, "%d", game_stage);
    send(client_socket, buffer, strlen(buffer), 0);

    // 서버로부터 응답 받기
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Server: %s\n", buffer);

    close(client_socket);
    return 0;
}
