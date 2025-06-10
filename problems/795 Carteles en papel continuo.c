#include <stdio.h>

inline void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define PRINT_LINE()                                                           \
    while (getchar_unlocked() == '-') {}                                       \
    for (i = 0; i < lines + 2; ++i)                                            \
        putchar_unlocked('-');                                                 \
    putchar_unlocked('\n');

int main() { // Caso marca final
    int lines, cols;
    char sign[40][40];
    fastscan_positive(&cols);
    fastscan_positive(&lines);

    while (lines != 0 && cols != 0) {
        int line, col, i;
        PRINT_LINE(); // Print top lines
        // Read sign
        for (line = 0; line < lines; ++line) {
            getchar_unlocked(); // Consume initial |
            for (col = 0; col < cols; ++col) {
                sign[line][col] = getchar_unlocked();
            }
            getchar_unlocked(); // Consume final |
            getchar_unlocked(); // Consume line jump
        }
        // Print sign
        for (col = cols - 1; col >= 0; --col) {
            putchar_unlocked('|');
            for (line = 0; line < lines; ++line) {
                putchar_unlocked(sign[line][col]);
            }
            putchar_unlocked('|');
            putchar_unlocked('\n');
        }
        PRINT_LINE(); // Print bottom lines
        fastscan_positive(&cols);
        fastscan_positive(&lines);
    }
    return 0;
}
