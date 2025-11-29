#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define BAR() \
    putchar_unlocked('|'); \
    for (i = 0; i < 8*w; ++i) putchar_unlocked('-'); \
    putchar_unlocked('|'); \
    putchar_unlocked('\n'); \

int main() {
    int w, c, x, y, i, j;
    char tile[2] = {' ', ' '};
    fastscan(&w);
    while (w != 0) {
        tile[1] = getchar_unlocked();
        getchar_unlocked();
        c = 0;
        BAR();
        for (y = 0; y < 8; ++y) {
            for (i = 0; i < w; ++i) {
                putchar_unlocked('|');
                for (x = 0; x < 8; ++x) {
                    for (j = 0; j < w; ++j) putchar_unlocked(tile[c]);
                    c = !c;
                }
                putchar_unlocked('|');
                putchar_unlocked('\n');
            }
            c = !c;
        }
        BAR();
        fastscan(&w);
    }
    return 0;
}
