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

// ──────────────────────── Segment tree implementation ─────────────────────

// Segment tree predicate. We are working with the indices of the values to
// reduce memory usage
inline int max(int a, int b) {
    return sums[a] >= sums[b] ? a : b;
}

int count_;
int data_[MAX * 4];

// Private methods

#define left(x) (x*2+1)
#define right(x) (x*2+2)

inline void _build(int node, int begin, int end) {
    if (begin + 1 == end) data_[node] = begin;
    else {
        int half = begin + (end - begin + 1) / 2;
        _build(left(node), begin, half);
        _build(right(node), half, end);
        data_[node] = max(data_[left(node)], data_[right(node)]);
    }
}

inline int _query(int node, int first, int last, int begin, int end) {
    if (first >= begin && last <= end) {
        return data_[node];
    } else {
        int half = first + (last - first + 1) / 2;
        int result = -1;
        if (half > begin && first < end) {
            result = _query(left(node), first, half, begin, end);
        }
        if (last > begin && half < end) {
            int other = _query(right(node), half, last, begin, end);
            if (result == -1) result = other;
            else result = max(result, other);
        }
        return result;
    }
}

// Public methods

inline void init_tree(int count) {
    count_ = count;
    _build(0, 0, count);
}

inline int query(int begin, int end) {
    return _query(0, 0, count_, begin, end);
}

// ─────────────────────────────────────────────────────────────────────────────

// Recursively find the maximum sum possible for a given segment
long long find_max(int size, int start, int end) {
    // Base cases
    if (start >= end) return 0;
    if (start + 1 == end) return sums[start];
    // Recursive case: find the current max, then search the left and right
    // segments. Use a segment tree to quickly get the max for any segment
    int max_i = query(start, end);
    long long max = sums[max_i];
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
        // Read the input and calculate the sum of all values
        for (i = 0; i < n; ++i) {
            int x;
            fastscan(&x);
            total += x;
            values[i] = x;
        }
        // Calculate the sum for each window
        long long curr = 0;
        for (i = 0; i < k; ++i)
            curr += values[i];
        sums[0] = curr;
        for (; i < n; ++i) {
            curr += values[i];
            curr -= values[i - k];
            sums[i - k + 1] = curr;
        }
        // Build the segment tree for queries
        init_tree(n - k + 1);
        // Find the maximum sum possible
        long long gotten = find_max(k, 0, n - k + 1);
        // Print the result and read the next case
        fastprint(total - gotten);
        fastscan(&n);
        fastscan(&k);
    }
    return 0;
}
