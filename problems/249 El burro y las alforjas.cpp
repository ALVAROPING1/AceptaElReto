#include <bits/stdc++.h>

template <typename T> void fastscan(T& number) {
    number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        number = number * 10 + c - '0';
}

// Max weight
const int MAX_WEIGHT = 20001;

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    fastscan(n);
    while (n--) {
        int max, t, curr;
        fastscan(max);
        fastscan(t);
        int total = 0;
        bool weights[MAX_WEIGHT] = {false};
        while (t--) {
            fastscan(curr);
            if (weights[curr]) { ++total; }
            weights[curr] = !weights[curr];
        }
        std::cout << std::min(max, total) << "\n";
    }
    return 0;
}
