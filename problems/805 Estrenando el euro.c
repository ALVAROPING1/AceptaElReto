#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
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
    int n;
    fastscan(&n);
    while (n != 0) {
        int curr, next, count = 1;
        fastscan(&curr);
        --n;
        int total = curr;
        while (n--) {
            fastscan(&next);
            // If the sum of all previous taken coins is smaller than the next coint,
            // we can extend the taken coins with the next coin. Otherwise the
            // currently taken coins is an invalid change as we would get the
            // next coin instead of the chosen coins, so replace the previous
            // biggest coin with the next coin
            if (total < next) {
                total += next;
                ++count;
            } else {
                total += next - curr;
            }
            curr = next;
        }
        fastprint(count);
        fastscan(&n);
    }
    return 0;
}
