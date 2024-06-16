#include <stdio.h>

// Max line size (+1 for the null terminator byte)
const size_t MAX = 101;

inline int get_line(char line[MAX]) {
    register int i = 0;
    register int c = getchar_unlocked();
    for (; c != '\n'; c = getchar_unlocked())
        if (c != ' ') line[i++] = c;
    return i;
}

inline char lowercase(char c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

inline void is_palindrome(char input[], int n) {
    int end = n / 2;
    int i;
    // Iterate through half of the line
    for (i = 0; i < end; ++i) {
        // Check if it's palindrome at the current character
        if (lowercase(input[i]) != lowercase(input[n - i - 1])) {
            putchar_unlocked('N');
            putchar_unlocked('O');
            return;
        };
    }
    putchar_unlocked('S');
    putchar_unlocked('I');
}

int main() {
    char line[MAX];
    // Read first line
    int n = get_line(line);
    while (line[0] != 'X' || line[1] != 'X' || line[2] != 'X' ||
           n != 3) { // While there are lines to read
        // Print the result, reset the stack, and read the next line
        is_palindrome(line, n);
        putchar_unlocked('\n');
        n = get_line(line);
    }
    return 0;
}
