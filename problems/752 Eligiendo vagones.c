#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan_s(short* number) {
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
}

// Maximum amount of train wagons
const int MAX = 500000;

int main() {
    short wagons[MAX];
    int p, n;
    fastscan(&p);
    fastscan(&n);
    while (p != 0 || n != 0) {
        int best_start = -1, best_length = MAX+1;
        int start = 0, end = 0;
        int total_space = 0;
        while (1) {
            if (total_space < p) {
                if (n == 0) break;
                fastscan_s(&wagons[end]);
                total_space += wagons[end++];
                --n;
            } else {
                int length = end - start;
                if (length < best_length) {
                    best_length = length;
                    best_start = start;
                }
                total_space -= wagons[start++];
            }
        }
        if (best_start == -1) {
            putchar_unlocked('N');
            putchar_unlocked('O');
            putchar_unlocked(' ');
            putchar_unlocked('E');
            putchar_unlocked('N');
            putchar_unlocked('T');
            putchar_unlocked('R');
            putchar_unlocked('A');
            putchar_unlocked('N');
        } else {
            fastprint(best_length);
            putchar_unlocked(' ');
            fastprint(best_start + 1);
        }
        putchar_unlocked('\n');
        fastscan(&p);
        fastscan(&n);
    }
    return 0;
}
