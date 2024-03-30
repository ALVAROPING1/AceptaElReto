#include <bits/stdc++.h>

template <typename T> void fastscan(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    // extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        number = number * 10 + c - '0';

    if (negative) number *= -1;
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    fastscan(n);
    while (n != 0) {
        int total = 0;
        int curr;
        while (n--) {
            fastscan(curr);
            total += curr;
        }
        std::cout << total << '\n';
        fastscan(n);
    }
    return 0;
}
