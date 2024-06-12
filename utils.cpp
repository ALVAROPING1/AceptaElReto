#include <bits/stdc++.h>

// Read positive number
template <typename T> inline void fastscan_positive(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

// Read positive/negative number
template <typename T> inline void fastscan(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        number = number * 10 + c - '0';

    if (negative) number *= -1;
}

// Read an entire line, returning its length
template <typename T> inline int fastscan_line(T& line) {
    // Keep on extracting characters if they aren't the line terminator
    register int i = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return 0;
    for (; c != '\n'; c = getchar_unlocked())
        line[i++] = c;
    line[i] = '\0';
    return i;
}

template <typename T> inline void fastprint_positive(T number) {
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

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // Replace stdin for debugging
    freopen("in.txt", "r", stdin);
}
