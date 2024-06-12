#include <stdio.h>

// Max line size (+1 for the null terminator byte)
const int MAX = 81;

inline int fastscan(char* line) {
    register int i = -1;
    register int c = getchar_unlocked();
    if (c == EOF) return 0;
    for (; c != '\n'; c = getchar_unlocked())
        // Preprocess word by deleting duplicate characters
        if (line[i] != c) line[++i] = c;
    line[++i] = '\0';
    return i;
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

int min(int a, int b) {
    return a < b ? a : b;
}

// Dynamic programming table: minimum cost of trimming the word
//
// X: value doesn't matter, represents an empty word (0 cost)
// Main diagonal: words with a single character, base cases (1 cost)
// F: cost of the full word
//
// The table is filled row by row from top to bottom, and right to left for each
// row
//
// Example for a 4 character word:
//
//      start ptr
//      0 1 2 3
//     01 X X X
// end 1  1 X X
// ptr 2    1 X
//     3F     1

int main() {
    char input[MAX];
    short calls[MAX - 1][MAX - 1];
    // Base cases. We can preset them as they are never modified
    unsigned int i;
    for (i = 0; i < MAX - 1; ++i) {
        calls[i][i] = 1;
    }
    // Read first line
    int len = fastscan(input);
    while (len != 0) { // While there are lines to read
        // We don't need to clear the dynamic table because only positions that
        // have already been calculated/written for this line are read
        // Recursive cases
        int end, start;
        for (end = 1; end < len; ++end)
            for (start = end - 1; start >= 0; --start)
                calls[end][start] =
                    (input[end] == input[start]
                         ? calls[end - 1][start + 1]
                         : min(calls[end][start + 1], calls[end - 1][start])) +
                    1;
        // Print the result and read the next line
        fastprint(calls[len - 1][0]);
        len = fastscan(input);
    }
    return 0;
}
