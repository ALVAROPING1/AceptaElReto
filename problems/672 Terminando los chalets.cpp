#include <stdbool.h>
#include <stdio.h>

inline int fastscan_check(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastscan(long long* number) {
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

inline long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    int n;
    while (fastscan_check(&n)) {
        long long max_val;
        fastscan(&max_val);
        long long total = max_val;
        while(--n) {
            long long x;
            fastscan(&x);
            total += x;
            max_val = max(max_val, x);
        }
        // Assume the 1st worker starts with the max value and the 2nd with the
        // rest. If the 1st worker finishes first (it accounts for less than
        // half of the sum of all times), it can start with the values the 2nd
        // worker has finished (guaranteed to be at least 1, since the 1st
        // worker was at the biggest value), leading to both workers being
        // always working and thus the final time is the sum of all times.
        // Otherwise, if the 2nd worker finishes first, it will have to wait for
        // the first worker to finish and then work at the max value. Thus the
        // max value is the critical path and the final time is twice its value
        fastprint(max(2*max_val, total));
    }
    return 0;
}
