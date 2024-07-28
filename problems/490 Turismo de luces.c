#include <stdbool.h>
#include <stdio.h>

inline bool fastscan_check(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == -1) return false;
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

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
    putchar_unlocked('\n');
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int abs(int x) {
    return x * ((x >= 0) * 2 - 1);
}

// Max amount of streets
const size_t MAX = 500000;

int main() {
    int n, k;
    int streets[MAX];
    while (fastscan_check(&n)) {
        fastscan(&k);
        int i;
        for (i = 0; i < n; ++i)
            fastscan(&streets[i]);
        int res = -1;
        for (i = 0; i < n - (k - 1); ++i)
            res = max(res, abs(streets[i + k - 1] - streets[i]));
        fastprint(res);
    }
    return 0;
}
