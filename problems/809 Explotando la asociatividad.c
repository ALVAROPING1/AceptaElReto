#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastprint(unsigned int number) {
    char buffer[32];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
}

// Values should fit in a signed 32 bit int (as the max amount of operations
// should be 100^3 * 100 = 10^8), but for some reason it gives WA. Using
// unsigned 32 bit ints gives AC and should be just as fast

// Dynamic programming tables
// dp[end][start] = min/max amount of operations to multiply the matrix
// sequence [start, end]
// Base case: a single matrix (dp[i][i]), cost is 0. Use global data initialized
// to 0 to avoid having to initialize them ourselves. This cases won't be
// modified on test cases, so no need to reset the table
unsigned int dp_max[100][100] = {0};
unsigned int dp_min[100][100] = {0};

int main() {
    int n, i, j, k;
    while (fastscan(&n)) {
        int dims[101];
        for (i = 0; i <= n; ++i)
            fastscan(&dims[i]);
        // Recursive case: try to split the multiplication into 2 subgroups at
        // each mid point. Obtain the amount of operations of each subgroup
        // recursively, then add the amount of operations required to multiply
        // the results of the subgroups. The max/min amount of operations will
        // be the max/min for any mid point
        // i = start of sequence
        // j = end of sequence
        for (j = 1; j < n; ++j) {
            for (i = j - 1; i >= 0; --i) {
                // Use variables for the current loop to avoid memory accesses,
                // using dp tables directly is significantly slower
                unsigned int min_ops = UINT32_MAX;
                unsigned int max_ops = 0;
                // Try to split the sequence at each mid point
                for (k = i; k < j; ++k) {
                    // Multiply sequences X_i,k and X_k+1,j
                    // Operations to multiply the subgroups A and B:
                    // rows(A) * cols(A) * cols(B)
                    // rows(X_ij) = dims[i]
                    // cols(X_ij) = dims[j+1]
                    unsigned int cost = dims[i] * dims[k + 1] * dims[j + 1];
                    unsigned int min_cost =
                        dp_min[k][i] + dp_min[j][k + 1] + cost;
                    if (min_cost < min_ops) min_ops = min_cost;
                    unsigned int max_cost =
                        dp_max[k][i] + dp_max[j][k + 1] + cost;
                    if (max_cost > max_ops) max_ops = max_cost;
                }
                dp_min[j][i] = min_ops;
                dp_max[j][i] = max_ops;
            }
        }
        fastprint(dp_min[n - 1][0]);
        putchar_unlocked(' ');
        fastprint(dp_max[n - 1][0]);
        putchar_unlocked('\n');
    }
    return 0;
}
