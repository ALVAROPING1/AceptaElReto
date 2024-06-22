#include <stdbool.h>
#include <stdio.h>

inline bool fastscan(int* next, int* zeros) {
    *zeros = 0;
    register int c = getchar_unlocked();
    if (c == '0') return false;
    *next = c - '0';
    // Keep on extracting characters if they are integers
    for (c = getchar_unlocked(); c >= '0'; c = getchar_unlocked()) {
        if (c == '0') ++*zeros;
        else *next *= c - '0';
    }
    return true;
}

int main() {
    int next, zeros;
    register int n;
    while (fastscan(&next, &zeros)) {
        while (next > 9) {
            n = next;
            next = 1;
            do {
                char digit = (n % 10);
                if (digit == 0) ++zeros;
                else next *= digit;
                n /= 10;
            } while (n);
        }
        putchar_unlocked(next + '0');
        putchar_unlocked(zeros + '0');
        putchar_unlocked('\n');
    }
    return 0;
}
