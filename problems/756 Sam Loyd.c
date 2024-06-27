#include <stdbool.h>
#include <stdio.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == -1) return false;
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

int main() {
    int n[16];
    // While there are lines to read
    while (fastscan(&n[0])) {
        bool inversions = 0;
        int i, j;
        for (i = 1; i < 16; ++i)
            fastscan(&n[i]);
        for (i = 0; i < 16; ++i)
            for (j = i + 1; j < 16; ++j)
                if (n[i] > n[j]) inversions = !inversions;
        if (inversions) {
            putchar_unlocked('N');
            putchar_unlocked('O');
        } else {
            putchar_unlocked('S');
            putchar_unlocked('I');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
