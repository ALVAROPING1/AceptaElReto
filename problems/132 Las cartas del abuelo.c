#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan_line(int buffer[]) {
    register int i = 0;
    register int prev = getchar_unlocked();
    register int curr;
    buffer[0] = 0;
    while ((curr = getchar_unlocked()) >= ' ') {
        buffer[i + 1] = buffer[i] + (curr != prev);
        prev = curr;
        ++i;
    }
}

// Max line size
const int MAX = 1000000;

int main() {
    int line[MAX];
    int n;
    fastscan_line(line);
    fastscan(&n);
    while (n != 0) {
        while (n--) {
            int a, b;
            fastscan(&a);
            fastscan(&b);
            if (line[a] == line[b]) {
                putchar_unlocked('S');
                putchar_unlocked('I');
            } else {
                putchar_unlocked('N');
                putchar_unlocked('O');
            }
            putchar_unlocked('\n');
        }
        putchar_unlocked('\n');
        fastscan_line(line);
        fastscan(&n);
    }
    return 0;
}
