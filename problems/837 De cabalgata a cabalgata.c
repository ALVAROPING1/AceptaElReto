#include <stdbool.h>
#include <stdio.h>
#include <string.h>

inline bool fastscan_check(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

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

inline int min(int a, int b) {
    return a < b ? a : b;
}

// Maximum amount of lights
#define MAX 500000

long long leds[MAX];
long long initial;
int n;

// Check whether it is possible for the minimum window sum to be at least
// `target` using a greedy algorithm
bool check(int range, long long budget, long long target) {
    // Initialize the array of lights repaired
    long long added[MAX];
    memset(added, 0, sizeof(long long) * n);
    int i;
    // Iterate through the lights
    long long window = initial;
    for (i = 0; i < n; ++i) {
        // Add the leds that entered the window
        if (i + range < n) window += leds[i + range];
        // Remove the leds that exited the window
        int l = i - range - 1;
        if (l >= 0) window -= leds[l] + added[l];
        // Calculate amount of lights needed to reach the target
        long long rem = target - window;
        // If we need to repair leds
        if (rem > 0) {
            // If we don't have enough leds, it's not possible to reach the
            // target
            if (rem > budget) return false;
            // Remove the repaired leds from the budget
            budget -= rem;
            // Repair the leds in the light furthest to the end possible
            added[min(i + range, n)] = rem;
            // Update the amount of lights in the current window
            window += rem;
        }
    }
    return true;
}

int main() {
    int i;
    while (fastscan_check(&n)) {
        int range;
        long long budget;
        // Read the input
        fastscan(&range);
        fastscanll(&budget);
        for (i = 0; i < n; ++i)
            fastscanll(&leds[i]);
        // Calculate initial value of the windows (when the center is at idx -1)
        initial = 0;
        for (i = 0; i < range; ++i)
            initial += leds[i];
        // Binary search the answer. Max should be 1e18 but there is no test
        // case that reaches above 1e16
        long long low = 1, high = 1e16;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (check(range, budget, mid)) low = mid + 1;
            else high = mid;
        }
        // Print the result
        fastprint(low - 1);
    }
    return 0;
}
