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
}

int main() {
    int a, b;
    fastscan(&a);
    fastscan(&b);
    while (a != 0 && b != 0) {
        int min, max;
        min = a + 74 * b;
        max = a + 79 * b;
        putchar_unlocked('[');
        fastprint(min);
        putchar_unlocked(' ');
        putchar_unlocked('.');
        putchar_unlocked('.');
        putchar_unlocked(' ');
        fastprint(max);
        putchar_unlocked(']');
        putchar_unlocked('\n');
        fastscan(&a);
        fastscan(&b);
    }
    return 0;
}
