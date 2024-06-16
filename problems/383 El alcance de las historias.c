#include <stdio.h>

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

void fastprint(int number) {
    if (number < 0) {
        putchar_unlocked('-');
        number *= -1;
    }
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

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int len, curr;
        fastscan(&len);
        int max_val = -(1 << 30);
        int max_pag;
        fastscan(&max_pag);
        --len;
        while (len--) {
            fastscan(&curr);
            max_val = max(max_val, max_pag - curr);
            max_pag = max(max_pag, curr);
        }
        fastprint(max_val);
    }
    return 0;
}
