#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
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

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

// Max value of a single coin
#define MAX_VALUE 200
// Max amount of types of coins
#define MAX_TYPES 10

int values_table[MAX_VALUE * MAX_TYPES + 1];
int types[MAX_TYPES];

int main() {
    // Init arrays
    int n, i, j;
    fastscan(&n);
    while (n--) {
        int n_types, max_coins;
        fastscan(&n_types);
        fastscan(&max_coins);
        int max_value = 0;
        // Read the types of steps
        for (i = 0; i < n_types; ++i) {
            fastscan(&types[i]);
            max_value = max(max_value, types[i]);
        }
        int values_size = max_value * MAX_TYPES + 1;
        for (i = 0; i < values_size; ++i) values_table[i] = 100;
        // Base case
        values_table[0] = 0;
        // Recursive cases
        int end = max_value * max_coins;
        int total = 0;
        for (i = 0; i < end; ++i) {
            total += values_table[i] <= max_coins;
            int curr = values_table[i] + 1;
            if (curr > max_coins) continue;
            for (j = 0; j < n_types; ++j) {
                int value = types[j];
                values_table[i + value] = min(values_table[i + value], curr);
            }
        }
        // Print the result and reset the steps table
        fastprint(total);
    }
    return 0;
}
