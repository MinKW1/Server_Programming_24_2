#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "maze_game.h"
#include "obstacle_game.h"
#include "puzzle_game.h"
#include "pattern_game.h"

// 함수 프로토타입 선언
void maze_game(int client_socket);
void obstacle_game(int client_socket);
void puzzle_game(int client_socket);
void pattern_game(int client_socket);
