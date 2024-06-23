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

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int min_a, max_a, min_b, max_b;
        fastscan(&min_a);
        fastscan(&max_a);
        fastscan(&min_b);
        fastscan(&max_b);
        int result = min(max_a, max_b) - max(min_a, min_b) + 1;
        fastprint(max(result, 0));
    }
    return 0;
}
