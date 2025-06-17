#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int max, max_amount = 0, amount = 0;
        fastscan(&max);
        --n;
        while (n--) {
            ++amount;
            if (amount > max_amount) max_amount = amount;
            int curr;
            fastscan(&curr);
            if (curr > max) {
                max = curr;
                amount = 1;
            }
        }
        fastprint(max_amount);
        fastscan(&n);
    }
    return 0;
}
