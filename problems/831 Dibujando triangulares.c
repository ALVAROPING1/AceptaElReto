#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
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
    putchar_unlocked('\n');
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int line, pow10;
        fastscan(&line);
        // Calculate initial/final value of the row
        int s = (line * (line - 1)) / 2 + 1;
        int e = s + line;
        int digits = 0;       // Current amount of digits of the numbers
        int x = s;            // First unprocessed number
        int total = line - 1; // Initialize the total with the amount of spaces
        // Calculate the first power of 10 above the initial value, and its
        // digits-1
        for (pow10 = 1; pow10 <= s; pow10 *= 10)
            ++digits;
        // While there are numbers to process in the current line
        while (x < e) {
            // Add the characters from the numbers up to the next power of 10 or
            // the end of the range
            total += (min(pow10, e) - x) * digits;
            // Update the next unprocessed number
            x = pow10;
            // Increase the amount of digits of the next number group and update
            // the next power of 10
            ++digits;
            pow10 *= 10;
        }
        // Print the result
        fastprint(total);
    }
    return 0;
}
