#include <stdbool.h>
#include <stdio.h>

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

int main() {
    int d, v, s;
    fastscan(&d);
    fastscan(&v);
    fastscan(&s);
    while (d != 0 || v != 0 || s != 0) {
        if (d <= 0 || v <= 0 || s <= 0) {
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('R');
            putchar_unlocked('O');
            putchar_unlocked('R');
        } else {
            int speed = d * 3.6 / s;
            if (speed < v) {
                putchar_unlocked('O');
                putchar_unlocked('K');
            } else if (speed < v * 1.2) {
                putchar_unlocked('M');
                putchar_unlocked('U');
                putchar_unlocked('L');
                putchar_unlocked('T');
                putchar_unlocked('A');
            } else {
                putchar_unlocked('P');
                putchar_unlocked('U');
                putchar_unlocked('N');
                putchar_unlocked('T');
                putchar_unlocked('O');
                putchar_unlocked('S');
            }
        }
        putchar_unlocked('\n');
        fastscan(&d);
        fastscan(&v);
        fastscan(&s);
    }
    return 0;
}
