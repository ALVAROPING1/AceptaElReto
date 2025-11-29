#include <stdio.h>

int main() {
    char prev[2], curr[2];
    char c;
    while ((c = getchar_unlocked()) != EOF) {
        do {
            prev[0] = c;
            prev[1] = getchar_unlocked();
        } while ((c = getchar_unlocked()) >= 'a');
        while (c == ' ') {
            curr[0] = getchar_unlocked();
            curr[1] = getchar_unlocked();
            if (curr[0] != prev[0] || curr[1] != prev[1]) {
                putchar_unlocked('N');
                putchar_unlocked('O');
                while(getchar_unlocked() != '\n');
                goto end;
            }
            prev[0] = curr[0];
            prev[1] = curr[1];
            while ((c = getchar_unlocked()) >= 'a'){
                prev[0] = c;
                prev[1] = getchar_unlocked();
            }
        }
        putchar_unlocked('S');
        putchar_unlocked('I');
    end:
        putchar_unlocked('\n');

    }
    return 0;
}
