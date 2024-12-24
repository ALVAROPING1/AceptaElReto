#include <stdbool.h>
#include <stdio.h>

// Read positive number
inline void fastscan_positive(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline bool solve(long long remaining1,
                  long long remaining2,
                  long long take1,
                  long long take2) {
    if (take1 == take2)
        return remaining1 == remaining2 && remaining1 % take1 == 0;
    long long det = take1 * take1 - take2 * take2;
    long long x = (take1 * remaining1 - take2 * remaining2);
    long long y = (-take2 * remaining1 + take1 * remaining2);
    return (x % det == 0 && x / det >= 0) && (y % det == 0 && y / det >= 0);
}

int main() {
    long long remaining1, remaining2, take1, take2;
    fastscan_positive(&remaining1);
    fastscan_positive(&remaining2);
    fastscan_positive(&take1);
    fastscan_positive(&take2);
    while (remaining1 != 0 || remaining2 != 0 || take1 != 0 || take2 != 0) {
        if (solve(remaining1, remaining2, take1, take2)) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
        fastscan_positive(&remaining1);
        fastscan_positive(&remaining2);
        fastscan_positive(&take1);
        fastscan_positive(&take2);
    }
    return 0;
}
