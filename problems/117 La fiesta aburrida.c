#include <stdio.h>

// Read positive number
inline void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() {
    int n;
    fastscan_positive(&n);
    while (n--) {
        register int c;
        getchar_unlocked();
        getchar_unlocked();
        getchar_unlocked();
        getchar_unlocked();
        putchar_unlocked('H');
        putchar_unlocked('o');
        putchar_unlocked('l');
        putchar_unlocked('a');
        putchar_unlocked(',');
        putchar_unlocked(' ');
        while ((c = getchar_unlocked()) != '\n') {
            putchar_unlocked(c);
        }
        putchar_unlocked('.');
        putchar_unlocked('\n');
    }
    return 0;
}
