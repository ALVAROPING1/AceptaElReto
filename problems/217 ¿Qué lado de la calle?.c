#include <stdio.h>

inline void fastscan(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        if (n % 2 == 1) {
            putchar_unlocked('I');
            putchar_unlocked('Z');
            putchar_unlocked('Q');
            putchar_unlocked('U');
            putchar_unlocked('I');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('D');
            putchar_unlocked('A');
        } else {
            putchar_unlocked('D');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('E');
            putchar_unlocked('C');
            putchar_unlocked('H');
            putchar_unlocked('A');
        }
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
