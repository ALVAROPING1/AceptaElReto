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

    int t;
    fastscan(t);
    while (t--) {
        long long N, D, I;
        int T, M;
        fastscan(N);
        fastscan(T);
        fastscan(M);
        fastscan(D);
        fastscan(I);
        int series = (N + M - 1) / M - 1;
        std::cout << N * T + series * D + I * (series - 1) * series / 2 << "\n";
    }
    return 0;
}
