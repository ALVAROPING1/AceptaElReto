#include <stdio.h>
#include <string.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0') c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

// Max amount of steps
#define MAX_STEPS 101
// Max amount of types of steps
#define MAX_TYPES 10
// Modulo for output
const size_t mod = 1e9 + 7;

int main() {
    // Init arrays
    int steps_table[2 * MAX_STEPS];
    int types[MAX_TYPES];
    int steps, n_types, i, j;
    fastscan(&steps);
    while (steps != 0) {
        memset(steps_table, 0, sizeof(int) * steps * 2);
        // Read the types of steps
        fastscan(&n_types);
        for (i = 0; i < n_types; ++i) fastscan(&types[i]);
        // Base case
        steps_table[0] = 1;
        // Recursive cases
        for (i = 0; i < steps; ++i) {
            for (j = 0; j < n_types; ++j) {
                int size = types[j];
                steps_table[i + size] =
                    (steps_table[i + size] + steps_table[i]) % mod;
            }
        }
        fastprint(steps_table[steps]);
        fastscan(&steps);
    }
    return 0;
}
