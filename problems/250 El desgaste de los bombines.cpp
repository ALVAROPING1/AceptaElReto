#include <bits/stdc++.h>

// Read positive number
template <typename T> void fastscan_positive(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

// Read positive/negative number
template <typename T> void fastscan(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        number = number * 10 + c - '0';

    if (negative) number *= -1;
}

// Max amount of numbers
const size_t MAX = 1000001;

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::array<int, MAX> vals;
    int n;
    fastscan_positive(n);
    while (n != 0) {
        int total = 0;
        int i = n;
        while (i--) {
            fastscan(vals[i]);
            total += vals[i];
        }
        int res = n;
        i = n;
        int best_diff = std::abs(total);
        while (i--) {
            total -= 2 * vals[i];
            int curr_diff = std::abs(total);
            if (curr_diff < best_diff) {
                res = i;
                best_diff = curr_diff;
            }
        }
        std::cout << n - res << "\n";
        fastscan_positive(n);
    }
    return 0;
}
