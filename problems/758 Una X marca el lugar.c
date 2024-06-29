#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
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
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int size;
        fastscan(&size);
        // Black tiles
        // Borders: size * 4 - 4 (-4 because each corner is counted twice)
        // First diagonal: size - 2
        // Second diagonal: size - 2 - 1 (-1 for the center)
        // Black = size * 4 - 4 + size - 2 + size - 3
        //       = size * 6 - 9
        fastprint(size * 6 - 9);
        putchar_unlocked(' ');
        // Do the calculation from scratch to avoid data dependencies
        // White tiles
        // White = total_tiles - black
        //       = size² - (size * 6 - 9)
        //       = size² - size * 6 + 9
        //       = size * (size - 1 * 6) + 9
        //       = size * (size - 6) + 9
        fastprint(size * (size - 6) + 9);
        putchar_unlocked('\n');
    }
    return 0;
}
