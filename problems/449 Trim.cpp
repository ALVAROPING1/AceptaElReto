#include <bits/stdc++.h>

// Max line size (+1 for the null terminator byte)
const int MAX = 81;

template <typename T> inline int fastscan(T& line) {
    register int i = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return 0;
    for (; c != '\n'; c = getchar_unlocked())
        line[i++] = c;
    line[i] = '\0';
    return i;
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
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char input[MAX];
    short calls[MAX - 1][MAX - 1];
    // Base cases. We can preset them as they are never modified
    for (unsigned int i = 0; i < MAX - 1; ++i) {
        calls[i][i] = 1;
    }
    // Read first line
    int len = fastscan(input);
    while (len != 0) { // While there are lines to read
        // We don't need to clear the dynamic table because only positions that
        // have already been calculated/written for this line are read
        // Recursive cases
        for (int end = 1; end < len; ++end) {
            for (int start = end - 1; start >= 0; --start) {
                // Start and end characters of the current substring are equal
                if (input[end] == input[start] and end - start != 1) {
                    // Find the start/end of the substring of the trimmed word
                    int end2 = end - 1, start2 = start + 1;
                    while (input[end2] == input[end])
                        --end2;
                    while (input[start2] == input[start])
                        ++start2;
                    // If the result is an empty word, a single trim is needed.
                    // Otherwise, we need a trim plus the cost of the trimmed
                    // word
                    calls[end][start] =
                        end2 >= start2 ? calls[end2][start2] + 1 : 1;
                } else {
                    // Get the minimum cost of removing the first or last
                    // character. If the character is the same as the next
                    // inner character, there is no extra cost (it was already
                    // paid for by the innermost character of that sequence)
                    calls[end][start] = std::min(
                        calls[end][start + 1] +
                            (input[start] != input[start + 1]),
                        calls[end - 1][start] + (input[end] != input[end - 1]));
                }
            }
        }
        // Print the result and read the next line
        fastprint(calls[len - 1][0]);
        len = fastscan(input);
    }
    return 0;
}
