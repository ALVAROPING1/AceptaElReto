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
        int max, min;
        fastscan(max);
        // Ignore separator
        getchar_unlocked();
        getchar_unlocked();
        fastscan(min);
        if (max >= min) {
            std::cout << "BIEN" << "\n";
        } else {
            std::cout << "MAL" << "\n";
        }
    }
    return 0;
}
