#include <stdio.h>

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

#define SYMBOL(c)                                                              \
    putchar_unlocked(' ');                                                     \
    putchar_unlocked(c);                                                       \
    putchar_unlocked(' ');

int main() {
    while (1) {
        register int c = getchar_unlocked();
        if (c == '-') return 0;
        int result = c - '0';
        putchar_unlocked(c);
        while ((c = getchar_unlocked()) != '\n') {
            SYMBOL('+');
            putchar_unlocked(c);
            result += c - '0';
        }
        SYMBOL('=');
        fastprint(result);
    }
    return 0;
}
