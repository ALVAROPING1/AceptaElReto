#include <stdbool.h>
#include <stdio.h>

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

inline void fastprint(int number) {
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

// Maximum amount of levels
#define MAX 20

// Check whether it is possible to fill `people` cups with the given amount of
// bottles
bool check(int levels,
           long long bottle_size,
           int people,
           long long capacity[2],
           int n) {
    // State of the bottles at the current and next level, split between even
    // and odd positions. Since the setup is symmetrical, we only care about the
    // right halve (using 1-indexing to avoid issues with the left overflow of
    // the central cup)
    long long bottles[MAX + 1] = {0};
    int i, r = 2, level;
    bottles[1] = n * bottle_size;
    int full = 0; // Total amount of filled bottles
    for (level = 0; level < levels; ++level) {
        bool end = true;
        // For each cup in the current level
        for (i = 1+(level&1); i < r; i += 2) {
            // Calculate overflow
            long long x = bottles[i] - capacity[level & 1];
            // Clear the cup in preparation for the 2nd next level
            bottles[i] = 0;
            // If the cup was filled
            if (x >= 0) {
                // Update the amount of filled bottles and check if we reached
                // the goal
                full += 1 + (i != 1);
                if (full >= people) return true;
                // If there was no overflow, we can stop with the current row,
                // as the sequence of values is strictly decreasing
                if (x == 0) break;
                // Distribute overflow over the adjacent cups (opposite parity)
                bottles[i - 1] += x / 2;
                bottles[i + 1] += x / 2;
                end = false;
            } else break;
        }
        // If there was no overflow in the current level, no more cups will be
        // filled
        if (end) return false;
        // The central cup should have gotten liquid from the one to its left,
        // but since we didn't process that cup we need to add it manually
        bottles[1] *= 2;
        // Update the range of cups that could have liquid
        ++r;
    }
    return false;
}

// Fixed point position
#define DIV 15

int main() {
    int levels, people;
    while (fastscan_check(&levels)) {
        int bottle_size;
        int capacity[2];
        // Read the input
        fastscan(&capacity[0]);
        fastscan(&capacity[1]);
        fastscan(&bottle_size);
        fastscan(&people);
        // Use fixed point numbers to avoid rounding errors
        long long cap[2] = {capacity[0] << DIV, capacity[1] << DIV};
        long long size = bottle_size << DIV;
        // Binary search the answer
        int low = 1, high = 2e7;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(levels, size, people, cap, mid)) high = mid - 1;
            else low = mid + 1;
        }
        // Print the result
        fastprint(high + 1);
    }
    return 0;
}
