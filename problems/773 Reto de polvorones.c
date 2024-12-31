#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int max, p;
    fastscan(&max);
    fastscan(&p);
    while (max != 0 && p != 0) {
        int max_type[10];
        int i;
        for (i = 0; i < p; ++i) {
            fastscan(&max_type[i]);
        }
        int curr;
        int total = 0;
        for (i = 0; i < p; ++i) {
            fastscan(&curr);
            total += curr;
            if (curr > max_type[i] || total > max) {
                putchar_unlocked('N');
                putchar_unlocked('O');
                if (i < p - 1)
                    while (getchar_unlocked() != '\n') {}
                goto end;
            }
        }
        putchar_unlocked('S');
        putchar_unlocked('I');
    end:
        putchar_unlocked('\n');
        fastscan(&max);
        fastscan(&p);
    }
    return 0;
}
