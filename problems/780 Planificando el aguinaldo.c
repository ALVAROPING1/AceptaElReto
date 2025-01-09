#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
    char buffer[32];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

#define MAX 500000

int values[MAX];
long long sums[MAX];

// Maybe a dynamic programming table can accelerate this?
// Maybe use a stack (pushing right range first) for dfs prioritising left
// edge, and reuse the already calculated result for all left-most children?
//
// For some reason, even just converting this function from recursive to
// iterative makes it slower and results in a TLE
long long find_max(int size, int start, int end) {
    if (start >= end) return 0;
    if (start + 1 == end) return sums[start];
    long long max = -1;
    int max_i = -1;
    int i;
    for (i = start; i < end; ++i) {
        if (sums[i] > max) {
            max = sums[i];
            max_i = i;
        }
    }
    return find_max(size, start, max_i - size + 1) + max +
           find_max(size, max_i + size, end);
}

int main() {
    int n, k;
    fastscan(&n);
    fastscan(&k);
    int i;
    while (n != 0 && k != 0) {
        long long total = 0;
        for (i = 0; i < n; ++i) {
            int x;
            fastscan(&x);
            total += x;
            values[i] = x;
        }
        long long curr = 0;
        for (i = 0; i < k; ++i) {
            curr += values[i];
        }
        sums[0] = curr;
        for (; i < n; ++i) {
            curr += values[i];
            curr -= values[i - k];
            sums[i - k + 1] = curr;
        }
        long long gotten = find_max(k, 0, i - k + 1);
        fastprint(total - gotten);
        fastscan(&n);
        fastscan(&k);
    }
    return 0;
}
