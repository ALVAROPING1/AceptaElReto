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

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m, y, x;
    fastscan(&n);
    fastscan(&m);
    while (n != 0 && m != 0) {
        int total = 0;
        int missing = 0x7ffffff;
        for (y = 0; y < m; ++y) {
            for (x = 0; x < n; ++x) {
                int curr;
                fastscan(&curr);
                total += curr;
                if (x % 2 != y % 2) missing = min(missing, curr);
            }
        }
        // If any of the sides is odd, we can trivially pass through all tiles
        // by zig zagging to get all food. Otherwise, in the best case we need
        // to skip a single tile with a parity different from the starting tile.
        // Since any of them can be chosen, to get the max total we just need to
        // select the minimum of the available choices
        if (n % 2 == 0 && m % 2 == 0) total -= missing;
        fastprint(total);
        fastscan(&n);
        fastscan(&m);
    }
    return 0;
}
