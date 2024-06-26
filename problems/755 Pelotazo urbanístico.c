#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
    char buffer[32];
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

int main() {
    int n;
    fastscan(&n);
    // While there are lines to read
    while (n--) {
        int w, h;
        fastscan(&w);
        fastscan(&h);
        // Square size. Must be a divisor of the width and height, and we want
        // the largest one to use the least squares
        long long max_div = gcd(w, h);
        // Calculate the amount of squares and print it
        fastprint(w / max_div * h / max_div);
    }
    return 0;
}
