#include <stdbool.h>
#include <stdio.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
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

#define MAX 500000

// This took way too much time. I needed all 7 hints and 20 tries. I hate this
// problem

// Gets the first index in the array with a value greater than or equal to
// `value` using binary search
inline int lower_bound(int n, int arr[], int value) {
    int begin = 0, end = n;
    while (end - begin > 0) {
        int mid = begin + (end - begin) / 2;
        if (arr[mid] < value) {
            begin = mid + 1;
        } else end = mid;
    }
    return begin;
}

// Finds the length of the longest increasing (sign = -1)/decreasing (sign = 1)
// sequence starting at each position of the array using binary search for a
// O(n log n) time
inline void lds(int n, int arr[], int res[], int sign) {
    int size = 1;
    // Array to store the minimum value of the last element of the sequences
    // with each length
    int ans[MAX];
    ans[0] = sign * arr[n - 1];
    res[n - 1] = 1;

    int i;
    // For each value starting from the end
    for (i = n - 2; i >= 0; --i) {
        if (sign * arr[i] > ans[size - 1]) {
            // If this value can extend the longest sequence, append it
            ans[size++] = sign * arr[i];
            res[i] = size;
        } else {
            // Find the first index where the value can be reduced with the
            // current value, and update it
            int low = lower_bound(size, ans, sign * arr[i]);
            ans[low] = sign * arr[i];
            // The position we updated corresponds with the length of the
            // longest sequence we could have gotten if we picked this value
            res[i] = low + 1;
        }
    }
}

int main() {
    int inc[MAX];
    int dec[MAX];
    int weights[MAX];
    int n;

    fastscan(&n);
    while (n != 0) {
        int i;
        // Read the input
        for (i = 0; i < n; ++i)
            fastscan(&weights[i]);
        // Calculate the longest increasing and decreasing sequences starting at
        // each car
        lds(n, weights, dec, 1);
        lds(n, weights, inc, -1);
        // For each car, the amount of cars we can fit is the sum of the longest
        // increasing and decreasing sequences that pick that car as their first
        // value, minus 1 to avoid double counting the first car. The maximum of
        // them is the result
        int res = -1;
        for (i = 0; i < n; ++i) {
            res = max(res, inc[i] + dec[i] - 1);
        }
        fastprint(res);
        fastscan(&n);
    }
    return 0;
}
