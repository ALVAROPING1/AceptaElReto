#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
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

inline int gcd(int a, int b) {
    int min, max;
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    while (1) {
        int res = max % min;
        if (res == 0) return min;
        max = min;
        min = res;
    }
}

inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;
    fastscan(&n);
    while (n > 0) {
        int res, curr;
        fastscan(&res);
        while (--n) {
            fastscan(&curr);
            res = lcm(res, curr);
        }
        fastprint(res);
        fastscan(&n);
    }
    return 0;
}
