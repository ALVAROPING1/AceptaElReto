#include <stdio.h>

int main() {
    while (1) {
        register int c;
        c = getchar_unlocked();
        if (c == '-') return 0;
        for (; c != '\n'; c = getchar_unlocked()) {
            if ((c - '0') % 2 == 1) {
                putchar_unlocked('N');
                putchar_unlocked('O');
                while ((c = getchar_unlocked()) != '\n')
                    ;
                goto end;
            }
        }
        putchar_unlocked('S');
        putchar_unlocked('I');
    end:
        putchar_unlocked('\n');
    }
}
