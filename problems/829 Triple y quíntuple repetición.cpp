#include <bits/stdc++.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

struct string_view {
    size_t len;
    const char* data;

    constexpr string_view(const char* data, size_t len) noexcept
        : len{len}, data{data} {}

    constexpr bool operator==(string_view x) const noexcept {
        return this->len == x.len &&
               std::char_traits<char>::compare(this->data, x.data, x.len) == 0;
    }
};

namespace std {
template <> struct hash<string_view> : public __hash_base<size_t, string_view> {
    size_t operator()(const string_view& str) const noexcept {
        return _Hash_impl::hash(str.data, str.len);
    }
};

template <> struct __is_fast_hash<hash<string_view>> : false_type {};
} // namespace std

int main() {
    int n;
    fastscan(&n);
    std::unordered_map<string_view, int> states[2];
    states[0].reserve(100);
    states[1].reserve(100);
    char str_arena[100][50];
    while (n != 0) {
        bool player = 0;
        while (n--) {
            // Read current line
            int i = 0;
            char c;
            while ((c = getchar_unlocked()) != '\n')
                str_arena[n][i++] = c;
            string_view line{str_arena[n], static_cast<size_t>(i)};

            // Add it to the seen states for the current player. If we already
            // saw this state 4 times before (this would be the 5th), we can
            // stop
            auto prev = states[player].find(line);
            if (prev == states[player].end()) states[player][line] = 0;
            else if (prev->second == 4) {
                putchar_unlocked('S');
                putchar_unlocked('I');
                // Ignore remaining lines
                while (n--)
                    while (getchar_unlocked() != '\n') {}
                goto end;
            }
            states[player][line]++;
            player = !player;
        }
        putchar_unlocked('N');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
        states[0].clear();
        states[1].clear();
        fastscan(&n);
    }
    return 0;
}
