#include <stdbool.h>
#include <stdio.h>

inline bool fastscan_check(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    if (c == '-') return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    for (c = getchar_unlocked(); c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastscan(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    for (c = getchar_unlocked(); c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void print_day(int day) {
    switch (day) {
    case 0:
        putchar_unlocked('M');
        putchar_unlocked('A');
        putchar_unlocked('R');
        putchar_unlocked('T');
        putchar_unlocked('E');
        putchar_unlocked('S');
        break;
    case 1:
        putchar_unlocked('M');
        putchar_unlocked('I');
        putchar_unlocked('E');
        putchar_unlocked('R');
        putchar_unlocked('C');
        putchar_unlocked('O');
        putchar_unlocked('L');
        putchar_unlocked('E');
        putchar_unlocked('S');
        break;
    case 2:
        putchar_unlocked('J');
        putchar_unlocked('U');
        putchar_unlocked('E');
        putchar_unlocked('V');
        putchar_unlocked('E');
        putchar_unlocked('S');
        break;
    case 3:
        putchar_unlocked('V');
        putchar_unlocked('I');
        putchar_unlocked('E');
        putchar_unlocked('R');
        putchar_unlocked('N');
        putchar_unlocked('E');
        putchar_unlocked('S');
        break;
    case 4:
        putchar_unlocked('S');
        putchar_unlocked('A');
        putchar_unlocked('B');
        putchar_unlocked('A');
        putchar_unlocked('D');
        putchar_unlocked('O');
        break;
    case 5:
        putchar_unlocked('D');
        putchar_unlocked('O');
        putchar_unlocked('M');
        putchar_unlocked('I');
        putchar_unlocked('N');
        putchar_unlocked('G');
        putchar_unlocked('O');
        break;
    case 6:
        putchar_unlocked('E');
        putchar_unlocked('M');
        putchar_unlocked('P');
        putchar_unlocked('A');
        putchar_unlocked('T');
        putchar_unlocked('E');
        break;
    }
    putchar_unlocked(' ');
}

int main() {
    int x, min_val, max_val, min_pos, max_pos, total, i;
    while (fastscan_check(&x)) {
        min_pos = 0;
        max_pos = 0;
        min_val = x;
        max_val = x;
        total = x;
        for (i = 1; i < 6; ++i) {
            fastscan(&x);
            if (x <= min_val) {
                if (x == min_val) {
                    min_pos = 6;
                } else {
                    min_val = x;
                    min_pos = i;
                }
            } else if (x >= max_val) {
                if (x == max_val) {
                    max_pos = 6;
                } else {
                    max_val = x;
                    max_pos = i;
                }
            }
            total += x;
        }
        print_day(max_pos);
        print_day(min_pos);
        if (total < x * 6) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
