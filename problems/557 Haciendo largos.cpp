#include <bits/stdc++.h>

template <typename T> void fastscan(T& number) {
    // variable to indicate sign of input number
    bool negative = false;
    register int c;
    number = 0;
    // extract current character from buffer
    c = getchar();
    if (c == '-') {
        negative = true;
        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar())
        number = number * 10 + c - '0';

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative) number *= -1;
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
