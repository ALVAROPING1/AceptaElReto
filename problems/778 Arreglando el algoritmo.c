#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscanll(long long* number) {
    bool negative = false;
    *number = 0;
    register int c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
        c = getchar_unlocked();
    }
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    if (negative) *number *= -1;
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
    int n;
    fastscan(&n);
    while (n != 0) {
        long long max;
        fastscanll(&max);
        int total = 1;
        while (--n) {
            long long x;
            fastscanll(&x);
            if (x >= max) {
                ++total;
                max = x;
            } else {
                total = 0;
            }
        }
        fastprint(total);
        fastscan(&n);
    }
    return 0;
}
