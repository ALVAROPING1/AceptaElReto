#include <stdio.h>

inline void fastscan(int* number) {
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

// Maximum amount of combinations of unique digits
#define MAX 1 << 10

int main() {
    int n;
    fastscan(&n);
    int keys[MAX]; // Array of unique keys seen
    while (n--) {
        int k, i, j;
        fastscan(&k);
        int cards[MAX] = {0}; // Amount of cards seen for each key
        int n_keys = 0;       // Amount of unique keys seen
        while (k--) {
            // Read the card and convert it to a bitfield where each bit
            // determines if the number has the respective digit
            char c;
            int mask = 0;
            while ((c = getchar_unlocked()) >= '0')
                mask |= 1 << (c - '0');
            // If it's the first time we have seen this key, append it to the
            // keys vector
            if (cards[mask] == 0) keys[n_keys++] = mask;
            ++cards[mask]; // Update the frequency of this key
        }

        long long total = 0;
        // For each unique key
        for (i = 0; i < n_keys; ++i) {
            long long amount = cards[keys[i]];
            // Calculate the amount of pairs of cards with the same key
            total += amount * (amount - 1) / 2;
            // Calculate the amount of pairs of cards with previous keys (to
            // avoid counting the same key twice)
            for (j = 0; j < i; ++j)
                // If the keys share a bit, add the amount of pairs of cards
                // between the groups (cartesian product)
                if ((keys[i] & keys[j]) != 0) total += amount * cards[keys[j]];
        }
        fastprint(total);
    }
    return 0;
}
