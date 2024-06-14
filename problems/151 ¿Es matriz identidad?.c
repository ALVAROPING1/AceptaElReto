#include <stdbool.h>
#include <stdio.h>

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                int first, second;
                first = getchar_unlocked() - '0';
                second = getchar_unlocked();
                if (first != (i == j) || second > ' ') {
                    i += second == '\n';
                    while (i < n) {
                        i += getchar_unlocked() == '\n';
                    }
                    putchar_unlocked('N');
                    putchar_unlocked('O');
                    goto end;
                }
            }
        }
        putchar_unlocked('S');
        putchar_unlocked('I');
    end:
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
