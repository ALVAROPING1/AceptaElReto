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
    while (n--) {
        int max, min;
        fastscan(&max);
        // Ignore separator
        getchar_unlocked();
        getchar_unlocked();
        fastscan(&min);
        if (max >= min) {
            putchar_unlocked('B');
            putchar_unlocked('I');
            putchar_unlocked('E');
            putchar_unlocked('N');
        } else {
            putchar_unlocked('M');
            putchar_unlocked('A');
            putchar_unlocked('L');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
