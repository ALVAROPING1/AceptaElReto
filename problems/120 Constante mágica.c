#include <stdio.h>
#include <stdbool.h>

inline void fastscan(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
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

inline int sum_to_n(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n, k;
    fastscan(&n);
    fastscan(&k);
    while (n != 0 || k != 0) {
        // Since we are wrapping around on both coordinates, all diagonals have
        // the same length equal to the size of the square (N). After filling up
        // a diagonal and moving down, we start the next diagonal 1 position to
        // the left and 2 positions below where we started the previous one.
        // Since we start at the center of the top row, we are guaranteed to
        // start the secondary diagonal at the bottom left corner after filling
        // N//2 diagonals, having filled N * (N//2) tiles. Thus, the first value
        // in that diagonal will be S = K + N*(N//2), and from there it will be
        // filled with consecutive naturals in the range [S, S + N - 1). As a
        // result, the magic number will be the sum of the naturals in that
        // range, which can be calculated as the difference between the sum of
        // the naturals up to each bound
        int s = k + n * (n / 2) - 1;
        fastprint(sum_to_n(s + n) - sum_to_n(s));
        fastscan(&n);
        fastscan(&k);
    }
    return 0;
}
