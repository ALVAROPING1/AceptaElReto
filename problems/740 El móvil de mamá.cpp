#include <bits/stdc++.h>

template <typename T> inline void fastscan_positive(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
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

struct pair {
    int total;
    int right;
    pair(int total, int right) : total(total), right(right) {}
};

int main() {
    int n;
    fastscan_positive(n);
    std::vector<pair> front, back;
    front.reserve(1024);
    back.reserve(1024);
    while (n--) {
        // Base case
        char c = getchar_unlocked() - '0';
        front.emplace_back(c, c);
        // For each character in the current line except the first
        while ((c = getchar_unlocked() - '0') != '\n' - '0') {
            // Recursive case: construct the new possible sums from the previous
            // Each sum can be extended in 2 ways: add the digit as a new term,
            // starting a new rightmost number, or append the digit to the end
            // of the rightmost number
            for (auto val : front) {
                back.emplace_back(val.total + c, c);
                int temp = val.right * 9 + c;
                back.emplace_back(val.total + temp, temp + val.right);
            }
            // Swap the buffers and clear the back buffer to prepare for the
            // next iteration. This allows reusing the previous front vector as
            // the back vector in the next iteration without extra
            // allocations/copies
            std::swap(front, back);
            back.clear();
        }
        // Sort the resulting sums
        std::sort(front.begin(), front.end(), [](pair x, pair y) {
            return x.total < y.total;
        });
        // Print the first (smallest) sum (guaranteed to exist)
        fastprint(front[0].total);
        // For each sum starting from the second
        for (auto i = front.begin() + 1; i < front.end(); ++i) {
            // If it's not a duplicate (equal to the previous), print it
            // prefixed by " "
            if (i->total != (i - 1)->total) {
                putchar_unlocked(' ');
                fastprint(i->total);
            }
        }
        // Print the final new line and clear the front vector
        putchar_unlocked('\n');
        front.clear();
    }
    return 0;
}
