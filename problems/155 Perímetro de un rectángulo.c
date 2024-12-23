#include <stdio.h>
#include <stdlib.h>

inline void fastscan(int* number) {
    register int c;
    *number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') exit(0);
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number) {
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

int main() {
    int w, h;
    fastscan(&w);
    fastscan(&h);
    while (1) {
        fastprint(2 * (w + h));
        fastscan(&w);
        fastscan(&h);
    }
    return 0;
}
