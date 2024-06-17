#include <stdbool.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
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

inline int max(int a, int b) {
    return a > b ? a : b;
}

// Max tree depth
const int MAX = 1024;

int main() {
    int stack[MAX];
    int n;
    fastscan(&n);
    while (n--) {
        int max_depth = 0, depth = 0;
        // Explore the tree
        while (1) {
            // Read the current value and calculate the new max depth
            fastscan(&stack[depth]);
            ++depth;
            max_depth = max(max_depth, depth);
            // Remove the parent from the stack until reaching a parent with
            // more unprocessed children
            while (stack[depth - 1] == 0) {
                // If the root node has no more children, stop
                if (depth == 1) goto end;
                --depth;
                --stack[depth - 1];
            }
        }
    end:
        fastprint(max_depth);
    }
    return 0;
}
