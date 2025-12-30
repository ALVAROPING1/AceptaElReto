#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscanll(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
    char buffer[32];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

int main() {
    int n, i;
    fastscan(&n);
    while (n != 0) {
        long long total = 0;
        long long max = 0;
        for (i = 0; i < n; ++i) {
            long long curr;
            fastscanll(&curr);
            if (curr > max) {
                total += i * (curr - max);
                max = curr;
            } else {
                total += max - curr;
            }
        }
        fastprint(total);
        fastscan(&n);
    }
    return 0;
}
