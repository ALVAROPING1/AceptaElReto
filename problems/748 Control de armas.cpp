#include <bits/stdc++.h>

template <typename T> inline void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

inline void fastscan_name(std::string& buf) {
    for (register int c = getchar_unlocked(); c > ' '; c = getchar_unlocked())
        buf.push_back(c);
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

int main() {
    std::unordered_map<std::string, int> map{};
    std::string name;
    name.reserve(10);
    int n;
    fastscan(n);
    while (n != 0) {
        while (n--) {
            register int c = getchar_unlocked();
            if (c != '?') {
                name.push_back(c);
                fastscan_name(name);
                int amount = getchar_unlocked() - '0';
                getchar_unlocked(); // Skip the newline character
                map[name] += amount;
                name.clear();
            } else {
                getchar_unlocked(); // Skip space character
                int k, total = 0;
                fastscan(k);
                while (k--) {
                    fastscan_name(name);
                    auto item = &map[name];
                    total += *item;
                    *item = 0;
                    name.clear();
                }
                fastprint(total);
            }
        }
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('\n');
        fastscan(n);
        map.clear();
    }
    return 0;
}
