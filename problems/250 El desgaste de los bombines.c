#include <stdbool.h>
#include <stdio.h>

// Read positive number
inline void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

// Read positive/negative number
inline void fastscan(int* number) {
    bool negative = false;
    register int c;
    *number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';

    if (negative) *number *= -1;
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

// Max amount of numbers
const size_t MAX = 1000001;

inline int abs(int x) {
    return x * ((x >= 0) * 2 - 1);
}

int main() {
    int vals[MAX];
    int n;
    fastscan_positive(&n);
    while (n != 0) {
        int total = 0;
        int i = n;
        while (i--) {
            fastscan(&vals[i]);
            total += vals[i];
        }
        int res = n;
        i = n;
        int best_diff = abs(total);
        while (i--) {
            total -= 2 * vals[i];
            int curr_diff = abs(total);
            if (curr_diff < best_diff) {
                res = i;
                best_diff = curr_diff;
            }
        }
        fastprint(n - res);
        fastscan_positive(&n);
    }
    return 0;
}
