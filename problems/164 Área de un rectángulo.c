#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
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

#define READ_RECT()                                                            \
    fastscan(&ax);                                                             \
    fastscan(&ay);                                                             \
    fastscan(&bx);                                                             \
    fastscan(&by);

int main() {
    int ax, ay, bx, by;
    READ_RECT();
    while (ax <= bx && ay <= by) {
        fastprint((bx - ax) * (by - ay));
        READ_RECT()
    }
    return 0;
}
