#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int x;
        fastscan(&x);
        int y = x % 3;
        if (x / 3 >= y) {
            putchar_unlocked(y + '0');
        } else {
            putchar_unlocked('I');
            putchar_unlocked('M');
            putchar_unlocked('P');
            putchar_unlocked('O');
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked('B');
            putchar_unlocked('L');
            putchar_unlocked('E');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
