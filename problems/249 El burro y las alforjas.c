#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
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

inline int min(int a, int b) {
    return a < b ? a : b;
}

// Max weight
#define MAX_WEIGHT 20001

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int max, t, curr;
        fastscan(&max);
        fastscan(&t);
        int total = 0;
        bool weights[MAX_WEIGHT] = {false};
        while (t--) {
            fastscan(&curr);
            if (weights[curr]) { ++total; }
            weights[curr] = !weights[curr];
        }
        fastprint(min(max, total));
    }
    return 0;
}
