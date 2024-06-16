#include <stdio.h>

// Read positive number
inline void fastscan(int* number) {
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

const size_t MAX = 21;

int main() {
    int n;
    fastscan(&n);
    while (n > 0) {
        int current;
        long long distance = 0;
        int mem[MAX];
        int i;
        for (i = 0; i < MAX; ++i)
            mem[i] = 0;
        while (n--) {
            fastscan(&current);
            ++mem[current];
            for (i = 0; i < current; ++i)
                mem[i] = 0;
            for (i = current; i < MAX; ++i)
                distance += mem[i];
        }
        fastprint(distance);
        fastscan(&n);
    }
    return 0;
}
