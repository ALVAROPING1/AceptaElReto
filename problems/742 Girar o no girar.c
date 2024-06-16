#include <stdio.h>

inline void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan_positive(&n);
    while (n--) {
        // Create memory arrays and reset them to 0
        int keep['1' + 1], rotate['1' + 1];
        keep['0'] = keep['1'] = rotate['0'] = rotate['1'] = 0;
        // Handle the first number
        register int c = getchar_unlocked();
        int first = c;
        int prev = c;
        ++rotate[first];
        // Handle all cases from the second
        for (c = getchar_unlocked(); c != '\n';
             prev = c, c = getchar_unlocked()) {
            // Increment the total occurrences of the current character
            ++rotate[c];
            // If the previous character was a '0', it was a possible starting
            // point for the keep case
            keep[c] += prev == '0';
        }
        // Handle the last case taking into account the first value for the keep
        // case
        keep[first] += prev == '0';
        // Calculate the survive probability of each action and print the result
        float p_keep = (float) keep['0'] / (keep['0'] + keep['1']);
        float p_rotate = (float) rotate['0'] / (rotate['0'] + rotate['1']);
        if (p_keep > p_rotate) {
            putchar_unlocked('N');
            putchar_unlocked('o');
            putchar_unlocked(' ');
            putchar_unlocked('g');
            putchar_unlocked('i');
            putchar_unlocked('r');
            putchar_unlocked('a');
            putchar_unlocked('r');
        } else if (p_keep < p_rotate) {
            putchar_unlocked('G');
            putchar_unlocked('i');
            putchar_unlocked('r');
            putchar_unlocked('a');
            putchar_unlocked('r');
        } else {
            putchar_unlocked('D');
            putchar_unlocked('a');
            putchar_unlocked(' ');
            putchar_unlocked('i');
            putchar_unlocked('g');
            putchar_unlocked('u');
            putchar_unlocked('a');
            putchar_unlocked('l');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
