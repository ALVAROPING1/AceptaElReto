#include <stdio.h>

void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

void fastprint(long long number) {
    char buffer[32];
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
    fastscan_positive(&n);
    while (n--) {
        int height;
        fastscan_positive(&height);
        // Solution to the recurrence relation:
        // a_n = a_n-1 + 2n + (n-1)
        // a_1 = 2
        // 2n represents the cards on the next level
        // n-1 represents the cards on the floor of the previous level
        long long res = (height * (3 * (long long) height + 1) / 2);
        fastprint(res);
    }
    return 0;
}
