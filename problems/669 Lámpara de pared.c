#include <stdio.h>

// Read positive number
inline void fastscan_positive(int* number) {
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

inline int solve(int groups4, int groups2) {
    if (groups4 <= groups2) {
        return groups4;
    } else {
        int total = groups2;
        groups4 -= groups2;
        total += 2 * (groups4 / 3);
        if (groups4 % 3 == 2) {
            total += 1;
        }
        return total;
    }
}

int main() {
    int n;
    fastscan_positive(&n);
    while (n != 0) {
        int current;
        int amounts[101] = {0};
        while (n--) {
            fastscan_positive(&current);
            ++amounts[current];
        }
        int i = 1;
        int groups4 = 0;
        int groups2 = 0;
        for (; i < 101; ++i) {
            groups4 += amounts[i] / 4;
            groups2 += (amounts[i] % 4) / 2;
        }
        fastprint(solve(groups4, groups2));
        fastscan_positive(&n);
    }
    return 0;
}
