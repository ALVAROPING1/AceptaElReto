#include <stdbool.h>
#include <stdio.h>

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

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        register int best_length = 0;
        register int length = 0;
        register int c = getchar_unlocked();
        do {
            if (c == 'T') ++length;
            else {
                best_length = max(best_length, length);
                length = 0;
            }
        } while ((c = getchar_unlocked()) != '\n');
        fastprint(max(best_length, length));
    }
    return 0;
}
