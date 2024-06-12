#include <stdbool.h>
#include <stdio.h>

inline void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan(int* number) {
    bool negative = false;
    register int c;
    *number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';

    if (negative) *number *= -1;
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

// Read vector of values
inline int read_vals(int values[]) {
    int i = -1;
    do {
        fastscan(&values[++i]);
    } while (values[i] != -1);
    return i;
}

int main() {
    // Magic size number, smaller is slower (likely due to cache conflicts)
    int values[32768];
    int ops[32768];
    // Read values of the first case
    int n_vals = read_vals(values);
    // While the current case isn't the last one
    while (n_vals != 0) {
        // Read the vector of operations and store it in reverse
        int n_ops;
        fastscan_positive(&n_ops);
        int i = n_ops;
        while (--i >= 0) {
            fastscan_positive(&ops[i]);
        }
        // Apply the operations in reverse to the rightmost element's position
        // to figure out where it started
        // Use index starting from the right to simplify calculations
        int pos = 0;
        for (i = 0; i < n_ops; ++i) {
            // If the current reverse operation affects the current value,
            // calculate its new (previous in the normal order) position
            if (pos < ops[i]) pos = ops[i] - pos - 1;
        }
        // Get the value at the calculated start position and print it
        fastprint(values[n_vals - pos - 1]);
        // Read the vector of values for the next case
        n_vals = read_vals(values);
    }
    return 0;
}
