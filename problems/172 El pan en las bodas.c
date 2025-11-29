#include <stdio.h>

int main() {
    char c;
    while (getchar_unlocked() != '0') {
        while(getchar_unlocked() != ' ');
        char dir = '.';
        while((c = getchar_unlocked()) != '\n') {
            if (dir != '.' && c != '.' && c != dir) {
                while(getchar_unlocked() != '\n');
                putchar_unlocked('A');
                putchar_unlocked('L');
                putchar_unlocked('G');
                putchar_unlocked('U');
                putchar_unlocked('N');
                putchar_unlocked('O');
                putchar_unlocked(' ');
                putchar_unlocked('N');
                putchar_unlocked('O');
                putchar_unlocked(' ');
                putchar_unlocked('C');
                putchar_unlocked('O');
                putchar_unlocked('M');
                putchar_unlocked('E');
                goto end;
            }
            if (c != '.') dir = c;
        }
        putchar_unlocked('T');
        putchar_unlocked('O');
        putchar_unlocked('D');
        putchar_unlocked('O');
        putchar_unlocked('S');
        putchar_unlocked(' ');
        putchar_unlocked('C');
        putchar_unlocked('O');
        putchar_unlocked('M');
        putchar_unlocked('E');
        putchar_unlocked('N');
    end:
        putchar_unlocked('\n');

    }
    return 0;
}
