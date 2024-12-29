#include <stdio.h>
#include <stdlib.h>

inline void fastscan_check(unsigned int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == '-') exit(0);
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan(unsigned int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    unsigned int p;
    fastscan_check(&p);
    while (1) {
        unsigned int n;
        fastscan(&n);
        if (p == 1 || p <= n) {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
        fastscan_check(&p);
    }
    return 0;
}
