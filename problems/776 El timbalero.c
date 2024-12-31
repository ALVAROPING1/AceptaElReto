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

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int timbal[600000];
        int i;
        for (i = 0; i < n*2; i += 2) {
            fastscan(&timbal[i]);
            fastscan(&timbal[i+1]);
        }
        int current;
        int res = 0;
        i = 0;
        fastscan(&current);
        while (current != 0) {
            if (i >= n*2) {
                do {
                    fastscan(&current);
                    ++res;
                } while (current != 0);
                break;
            }
            if (current >= timbal[i] && current <= timbal[i+1]) {
                fastscan(&current);
                continue;
            }
            if (i+2 >= n*2 || current < timbal[i+2]) {
                fastscan(&current);
                ++res;
                continue;
            }
            i += 2;
        }
        fastprint(res);
        fastscan(&n);
    }
    return 0;
}
