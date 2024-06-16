#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int prev, curr;
        bool fail = false;
        fastscan(&prev);
        while (--n) {
            fastscan(&curr);
            fail = fail || curr <= prev;
            prev = curr;
        }
        if (fail) {
            putchar_unlocked('N');
            putchar_unlocked('O');
        } else {
            putchar_unlocked('S');
            putchar_unlocked('I');
        }
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
