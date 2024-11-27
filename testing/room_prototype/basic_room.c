#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// Room structure definition
typedef struct {
    char description[256];
    char hint[256];
    int is_solved; // Indicates if the puzzle is solved
} Room;

void enter_room(Room *room) {
    clear(); // Clear the screen
    printw("%s\n", room->description);
    if (room->is_solved) {
        printw("Hint: %s\n", room->hint);
    } else {
        printw("What would you like to do? (examine desk / open door [password])\n");
    }
    refresh();
}

int main() {
    // Initialize ncurses
    initscr();
    echo(); // Allow user input to be visible
    cbreak();

    // Room setup
    Room room1 = {
        .description = "You are trapped in an old room. There seems to be a note on the desk.",
        .hint = "The password is 1234.",
        .is_solved = 0
    };

    char input[256];

    while (1) {
        enter_room(&room1);
        mvprintw(LINES - 1, 0, "Enter command: ");
        getstr(input); // Get user input

        // Command handling
        if (strcmp(input, "examine desk") == 0) {
            room1.is_solved = 1;
            printw("You found a note on the desk. Note: %s\n", room1.hint);
        } else if (strncmp(input, "open door ", 10) == 0) {
            char *password = input + 10;
            if (room1.is_solved && strcmp(password, "1234") == 0) {
                printw("The door is open! You successfully escaped.\n");
                break;
            } else {
                printw("The door does not open. The password is incorrect.\n");
            }
        } else {
            printw("Unknown command. Please try again.\n");
        }

        printw("\nPress any key to continue...\n");
        getch();
    }

    // End ncurses
    endwin();
    return 0;
}
