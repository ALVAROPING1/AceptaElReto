#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const int MAX_NAME_LEN = 11;

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan_word(char name[MAX_NAME_LEN]) {
    register int i = 0;
    register int c = getchar_unlocked();
    for (; (c >= 'a' && c <= 'z'); c = getchar_unlocked())
        name[i++] = c;
    name[i] = '\0';
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        char correct[MAX_NAME_LEN];
        fastscan_word(correct);
        int amount;
        fastscan(&amount);
        bool failed = amount == 1;
        char name[MAX_NAME_LEN];
        while (amount-- > 1) {
            fastscan_word(name);
            if (!failed && strcmp(correct, name) == 0) failed = true;
        }
        fastscan_word(name);
        if (failed || strcmp(correct, name) != 0) {
            putchar_unlocked('F');
            putchar_unlocked('A');
            putchar_unlocked('L');
            putchar_unlocked('S');
            putchar_unlocked('A');
        } else {
            putchar_unlocked('V');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('D');
            putchar_unlocked('A');
            putchar_unlocked('D');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('A');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
