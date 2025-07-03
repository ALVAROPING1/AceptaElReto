#include <stdio.h>
#include <string.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    do {
        *number = *number * 10 + c - '0';
    } while ((c = getchar_unlocked()) >= '0');
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
}

#define MAX 300001

// When calculating the permutation, it is enough to calculate the contribution
// for each digit individually. Applying the contribution from the k-th digit
// has the effect of going over all permutations of the remaining k numbers k_i
// times, where k_i is the value of the k-th digit (since the amount of
// permutations would be k_i * k!). This has the effect of moving the k_i-th
// number to the k+1 position and shifting the following numbers over, leaving
// the elements at positions >k+1 unchanged (changing elements in those
// positions would require going over >(k+1)! permutations, but at most we can
// go over k*k! and k*k! < (k+1) * k! = (k+1)!)
//
// We start with an array of numbers [1, N]. If we start processing the digits
// from the most significant one (left), the contribution from the first digit
// moves the k_N-th number to the first place and shifts over the rest. Since
// the first position is now correct, we can recursively solve the following
// values by repeating the process with the numbers in positions [2, N] and the
// remaining k-1 digits, until the list is empty. This process can also be seen
// as repeatedly taking the k_i-th value out of the list of numbers until it is
// empty
//
// Since the process of taking out a number doesn't reorder the remaining ones,
// we don't need to store them. Instead, we can store which numbers have been
// placed in their correct positions as an array of booleans. For each digit k,
// we can find the k-th unused number in this array and mark it as used
//
// This can be done efficiently by using a Fenwick tree and a predicate that
// counts the amount of unused numbers (addition if the booleans are stored as
// integer). To find the k-th unused number, we can use binary search on the
// endpoint of ranges [0, i] to find the position that results in k unused
// numbers in the range (since the predicate is monotonic). Fenwick trees allow
// updating the i-th value and querying the range [0, i] in O(log n). Since we
// need to perform log n queries for the binary search, this has a complexity of
// O(log² n) for each digit. This can be improved to O(log n) by combining the
// binary search and the queries into a single operation by using binary
// lifting (https://codeforces.com/blog/entry/61364), for a final complexity of
// O(n log n)

int bit[MAX]; // binary indexed tree
int size;

// Fenwick tree initialization
inline void init() {
    memset(bit, 0, (size + 1) * sizeof(int));
    int i;
    for (i = 0; i <= size; i++) {
        bit[i] += 1;
        int r = i + (i & -i);
        if (r <= size) { bit[r] += bit[i]; }
    }
}

// Finds the k-th unused number using binary lifting
inline int find_k(int k) {
    int idx = 0, d;
    for (d = 1 << 18; d > 0; d >>= 1) {
        if ((idx | d) <= size && bit[idx | d] <= k) {
            k -= bit[idx | d];
            idx |= d;
        }
    }
    return idx + 1;
}

// Fenwick tree value update
inline void update(int idx, int delta) {
    for (; idx <= size; idx += (idx & -idx)) {
        bit[idx] += delta;
    }
}

int main() {
    int n, i;
    fastscan(&n);
    while (n--) {
        // Read the amount of digits
        fastscan(&size);
        // Initialize the Fenwick tree
        init();
        // For each digit except the last
        for (i = 0; i < size - 1; ++i) {
            int k;
            // Read the number
            fastscan(&k);
            // Find the k-th unused value
            int res = find_k(k);
            // Mark the value as used
            update(res, -1);
            // Print the number separated by a space
            fastprint(res);
            putchar_unlocked(' ');
        }
        // The last number has a weight of 0!, so it must be 0
        // Consume the digit and new line
        getchar_unlocked();
        getchar_unlocked();
        // Calculate and print the result, followed by a new line
        fastprint(find_k(0));
        putchar_unlocked('\n');
    }
    return 0;
}
