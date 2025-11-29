#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
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

#define MAX 1000

const int dir8[] = {-1, -1, 0, -1, 1, 0, 1, 1, -1};

int main() {
    int w, h, i, j, k;
    char map[MAX][MAX];
    fastscan(&w);
    fastscan(&h);
    while (w != 0 && h != 0) {
        for (i = 0; i < h; ++i) {
            for (j = 0; j < w; ++j)
                map[i][j] = getchar_unlocked();
            getchar_unlocked();
        }
        int total = 0;
        for (i = 1; i < h - 1; ++i) {
            for (j = 1; j < w - 1; ++j) {
                if (map[i][j] == '*') continue;
                int count = 0;
                for (k = 0; k < 8; ++k) {
                    int x = j + dir8[k];
                    int y = i + dir8[k + 1];
                    count += map[y][x] == '*';
                    if (count >= 6) {
                        ++total;
                        break;
                    }
                }
            }
        }
        fastprint(total);
        fastscan(&w);
        fastscan(&h);
    }
    return 0;
}
