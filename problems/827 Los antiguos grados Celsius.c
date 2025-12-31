#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    bool negative = false;
    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    if (negative) *number *= -1;
}

inline void fastprint(int number) {
    if (number < 0) {
        putchar_unlocked('-');
        number *= -1;
    }
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
    while (n--) {
        int x;
        fastscan(&x);
        fastprint(100 - x);
    }
    return 0;
}
