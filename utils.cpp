#include <bits/stdc++.h>

// Read positive number
template <typename T> void fastscan_positive(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

// Read positive/negative number
template <typename T> void fastscan(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
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
    // Replace stdin for debugging
    freopen("in.txt", "r", stdin);
}
