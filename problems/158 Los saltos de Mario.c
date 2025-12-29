#include <stdio.h>

inline void fastscan(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number, char terminator) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked(terminator);
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int walls, prev, x;
        int up = 0;
        int down = 0;
        fastscan(&walls);
        fastscan(&prev);
        while (--walls) {
            fastscan(&x);
            if (x > prev) ++up;
            else if (x < prev) ++down;
            prev = x;
        }
        fastprint(up, ' ');
        fastprint(down, '\n');
    }
}
