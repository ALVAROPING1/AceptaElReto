#include <stdio.h>

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

const long long MOD = 1000000007;

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int t, min, max;
        fastscan(&t);
        fastscan(&min);
        fastscan(&max);
        int points = t * t;
        int i;
        long long current = 1;
        long long total = 0;
        for (i = 0; i < min - 1; ++i)
            current = (current * (points - i)) % MOD;
        for (; i < max; ++i) {
            current = (current * (points - i)) % MOD;
            total = (total + current) % MOD;
        }
        fastprint(total);
    }
    return 0;
}
