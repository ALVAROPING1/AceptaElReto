#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number) {
    char buffer[16];
    register int i = -1;
    if (number < 0) {
        putchar_unlocked('-');
        number *= -1;
    }
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int tons, distance, pay, fuel_cost, travel_cost, salary;
        fastscan(&tons);
        fastscan(&distance);
        fastscan(&pay);
        fastscan(&fuel_cost);
        fastscan(&travel_cost);
        fastscan(&salary);
        fastprint(tons * distance * pay - distance * fuel_cost * 2 -
                  travel_cost - salary);
    }
    return 0;
}
