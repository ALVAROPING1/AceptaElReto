#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int amount;
        fastscan(&amount);
        register int tot = 0;
        do {
            if ((amount % 5) == 4) {
                if (tot == 1) {
                    putchar_unlocked('S');
                    putchar_unlocked('I');
                    goto end;
                }
                tot = 1;
            }
            amount /= 5;
        } while (amount);
        putchar_unlocked('N');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
    }
    return 0;
}
