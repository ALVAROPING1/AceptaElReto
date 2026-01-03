#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number, char delimiter) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked(delimiter);
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int normal_in, normal_out, new_in, new_out;
        fastscan(&normal_in);
        fastscan(&normal_out);
        fastscan(&new_in);
        fastscan(&new_out);
        int total =
            12 * normal_in + 9 * normal_out + (12 + 6) * new_in + 12 * new_out;
        int a = total / (12 * 20);
        int b = (total % (12 * 20)) / 12;
        int c = total % 12;

        fastprint(a, ' ');
        fastprint(b, ' ');
        fastprint(c, '\n');
    }
    return 0;
}
