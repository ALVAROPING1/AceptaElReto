#include <bits/stdc++.h>

inline void fastscan_positive(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#define MAX 300000

// ╔═══════════════════════════════════════════════════════════════════════════╗
// ║                           Segment Tree solution                           ║
// ╚═══════════════════════════════════════════════════════════════════════════╝

// Use a segment tree to store the values to be able to perform range queries
// and value updates in O(n log n)

// Quickly scan if the next number is positive, negative, or zero
inline void fastscan_sign(int* number) {
    register int c = getchar_unlocked();
    if (c == '-') *number = -1;
    else if (c == '0') *number = 0;
    else *number = 1;
    while (getchar_unlocked() >= '0') {}
}

// Segment tree predicate. We only store the sign of the numbers, so multiplying
// them is enough to get the sign of their multiplication
inline int mul(int l, int r) {
    return l * r;
}

class SegmentTree {
  protected:
    using size_type = ptrdiff_t;
    using index_type = ptrdiff_t;
    using value_type = int;

    size_type count_;
    int data_[MAX * 4];

    static inline constexpr index_type left(index_type x) {
        return x * 2 + 1;
    }
    static inline constexpr index_type right(index_type x) {
        return x * 2 + 2;
    }

  public:
    SegmentTree(int* begin, int* end) : count_{end - begin} {
        build(0, begin, end);
    }

    // Query the value in range [begin, end)
    int query(index_type begin, index_type end) const {
        return query(0, 0, count_, begin, end);
    }

    // Update a value
    void update(index_type pos, int value) {
        update(0, 0, count_, pos, value);
    }

  private:
    void build(index_type node, int* begin, int* end) {
        if (begin + 1 == end) data_[node] = *begin;
        else {
            auto half = begin + (end - begin + 1) / 2;
            build(left(node), begin, half);
            build(right(node), half, end);
            data_[node] = mul(data_[left(node)], data_[right(node)]);
        }
    }

    int query(index_type node,
              index_type first,
              index_type last,
              index_type begin,
              index_type end) const {
        if (first >= begin and last <= end) {
            return data_[node];
        } else {
            index_type half = first + (last - first + 1) / 2;
            int result{1};
            if (half > begin and first < end) {
                result = query(left(node), first, half, begin, end);
            }
            if (last > begin and half < end) {
                auto other = query(right(node), half, last, begin, end);
                result = mul(result, other);
            }
            return result;
        }
    }

    void update(index_type node,
                index_type begin,
                index_type end,
                index_type pos,
                int value) {
        if (begin + 1 == end) {
            data_[node] = value;
        } else {
            index_type half = begin + (end - begin + 1) / 2;
            if (pos < half) {
                update(left(node), begin, half, pos, value);
            } else {
                update(right(node), half, end, pos, value);
            }
            data_[node] = mul(data_[left(node)], data_[right(node)]);
        }
    }
};

int solve1() {
    int n, c;
    fastscan_positive(&n);
    fastscan_positive(&c);

    int values[MAX];
    while (n != 0 && c != 0) {
        // Read the starting values and initialize the segment tree
        // Since we only ever care about the sign of values, there is no
        // need to actually parse the number. Getting its sign and ignoring the
        // input until the next number/new line is enough
        for (int i = 0; i < n; ++i)
            fastscan_sign(&values[i]);
        SegmentTree tree{&values[0], &values[n]};
        // For each operation
        while (c--) {
            char op = getchar_unlocked(); // Get its type
            getchar_unlocked();           // Ignore space
            if (op == 'C') {              // Change value
                int pos, new_val;
                fastscan_positive(&pos);
                fastscan_sign(&new_val);
                tree.update(pos - 1, new_val);
            } else { // Query range
                int start, end;
                fastscan_positive(&start);
                fastscan_positive(&end);
                int res = tree.query(start - 1, end);
                if (res == 0) putchar_unlocked('0');
                else if (res < 0) putchar_unlocked('-');
                else putchar_unlocked('+');
            }
        }
        putchar_unlocked('\n');
        fastscan_positive(&n);
        fastscan_positive(&c);
    }
    return 0;
}

// ╔═══════════════════════════════════════════════════════════════════════════╗
// ║                           Fenwick Tree solution                           ║
// ╚═══════════════════════════════════════════════════════════════════════════╝

// Use a simpler fenwick tree to store the values and be able to perform
// updates/queries. Has the same complexity as a segment tree, but it's faster
// in practice due to being simpler (which also makes it more restrictive)
//
// Fenwick trees can only answer queries for ranges [0, r], for ranges [l, r]
// the ranges for [0, l-1] and [0, r] must be combined. We can store the amount
// of zeros and negative numbers in each range and perform a subtraction for the
// combination. The result of the multiplication of the numbers in the range
// will be:
// - 0 if there are any zeros
// - -1 if the amount of negative numbers is odd
// - 1 otherwise

// Struct to store the counts
struct Value {
    int zeros, negatives;
};

// Quickly scan a number and convert it to the `Value` struct
inline void fastscan_sign(Value* number) {
    register int c = getchar_unlocked();
    if (c == '-') *number = {0, 1};
    else if (c == '0') *number = {1, 0};
    else *number = {0, 0};
    while (getchar_unlocked() >= '0') {}
}

class FenwickTree {
  protected:
    Value bit_[MAX]; // binary indexed tree
    int n_;

  public:
    FenwickTree(int n) {
        n_ = n;
        for (int i = 0; i < n; ++i)
            bit_[i] = Value{0, 0};
    }

    FenwickTree(int size, Value a[]) : FenwickTree(size) {
        for (int i = 0; i < n_; i++) {
            bit_[i].zeros += a[i].zeros;
            bit_[i].negatives += a[i].negatives;
            int r = i | (i + 1);
            if (r < n_) {
                bit_[r].zeros += bit_[i].zeros;
                bit_[r].negatives += bit_[i].negatives;
            }
        }
    }

    Value query(int l, int r) {
        Value res = query(r);
        Value res2 = query(l - 1);
        res.zeros -= res2.zeros;
        res.negatives -= res2.negatives;
        return res;
    }

    Value query(int r) {
        Value ret = {0, 0};
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret.zeros += bit_[r].zeros;
            ret.negatives += bit_[r].negatives;
        }
        return ret;
    }

    void update(int idx, Value delta) {
        for (; idx < n_; idx = idx | (idx + 1)) {
            bit_[idx].zeros += delta.zeros;
            bit_[idx].negatives += delta.negatives;
        }
    }
};

int solve2() {
    int n, c;
    fastscan_positive(&n);
    fastscan_positive(&c);

    Value values[MAX];
    while (n != 0 && c != 0) {
        // Read the starting values and initialize the fenwick tree
        // Since we only ever care about the sign of values, there is no
        // need to actually parse the number. Getting its sign and ignoring the
        // input until the next number/new line is enough
        for (int i = 0; i < n; ++i)
            fastscan_sign(&values[i]);
        FenwickTree tree{n, values};
        // For each operation
        while (c--) {
            char op = getchar_unlocked(); // Get its type
            getchar_unlocked();           // Ignore space
            if (op == 'C') {              // Change value
                int pos;
                Value val;
                fastscan_positive(&pos);
                fastscan_sign(&val);
                --pos;
                // Calculate the difference in the counts
                Value delta = {val.zeros - values[pos].zeros,
                               val.negatives - values[pos].negatives};
                values[pos] = val; // Update the value in the original array
                tree.update(pos, delta); // Apply the update in the fenwick tree
            } else {                     // Query range
                int start, end;
                fastscan_positive(&start);
                fastscan_positive(&end);
                Value res = tree.query(start - 1, end - 1);
                if (res.zeros > 0) putchar_unlocked('0');
                else if (res.negatives % 2 == 1) putchar_unlocked('-');
                else putchar_unlocked('+');
            }
        }
        putchar_unlocked('\n');
        fastscan_positive(&n);
        fastscan_positive(&c);
    }
    return 0;
}

int main() {
    return solve2();
}
