#include <bits/stdc++.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
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

// Maximum amount of segments (+1 because we care about prefix sums, and need to
// represent the empty prefix)
const int constexpr MAX = 300001;

class FenwickTree {
  protected:
    int bit_[MAX]; // binary indexed tree
    int n_;

  public:
    FenwickTree(int n) {
        n_ = n;
        memset(bit_, 0, sizeof(int) * n);
    }

    int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit_[r];
        return ret;
    }

    void update(int idx, int delta) {
        for (; idx < n_; idx = idx | (idx + 1)) {
            bit_[idx] += delta;
        }
    }
};

using Pair = std::pair<int, int>;

int main() {
    int n;
    fastscan(&n);
    Pair sorted[MAX]; // Sorted array of prefix sums
    int idx[MAX];     // Lowest index of each prefix sum in the sorted array
    while (n != 0) {
        int target;
        fastscan(&target);
        // Read the segments and calculate the prefix sums
        sorted[0] = std::make_pair(0, 0);
        for (int i = 1; i <= n; i++) {
            int x;
            fastscan(&x);
            // `Target - x` is the amount of time saved over the opponent, i.e.
            // we want to calculate the amount of sequences whose sum is a
            // positive value. Using prefix sums that translates to the amount
            // of sequences that end with a higher value that the one they
            // started at:
            // sum(s, e) = prefix[e] - prefix[s] > 0 => prefix[e] > prefix[s]
            sorted[i] = std::make_pair(i, sorted[i - 1].second + target - x);
        }
        // Apply coordinate compression to reduce memory usage, since we will
        // need to store an int for each possible value. This doesn't change the
        // ordering of the points, and since we only care about the order
        // between pairs of prefix sums the result is unchanged
        //
        // Sort the prefix sums by their value while keeping track of their
        // original position
        std::sort(sorted, &sorted[n + 1], [](const Pair& a, const Pair& b) {
            return a.second < b.second;
        });
        int unique = 0; // First index of the current value in the sorted array
        idx[sorted[0].first] = 0;
        for (int i = 1; i <= n; ++i) {
            // If the current value is different from the previous one, we need
            // a new index for the values
            unique += sorted[i - 1].second != sorted[i].second;
            // Write the current index to the original position of the current
            // prefix sum
            idx[sorted[i].first] = unique;
        }
        // For each prefix sum, we need to count the amount of previous prefix
        // sums with a value strictly smaller than the current one, since each
        // of those can be the start point of a valid sequence (one that starts
        // at a value strictly smaller than its end value) that ends at the
        // current value. This can be done with a Fenwick Tree that counts the
        // amount of prefix sums with each value seen so far
        auto tree = FenwickTree(n + 1);
        long long total = 0;
        for (int i = 0; i <= n; ++i) {
            // Get the value of the current prefix sum
            int pos = idx[i];
            // Increment the total by the amount of previous prefix sums with
            // `value < pos`
            total += tree.query(pos - 1);
            // Increment the amount of prefix sums seen with the current value
            tree.update(pos, 1);
        }
        // Print the results and read the next case
        fastprint(total);
        fastscan(&n);
    }
    return 0;
}
