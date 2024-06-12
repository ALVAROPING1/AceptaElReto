#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
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

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int wall, int cell) {
    return (wall + cell - 1) / cell;
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int wall_x, wall_y, cell_x, cell_y;
        fastscan(&wall_x);
        fastscan(&wall_y);
        fastscan(&cell_x);
        fastscan(&cell_y);
        fastprint(min(solve(wall_x, cell_x) * solve(wall_y, cell_y),
                      solve(wall_x, cell_y) * solve(wall_y, cell_x)));
    }
    return 0;
}
