#include <bits/stdc++.h>

inline bool fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    while(c < '0' || c > '9') c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastscan(int* number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar_unlocked();
    while(c != '-' && (c < '0' || c > '9')) c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    if (negative) *number *= -1;
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

int values[100000];
int n;

bool check(int lives, long long max_energy) {
    long long energy = max_energy;
    for (int i = 0; i < n; ++i) {
        int curr = values[i];
        energy = std::min(energy + curr, max_energy);
        if (energy <= 0) {
            --lives;
            if (lives == 0) return false;
            energy = max_energy + curr;
            if (energy <= 0) return false;
        }
    }
    return true;
}

long long binary_search(int lives, long long min, long long max) {
    long long l = min, r = max;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (check(lives, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

// TODO: use fastscan/fastprint IO. For some reason it gives RTE
int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int lives;
    std::cin >> lives;
    while (std::cin) {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
            std::cin >> (values[i]);
        std::cout << (binary_search(lives, 0, 1200000000000)) << '\n';
        std::cin >> lives;
    }
    return 0;
}
