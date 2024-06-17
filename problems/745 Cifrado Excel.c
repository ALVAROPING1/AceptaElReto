#include <stdbool.h>
#include <stdio.h>

void fastscan(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

void fastprint(long long number) {
    char buffer[16];
    register int i = -1;
    do {
        number -= 1;
        buffer[++i] = (number % 26) + 'A';
        number /= 26;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
}

int main() {
    long long n;
    fastscan(&n);
    while (n != 0) {
        fastprint(n);
        fastscan(&n);
        while (n != 0) {
            putchar_unlocked(' ');
            fastprint(n);
            fastscan(&n);
        }
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
