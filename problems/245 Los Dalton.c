#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscanll(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define FAIL(i)                                                                \
    do {                                                                       \
        if (i < n)                                                             \
            while (getchar_unlocked() != '\n') {}                              \
        putchar_unlocked('D');                                                 \
        putchar_unlocked('E');                                                 \
        putchar_unlocked('S');                                                 \
        putchar_unlocked('C');                                                 \
        putchar_unlocked('O');                                                 \
        putchar_unlocked('N');                                                 \
        putchar_unlocked('O');                                                 \
        putchar_unlocked('C');                                                 \
        putchar_unlocked('I');                                                 \
        putchar_unlocked('D');                                                 \
        putchar_unlocked('O');                                                 \
        putchar_unlocked('S');                                                 \
        goto end;                                                              \
    } while (0)

int main() {
    int n, i;
    fastscan(&n);
    while (n != 0) {
        long long x, prev;
        fastscanll(&prev);
        fastscanll(&x);
        if (prev == x) FAIL(2);
        bool order = prev < x;
        for (i = 2; i < n; ++i) {
            prev = x;
            fastscanll(&x);
            if (x == prev || (prev < x) != order) FAIL(i + 1);
        }
        putchar_unlocked('D');
        putchar_unlocked('A');
        putchar_unlocked('L');
        putchar_unlocked('T');
        putchar_unlocked('O');
        putchar_unlocked('N');
    end:
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
