#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
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
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
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

inline void solve(int h, int n, int heights[20]) {
    int inf = 0, sup = INT32_MAX;
    int a, b, c, d;
    // Iterate through all unique 4-tuples of heights
    for (a = 0; a < n; ++a) {
        for (b = a + 1; b < n; ++b) {
            int mult1 = lcm(heights[a], heights[b]);
            for (c = b + 1; c < n; ++c) {
                int mult2 = lcm(mult1, heights[c]);
                for (d = c + 1; d < n; ++d) {
                    // Calculate the least common multiple of the heights
                    int mult = lcm(mult2, heights[d]);
                    // If the target is a multiple of the LCM, it can be
                    // obtained exactly with this combination. We don't need to
                    // check any more combinations
                    int mod = h % mult;
                    if (mod == 0) {
                        fastprint(h);
                        putchar_unlocked(' ');
                        fastprint(h);
                        return;
                    }
                    // Otherwise, update the lower and upper limits that can be
                    // obtained
                    inf = max(h - mod, inf);
                    sup = min(h - mod + mult, sup);
                }
            }
        }
    }
    // Print the result
    fastprint(inf);
    putchar_unlocked(' ');
    fastprint(sup);
}

int main() {
    int h;
    while (fastscan(&h)) {
        int n, i;
        fastscan(&n);
        int heights[20];
        for (i = 0; i < n; ++i)
            fastscan(&heights[i]);
        solve(h, n, heights);
        putchar_unlocked('\n');
    }
    return 0;
}
