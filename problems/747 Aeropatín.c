#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

const int MAX = 50;

struct pair {
    int i, j;
};

#define PUSH(I, J)                                                             \
    {                                                                          \
        ++pos;                                                                 \
        queue[pos].i = I;                                                      \
        queue[pos].j = J;                                                      \
        map[I][J] = false;                                                     \
    }

int main() {
    int f, c;
    fastscan(&f);
    fastscan(&c);
    bool map[MAX][MAX];
    struct pair queue[MAX * MAX];
    while (f != 0 || c != 0) {
        int i, j;
        for (i = 0; i < f; ++i) {
            for (j = 0; j < c; ++j) {
                map[i][j] = getchar_unlocked() == '.';
            }
            getchar_unlocked();
        }
        int pos = 0;
        queue[0].i = 0;
        queue[0].j = 0;
        while (pos >= 0) {
            i = queue[pos].i;
            j = queue[pos].j;
            --pos;
            if (i == f - 1 && j == c - 1) {
                putchar_unlocked('S');
                putchar_unlocked('I');
                goto end;
            }
            if (i - 1 >= 0 && map[i - 1][j]) PUSH(i - 1, j)
            if (j - 1 >= 0 && map[i][j - 1]) PUSH(i, j - 1)
            if (i + 1 < f && map[i + 1][j]) PUSH(i + 1, j)
            if (j + 1 < c && map[i][j + 1]) PUSH(i, j + 1)
        }
        putchar_unlocked('N');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
        fastscan(&f);
        fastscan(&c);
    }
    return 0;
}
