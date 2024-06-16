#include <bits/stdc++.h>

// Max vector size (+1 for an extra first element)
const size_t MAX = 100 + 1;

inline void fastscan(short* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
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
}

inline void solve1(int n) {
    std::array<short, MAX> vector;
    int i = n;
    // Read values to array
    while (i--)
        fastscan(&vector[i]);
    // Duplicate the leftmost value
    vector[n] = vector[n - 1];
    // For each value starting from the right
    i = 0;
    while (true) {
        // If the value is equal to the value at its left, it can be incremented
        if (vector[i] == vector[i + 1]) {
            ++vector[i];
            break;
        }
        ++i;
    }
    // Reset all values to its right to the incremented value
    int j = i - 1;
    while (--j >= 0)
        vector[j] = vector[i];
    // Print the result
    fastprint(vector[n - 1]);
    i = n - 1;
    while (i--) {
        putchar_unlocked(' ');
        fastprint(vector[i]);
    }
}

// Equivalent (same speed), theoretically faster if there were 128bit ints
void solve2(int n) {
    uint_fast64_t lower = 0, upper = 0;
    short prev, curr;
    // Read first value and store it
    std::cin >> curr;
    short first = curr;
    // Convert the vector of differences to a `MAX` bits integer, where
    // differences are read from MSB to LSB. Since there are no 128bit integers,
    // it has to be split into 2 64bit ints
    auto read_val = [&](int start, uint_fast64_t& field) {
        for (int i = start; i >= 0; --i) {
            prev = curr;
            std::cin >> curr;
            // If it's different from the previous, set its bit
            if (prev != curr) field |= 1ULL << i;
        }
    };
    read_val(n - 2 - 64, upper);
    read_val(std::min(n - 2, 63), lower);
    // Increment the lower bits
    ++lower;
    // If there was an overflow, carry the increment to the upper bits
    upper += lower == 0;
    // Convert the integer back to a vector and print it

    // Check if the first number needs to be incremented and print it
    if (n > 64) {
        first += (upper & (1ULL << (n - 1 - 64))) != 0;
    } else {
        first += (lower & (1ULL << (n - 1))) != 0;
    }
    std::cout << first;
    auto write_val = [&](int start, uint_fast64_t field) {
        for (int i = start; i >= 0; --i) {
            first += (field & (1ULL << i)) != 0;
            std::cout << ' ' << first;
        }
    };
    write_val(n - 2 - 64, upper);
    write_val(std::min(n - 2, 63), lower);
}

int main() {
    short n;
    fastscan(&n);
    while (n > 0) {
        solve1(n);
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
