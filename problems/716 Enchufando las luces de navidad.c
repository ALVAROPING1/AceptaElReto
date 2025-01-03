#include <stdio.h>

// Read positive number
void fastscan_positive(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

void fastprint(int number) {
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
    int n;
    fastscan_positive(&n);
    while (n != 0) {
        int total = 1;
        int current;
        while (n--) {
            fastscan_positive(&current);
            total += current - 1;
        }
        fastprint(total);
        fastscan_positive(&n);
    }
    return 0;
}
