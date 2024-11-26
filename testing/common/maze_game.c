#include "maze_game.h"
#include "game_manager.h"  // Include the header for the declaration

// You can now call maze_game here, but you don't need to define it again.

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void maze_game(int client_socket) {
    char buffer[1024];
    sprintf(buffer, "Welcome to the Maze Game!");
    send(client_socket, buffer, strlen(buffer), 0);
}
