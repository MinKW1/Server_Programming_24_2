#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../common/game_manager.h"

#define PORT 11244
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    // 家南 积己
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 官牢爹
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server is listening on port %d\n", PORT);
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    printf("Client connected\n");

    // 霸烙 包府 风橇
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread > 0) {
            int game_stage = atoi(buffer);
            switch (game_stage) {
                case 1:
                    maze_game(new_socket);
                    break;
                case 2:
                    obstacle_game(new_socket);
                    break;
                case 3:
                    puzzle_game(new_socket);
                    break;
                case 4:
                    pattern_game(new_socket);
                    break;

                default:
                    strcpy(buffer, "UNKNOWN GAME");
                    send(new_socket, buffer, strlen(buffer), 0);
            }
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
