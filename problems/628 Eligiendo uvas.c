#include <stdbool.h>
#include <stdio.h>

inline bool fastscan_check(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastscan(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
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
}

inline long long max(long long a, long long b) {
    return a > b ? a : b;
}

inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    long long curr_flavor, curr_thickness;
    while (fastscan_check(&curr_flavor)) {
        fastscan(&curr_thickness);
        long long max_flavor = curr_flavor;
        long long min_thickness = curr_thickness;
        long long best_flavor = curr_flavor;
        long long best_thickness = curr_thickness;
        fastscan(&curr_flavor);
        fastscan(&curr_thickness);
        while (curr_flavor != 0 || curr_thickness != 0) {
            max_flavor = max(max_flavor, curr_flavor);
            min_thickness = min(min_thickness, curr_thickness);
            if (curr_flavor >= best_flavor &&
                curr_thickness <= best_thickness) {
                best_flavor = curr_flavor;
                best_thickness = curr_thickness;
            }
            fastscan(&curr_flavor);
            fastscan(&curr_thickness);
        }
        if (best_flavor == max_flavor && best_thickness == min_thickness) {
            fastprint(best_flavor);
            putchar_unlocked(' ');
            fastprint(best_thickness);
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
            putchar_unlocked(' ');
            putchar_unlocked('H');
            putchar_unlocked('A');
            putchar_unlocked('Y');
            putchar_unlocked(' ');
            putchar_unlocked('M');
            putchar_unlocked('E');
            putchar_unlocked('J');
            putchar_unlocked('O');
            putchar_unlocked('R');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
