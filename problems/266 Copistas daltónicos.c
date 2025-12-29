#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define MAX 501

int main() {
    char transform[128];
    char picture[MAX * MAX];
    transform['\n'] = '\n';
    int H, W, i;
    fastscan(&H);
    fastscan(&W);
    while (H != 0 || W != 0) {
        for (i = 'A'; i <= 'Z'; ++i)
            transform[i] = i;
        int size = H * (W + 1);
        for (i = 0; i < size; ++i)
            picture[i] = getchar_unlocked();
        int k;
        fastscan(&k);
        while (k--) {
            char old = getchar_unlocked();
            getchar_unlocked();
            char new = getchar_unlocked();
            getchar_unlocked();
            for (i = 'A'; i <= 'Z'; ++i)
                if (transform[i] == old) transform[i] = new;
        }
        for (i = 0; i < size; ++i) putchar_unlocked(transform[(int)picture[i]]);
        fastscan(&H);
        fastscan(&W);
    }
    return 0;
}
