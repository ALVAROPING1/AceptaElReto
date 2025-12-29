#include <stdio.h>
#include <stdbool.h>

inline void fastscan_positive(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    bool negative = false;
    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    if (negative) *number *= -1;
}

int main() {
    int n;
    fastscan_positive(&n);
    while (n--) {
        int s, c;
        fastscan(&s);
        fastscan(&c);
        if (s + c >= 0) {
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
