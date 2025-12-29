#include <stdio.h>
#include <unistd.h>

inline void fastscan(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan(&n);
    while (n) {
        while(n--) putchar_unlocked('1');
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
