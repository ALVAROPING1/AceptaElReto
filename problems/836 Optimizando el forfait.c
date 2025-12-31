#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscanll(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
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
    putchar_unlocked(' ');
}

inline void fastprintll(long long number) {
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

int main() {
    int n, holidays, i;
    fastscan(&n);
    fastscan(&holidays);
    long long window[1000]; // Circular buffer for the last `holiday` values

    while (n != 0 && holidays != 0) {
        long long window_sum = 0;
        long long min = 0x7fffffffffffffff;
        int min_pos = -1;
        // Read the first possible holiday window, keeping track of its sum,
        // min, position of the min, and each value
        for (i = 0; i < holidays; ++i) {
            long long x;
            fastscanll(&x);
            window[i] = x;
            window_sum += x;
            // We need to keep the last position in which we saw the min value
            if (x <= min) {
                min = x;
                min_pos = i;
            }
        }
        int best_start = 0;
        long long best_total = window_sum;
        // For each remaining holiday end day
        for (i = holidays; i < n; ++i) {
            long long x;
            fastscanll(&x);
            // Remove the oldest value from the window and add the current
            // value, recalculating the sum
            window_sum += x - window[i % holidays];
            window[i % holidays] = x;
            // If we found a new min, the only possible solution is the one
            // that ends on the new min
            if (x < min) {
                best_start = i - holidays + 1;
                best_total = window_sum;
                min = x;
                min_pos = i;
                continue;
            }
            // We need to keep the last position in which we saw the min value
            if (x == min) min_pos = i;
            // If the min position is within the current window and we got a
            // lower total, update the best possible solution found
            if (min_pos >= i - holidays && window_sum < best_total) {
                best_start = i - holidays + 1;
                best_total = window_sum;
            }
        }
        // Print results and read next case
        fastprint(best_start + 1);
        fastprintll(best_total);
        fastscan(&n);
        fastscan(&holidays);
    }
    return 0;
}
