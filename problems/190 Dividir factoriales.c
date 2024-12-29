#include <stdio.h>

inline void fastscan(unsigned int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
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
    unsigned int num;
    unsigned int den;
    fastscan(&num);
    fastscan(&den);
    while (num >= den) {
        long long res = 1;
        for (; num > den; --num)
            res *= num;
        fastprint(res);
        fastscan(&num);
        fastscan(&den);
    }
    return 0;
}
