#include <bits/stdc++.h>

const size_t max_holes = 500000;
const size_t max_size = 21;

long long solve(int n) {
    int current;
    long long distance = 0;
    std::vector<int> mem(max_size, 0);
    while (n--) {
        std::cin >> current;
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
    std::cin >> n;
    while (n > 0) {
        std::cout << solve(n) << "\n";
        std::cin >> n;
    }
    return 0;
}
