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
        int len, curr;
        fastscan(len);
        int max = std::numeric_limits<int>::min();
        int max_pag;
        fastscan(max_pag);
        --len;
        while (len--) {
            fastscan(curr);
            max = std::max(max, max_pag - curr);
            max_pag = std::max(max_pag, curr);
        }
        std::cout << max << '\n';
    }
    return 0;
}
