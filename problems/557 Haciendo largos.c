#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan_ll(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
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
    int t;
    fastscan(&t);
    while (t--) {
        long long N, D, I;
        int T, M;
        fastscan_ll(&N);
        fastscan(&T);
        fastscan(&M);
        fastscan_ll(&D);
        fastscan_ll(&I);
        int series = (N + M - 1) / M - 1;
        fastprint(N * T + series * D + I * (series - 1) * series / 2);
    }
    return 0;
}
