#include <stdbool.h>
#include <stdio.h>

inline void fastscan(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
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

int main() {
    int n, i;
    while (scanf("%d", &n) != EOF) {
        int res = n;
        long long x, prev;
        fastscan(&prev);
        for (i = 1; i < n; ++i) {
            fastscan(&x);
            if (prev > x)
                while (n - res < i)
                    res >>= 1;
            prev = x;
        }
        fastprint(res);
    }
    return 0;
}
