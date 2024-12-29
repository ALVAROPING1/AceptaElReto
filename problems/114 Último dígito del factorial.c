#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int solutions[] = {1, 1, 2, 6, 4};

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int x;
        fastscan(&x);
        if (x >= 5) {
            putchar_unlocked('0');
        } else {
            putchar_unlocked(solutions[x] + '0');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
