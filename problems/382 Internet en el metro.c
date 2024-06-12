#include <stdio.h>

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int distance, amount;
        fastscan(&distance);
        fastscan(&amount);
        int max_distance = 0;
        while (amount--) {
            int pos, radius;
            fastscan(&pos);
            fastscan(&radius);
            if (pos - radius <= max_distance)
                max_distance = max(max_distance, pos + radius);
        }
        if (max_distance >= distance) {
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
