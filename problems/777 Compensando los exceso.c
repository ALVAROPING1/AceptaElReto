#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
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
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (1) {
        int res = b % a;
        if (res == 0) return a;
        b = a;
        a = res;
    }
}

inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        // Codigo
        int a, b;
        fastscan(&a);
        fastscan(&b);
        int res = (a + b) / gcd(a, b) - 1;
        fastprint(res);
    }
    return 0;
}
