#include <bits/stdc++.h>

// Max line size (+1 for the null terminator byte)
const int MAX = 81;

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char input[MAX];
    int calls[MAX - 1][MAX - 1];
    // Base cases
    for (unsigned int i = 0; i < MAX - 1; ++i) {
        calls[i][i] = 1;
    }
    // Read first line
    std::cin.getline(input, MAX);
    while (std::cin) { // While there are lines to read
        int len = strlen(input);
        // Recursive cases
        for (unsigned int end = 1; end < len; ++end) {
            for (int start = end - 1; start >= 0; --start) {
                if (input[end] == input[start] and end - start != 1) {
                    int end2 = end - 1, start2 = start + 1;
                    while (input[end2] == input[end])
                        --end2;
                    while (input[start2] == input[start])
                        ++start2;
                    calls[end][start] =
                        end2 >= start2 ? calls[end2][start2] + 1 : 1;
                } else {
                    calls[end][start] = std::min(
                        calls[end][start + 1] +
                            (input[start] != input[start + 1]),
                        calls[end - 1][start] + (input[end] != input[end - 1]));
                }
            }
        }
        // Print the result and read the next line
        std::cout << calls[len - 1][0] << "\n";
        std::cin.getline(input, MAX);
    }
    return 0;
}
