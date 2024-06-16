#include <bits/stdc++.h>

// Read positive number
template <typename T> inline void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

template <typename T> inline void fastprint(T number) {
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

// Max value of a single coin
const size_t max_value = 200;
// Max amount of types of coins
const size_t max_types = 10;

int main() {
    // Init arrays
    std::array<int, max_value * max_types + 1> values_table;
    std::array<int, max_types> types;
    int n;
    fastscan(n);
    while (n--) {
        int n_types, max_coins;
        fastscan(n_types);
        fastscan(max_coins);
        int max_value = 0;
        // Read the types of steps
        for (int i = 0; i < n_types; ++i) {
            fastscan(types[i]);
            max_value = std::max(max_value, types[i]);
        }
        values_table.fill(100);
        // Base case
        values_table[0] = 0;
        // Recursive cases
        int end = max_value * max_coins;
        for (int i = 0; i < end; ++i) {
            int curr = values_table[i] + 1;
            if (curr > max_coins) continue;
            for (int j = 0; j < n_types; ++j) {
                int value = types[j];
                values_table[i + value] =
                    std::min(values_table[i + value], curr);
            }
        }
        int total = 0;
        for (int i = 1; i <= end; ++i)
            total += values_table[i] <= max_coins;
        // Print the result and reset the steps table
        fastprint(total);
    }
    return 0;
}
