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
    while (n != 0) {
        int prev, curr;
        bool fail = false;
        fastscan(prev);
        while (--n) {
            fastscan(curr);
            fail = fail or curr <= prev;
            prev = curr;
        }
        if (fail) {
            std::cout << "NO\n";
        } else {
            std::cout << "SI\n";
        }
        fastscan(n);
    }
    return 0;
}
