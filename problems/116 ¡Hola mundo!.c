#include <stdio.h>

int main() {
    register int c = getchar_unlocked();
    for (; c > '0'; --c) {
        putchar_unlocked('H');
        putchar_unlocked('o');
        putchar_unlocked('l');
        putchar_unlocked('a');
        putchar_unlocked(' ');
        putchar_unlocked('m');
        putchar_unlocked('u');
        putchar_unlocked('n');
        putchar_unlocked('d');
        putchar_unlocked('o');
        putchar_unlocked('.');
        putchar_unlocked('\n');
    }
    return 0;
}
