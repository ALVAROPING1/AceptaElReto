#include <bits/stdc++.h>

template <typename T> inline bool fastscan(T& number) {
    number = 0;
    register int c = getchar_unlocked();
    if (c == -1) return false;
    // Keep on extracting characters if they are integers
    for (; (c >= '0'); c = getchar_unlocked())
        number = number * 10 + c - '0';
    return true;
}

inline void fastprint(int number) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

// Max amount of books
const int MAX = 1000;

int main() {
    int n;
    int prices[MAX];
    while (fastscan(n)) {
        int i = n;
        while (i--)
            fastscan(prices[i]);
        std::sort(prices, &prices[n]);
        int result = 0;
        for (i = n - 3; i >= 0; i -= 3)
            result += prices[i];
        fastprint(result);
    }
    return 0;
}
