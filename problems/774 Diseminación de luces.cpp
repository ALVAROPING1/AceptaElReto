#include <bits/stdc++.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
    char buffer[32];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        std::unordered_map<int, int> colors;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            fastscan(&x);
            auto prev = colors.find(x);
            if (prev != colors.end()) {
                res += i - prev->second;
            }
            colors[x] = i;
        }
        fastprint(res);
        fastscan(&n);
    }
    return 0;
}
