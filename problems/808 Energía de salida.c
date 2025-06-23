#include <stdbool.h>
#include <stdio.h>

inline bool fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastscan(int* number) {
    bool negative = false;
    register int c;
    *number = 0;
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    if (negative) *number *= -1;
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

inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

// Worst case scenario has a single live and max amount of events (10^5) all of
// which are enemies with the maximum damage possible (10^7), in which case we
// would need a starting health of 10^12 + 1 => we need 64-bit ints for the
// health

int values[100000]; // Level events
int n;              // Amount of events in the level

// Check whether the level can be beaten with the given amount of lives and
// starting health
bool check(int lives, long long max_health) {
    long long health = max_health;
    int i;
    // For each event
    for (i = 0; i < n; ++i) {
        int curr = values[i];
        // Update the current health, clamping it at the max health (in case the
        // current event was a health pack)
        health = min(health + curr, max_health);
        // Check if we run of out health
        if (health <= 0) {
            // Update the amount of lives
            --lives;
            // If we run out of lives, we didn't beat the level
            if (lives == 0) return false;
            // Restore the health to the maximum health and take the damage
            // again
            health = max_health + curr;
            // If we run out of health, the current monster has more damage than
            // we have health => we can't beat the level regardless of the
            // amount of lives
            if (health <= 0) return false;
        }
    }
    // If we reached the end of the level without failing, we beat it
    return true;
}

int main() {
    int lives, i;
    while (fastscan_positive(&lives)) {
        fastscan_positive(&n);
        // Scan input and calculate upper bound for the solution
        long long curr = 0; // Current damage accumulated (non-positive)
        long long max = 0;  // Max damage accumulated at once in the level
        for (i = 0; i < n; ++i) {
            fastscan(&values[i]);
            // Update the current damage accumulated. Clamp it at 0 as we can't
            // heal above the starting health (corresponding with 0 damage
            // accumulated)
            curr = min(curr + values[i], 0LL);
            // Update max damage accumulated at once. Use the min as the numbers
            // are negative
            max = min(curr, max);
        }
        // Binary search to find the minimum starting health to beat the level
        long long low = 1, high = -max + 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(lives, mid)) high = mid - 1;
            else low = mid + 1;
        }
        // Print the result
        fastprint(high + 1);
    }
    return 0;
}
