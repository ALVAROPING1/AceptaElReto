#include <stdio.h>

// Max value (+1 since it's an inclusive range)
#define MAX 1000 + 1

// Modulo used for output
const int mod = 1000000007;

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
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
    int binomial[MAX][MAX] = {{0}};
    int i, j;
    binomial[0][0] = 1;
    for (i = 1; i < MAX; ++i) {
        binomial[i][0] = 1;
        binomial[i][i] = 1;
    }
    for (i = 1; i < MAX; ++i) {
        for (j = 1; j < i; ++j) {
            binomial[i][j] =
                (binomial[i - 1][j - 1] + binomial[i - 1][j]) % mod;
        }
    }
    // Read first line
    int n, k;
    fastscan(&n);
    fastscan(&k);
    while (n != 0 || k != 0) { // While there are lines to read
        // Print the result and read the next line
        fastprint(binomial[n][k]);
        fastscan(&n);
        fastscan(&k);
    }
    return 0;
}
