#include <bits/stdc++.h>

template <typename T> void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    fastscan(n);
    while (n--) {
        int distance, amount;
        fastscan(distance);
        fastscan(amount);
        int max_distance = 0;
        while (amount--) {
            int pos, radius;
            fastscan(pos);
            fastscan(radius);
            if (pos - radius <= max_distance)
                max_distance = std::max(max_distance, pos + radius);
        }
        if (max_distance >= distance) {
            std::cout << "SI" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
    }
    return 0;
}
