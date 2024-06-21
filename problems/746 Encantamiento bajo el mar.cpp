#include <bits/stdc++.h>

template <typename T> inline void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
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
    putchar_unlocked('\n');
}

#define CALC_PAIRS(pos)                                                        \
    vec[pos - 1] == half and even ? curr[0] / 2 : std::min(curr[0], curr[1])

int main() {
    int vec[300000];
    int n, d;
    fastscan(n);
    fastscan(d);
    while (n != 0 or d != 0) {
        int half = d >> 1;
        bool even = (d & 1) == 0;
        // Parse the input
        int i = n;
        while (i--) {
            int curr;
            // Read the numbers
            fastscan(curr);
            // If it's bigger than half the distance, convert it to the value
            // needed to reach the distance (which will be smaller than half the
            // distance)
            // We only need 30 bits to represent the numbers, so we shift them
            // twice to the left and use the LSB to keep track if the number was
            // originally above or below half the target distance. This
            // maintains the order in the numbers, and allows checking if 2
            // numbers represent the same distance by checking if their
            // difference is <=1 (as different disntance representations will
            // have a difference of at least 3)
            vec[i] = curr > half ? ((d - curr) << 2) | 1 : curr << 2;
        }
        // Sort the numbers
        std::sort(vec, &vec[n]);
        // Calculate total pairs
        int total = 0;
        // Array to keep track of how many occurrences of the current distance
        // above/below half the target distance have been seen
        int curr[2] = {0};
        curr[vec[0] & 1] = 1;
        half = half << 2;
        for (int i = 1; i < n; ++i) {
            // Compare the current distance with the previous
            // If they are the same, increment the amount of times this distance
            // has been seen
            if (vec[i] - vec[i - 1] <= 1) ++curr[vec[i] & 1];
            else {
                // Otherwise, calculate the pairs for this distance and add it
                // to the total
                // If the target distance was even and the current distance is
                // half of it, the amount of pairs will just be half the amount
                // of times the distance has been seen. Otherwise, take the
                // minimum between the distances below and above half the
                // distance
                total += CALC_PAIRS(i);
                // Reset the array to prepare for the next distance
                curr[vec[i] & 1] = 1;
                curr[not(vec[i] & 1)] = 0;
            }
        }
        // Add the pairs from the last distance
        total += CALC_PAIRS(n);
        // Print the results
        fastprint(total);
        fastscan(n);
        fastscan(d);
    }
    return 0;
}
