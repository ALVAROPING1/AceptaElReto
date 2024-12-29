#include <stdio.h>

inline void fastscan(unsigned int* number) {
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

inline int min(int a, int b) {
    return a < b ? a : b;
}

const unsigned int max = ((1U << 31) - 1) / 5;

int main() {
    unsigned int n;
    fastscan(&n);
    while (n--) {
        unsigned int x;
        fastscan(&x);
        unsigned int n2 = 0;
        unsigned int n5 = 0;
        unsigned int i = 2;
        while (i <= x) {
            n2 += x / i;
            i *= 2;
        }
        i = 5;
        while (i <= x) {
            n5 += x / i;
            if (i > max) break;
            i *= 5;
        }
        fastprint(min(n2, n5));
    }
    return 0;
}
