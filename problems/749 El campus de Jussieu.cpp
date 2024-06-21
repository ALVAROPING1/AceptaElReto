#include <bits/stdc++.h>

template <typename T> inline void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
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

// Converts the grid position to a single ID
inline long long id(long long i, long long j) {
    return i * 100000 + j;
}

// Marks the grid position as removed
inline void set(std::unordered_set<long long>& set, long long i, long long j) {
    set.insert(id(i, j));
}

// Checks if the grid position has been removed already
inline bool
check(std::unordered_set<long long>& set, long long i, long long j) {
    return set.find(id(i, j)) == set.end();
}

int main() {
    std::unordered_set<long long> memory{};
    int c, f, h;
    fastscan(c);
    fastscan(f);
    fastscan(h);
    while (c != 0 or f != 0 or h != 0) {
        // Calculate the amount of grid edges assuming no points have been
        // removed
        long long total = (long long) c * (f - 1) + (long long) f * (c - 1);
        // For each removed point
        while (h--) {
            int i, j;
            fastscan(i);
            fastscan(j);
            // Decrement the amount of edges for each adjacent point that hasn't
            // been removed
            total -= (i > 1) and (check(memory, i - 1, j));
            total -= (j > 1) and (check(memory, i, j - 1));
            total -= (i < c) and (check(memory, i + 1, j));
            total -= (j < f) and (check(memory, i, j + 1));
            // Mark the current point as removed
            set(memory, i, j);
        }
        // Print the results and prepare for the next test case
        fastprint(total);
        memory.clear();
        fastscan(c);
        fastscan(f);
        fastscan(h);
    }
    return 0;
}
