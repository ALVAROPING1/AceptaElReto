#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define PARITY(x, y) ((x - y) & 1)

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int x1, y1, x2, y2;
        fastscan(&x1);
        fastscan(&y1);
        fastscan(&x2);
        fastscan(&y2);
        if (PARITY(x1, y1) != PARITY(x2, y2)) {
            putchar_unlocked('I');
            putchar_unlocked('M');
            putchar_unlocked('P');
            putchar_unlocked('O');
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked('B');
            putchar_unlocked('L');
            putchar_unlocked('E');
        } else if (x1 == x2 && y1 == y2) putchar_unlocked('0');
        else if ((x1 - y1) == (x2 - y2) || (x1 + y1) == (x2 + y2)) putchar_unlocked('1');
        else putchar_unlocked('2');
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
