#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// Room structure definition
typedef struct {
    char description[256];
    char hint[256];
    char solution[256];
    int is_solved;
} Room;

void enter_room(Room *room) {
    clear();
    printw("%s\n", room->description);
    if (room->is_solved) {
        printw("Hint: %s\n", room->hint);
    }
    printw("What would you like to do? Type your command:\n");
    refresh();
}

int main() {
    // Initialize ncurses
    initscr();
    echo();   // Enable echoing of user input
    cbreak();

    // Room setup
    Room rooms[3] = {
        { // Room 1
            .description = "You are in a small room. There's a desk with a note on it.",
            .hint = "The password for the door is 1234.",
            .solution = "1234",
            .is_solved = 0
        },
        { // Room 2
            .description = "You enter a dimly lit room. There is a locked box here.",
            .hint = "The code for the box is the number of sides on a square.",
            .solution = "4",
            .is_solved = 0
        },
        { // Room 3
            .description = "You are in the final room. There's a riddle on the wall:\n"
                           "'I speak without a mouth and hear without ears. I have no body, but I come alive with the wind.'",
            .hint = "The answer is 'echo'.",
            .solution = "echo",
            .is_solved = 0
        }
    };

    int current_room = 0;
    char input[256];

    while (current_room < 3) {
        Room *room = &rooms[current_room];
        enter_room(room);

        mvprintw(LINES - 1, 0, "Enter command: ");
        refresh();

        // Ensure we can read input properly
        if (getnstr(input, sizeof(input) - 1) == ERR) {
            printw("Error reading input. Please try again.\n");
            continue;
        }

        // Handle commands
        if (room->is_solved) {
            if (strcmp(input, "open door") == 0) {
                printw("The door opens, and you proceed to the next room.\n");
                current_room++;
                getch();
                continue;
            } else {
                printw("Invalid command. Try 'open door' to proceed.\n");
            }
        } else {
            if (strncmp(input, "examine", 7) == 0) {
                printw("You examine the surroundings carefully.\n");
                room->is_solved = 1;
            } else if (strncmp(input, "solve ", 6) == 0) {
                char *solution = input + 6;
                if (strcmp(solution, room->solution) == 0) {
                    printw("Correct! You solved the puzzle.\n");
                    room->is_solved = 1;
                } else {
                    printw("Wrong solution. Try again.\n");
                }
            } else {
                printw("Unknown command. Try 'examine' or 'solve <answer>'.\n");
            }
        }

        printw("\nPress any key to continue...\n");
        getch();
    }

    // Final message
    clear();
    printw("Congratulations! You have escaped all the rooms.\n");
    printw("Press any key to exit...\n");
    getch();

    // End ncurses
    endwin();
    return 0;
}
