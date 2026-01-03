#include <stdbool.h>
#include <stdio.h>
#include <string.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define MAX_STATES 50
#define MAX_SIZE 51

int main() {
    int n, i;
    fastscan(&n);
    // Arena for the processed states
    char str_arena[2][MAX_STATES][MAX_SIZE];
    // Array with the size of each state
    int sizes[2][MAX_STATES];
    // Array with the amount of times each state has been seen
    int states[2][MAX_STATES];
    while (n != 0) {
        bool player = false;
        // Amount of unique states seen by each player
        int player_states[2] = {0, 0};
        while (n--) {
            // Create aliases for the data relevant for the current turn
            int turn = player_states[player];
            char (*arena)[MAX_SIZE] = str_arena[player];
            int* size = sizes[player];
            int* seen = states[player];
            // Read current line
            int s = 0;
            char c;
            while ((c = getchar_unlocked()) != '\n')
                arena[turn][s++] = c;
            arena[turn][s] = '\0';
            size[turn] = s;
            // Check if the player has already seen this state
            for (i = turn - 1; i >= 0; --i) {
                if (s == size[i] && strcmp(arena[turn], arena[i]) == 0) {
                    // If we already saw this state 4 times before (this would
                    // be the 5th), we can stop
                    if (seen[i] == 4) {
                        putchar_unlocked('S');
                        putchar_unlocked('I');
                        // Ignore remaining lines
                        while (n--)
                            while (getchar_unlocked() != '\n') {}
                        goto end;
                    }
                    ++seen[i];
                    goto end_loop;
                }
            }
            ++player_states[player];
            seen[turn] = 1;
        end_loop:
            player = !player;
        }
        putchar_unlocked('N');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
