#include <stdio.h>

inline void fastscan(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
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

inline long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    long long x;
    fastscan(&x);
    while (x != 0) {
        long long max_pair = x;
        long long next;
        while (x != 0) {
            fastscan(&next);
            max_pair = max(max_pair, x + next);
            x = next;
        }
        fastprint(max_pair);
        fastscan(&x);
    }
    return 0;
}
