#include <bits/stdc++.h>

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while (n > 0) {
        int total = 0;
        int curr;
        while (n--) {
            std::cin >> curr;
            total += curr;
        }
        std::cout << total << '\n';
        std::cin >> n;
    }
    return 0;
}
