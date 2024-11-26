#include "obstacle_game.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void obstacle_game(int client_socket) {
    char buffer[1024];
    sprintf(buffer, "Welcome to the Obstacle Game!");
    send(client_socket, buffer, strlen(buffer), 0);
}
