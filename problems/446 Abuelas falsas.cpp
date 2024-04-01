#include <bits/stdc++.h>
#include <cstring>

const int MAX_NAME_LEN = 11;

template <typename T> void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

void fastscan_word(char name[MAX_NAME_LEN]) {
    register int i = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= 'a' && c <= 'z');
         c = getchar_unlocked())
        name[i++] = c;
    name[i] = '\0';
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    fastscan(n);
    while (n--) {
        char correct[MAX_NAME_LEN];
        fastscan_word(correct);
        int amount;
        fastscan(amount);
        bool failed = amount == 1;
        char name[MAX_NAME_LEN];
        while (amount-- > 1) {
            fastscan_word(name);
            if (not failed and strcmp(correct, name) == 0) failed = true;
        }
        fastscan_word(name);
        if (failed or strcmp(correct, name) != 0) {
            std::cout << "FALSA\n";
        } else {
            std::cout << "VERDADERA\n";
        }
    }
    return 0;
}
