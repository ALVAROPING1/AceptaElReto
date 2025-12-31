#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint2d(int number, char delim) {
    putchar_unlocked(number / 10 + '0');
    putchar_unlocked(number % 10 + '0');
    putchar_unlocked(delim);
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int total = 0;
        while (n--) {
            int x;
            fastscan(&x);
            total += x;
        }
        int h = total / 3600;
        int m = (total % 3600) / 60;
        int s = (total % 60);
        fastprint2d(h, ':');
        fastprint2d(m, ':');
        fastprint2d(s, '\n');
        fastscan(&n);
    }
    return 0;
}
