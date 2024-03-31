#include <bits/stdc++.h>

template <typename T> void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

const size_t max_size = 21;

long long solve(int n) {
    int current;
    long long distance = 0;
    std::vector<int> mem(max_size, 0);
    while (n--) {
        fastscan(current);
        ++mem[current];
        std::fill(mem.begin(), mem.begin() + current, 0);
        distance = std::accumulate(mem.begin() + current, mem.end(), distance);
    }
    return distance;
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    fastscan(n);
    while (n > 0) {
        std::cout << solve(n) << "\n";
        fastscan(n);
    }
    return 0;
}
