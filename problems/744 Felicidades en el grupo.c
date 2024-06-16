#include <stdio.h>
#include <stdbool.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    // Keep on extracting characters if they are integers
    for (; c >= '0' ; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
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
    int max;
    while (fastscan(&max)) {
        int last_reply = 0, curr, replies = 0;
        fastscan(&curr);
        while (curr != 0) {
            if (curr > last_reply) {
                ++replies;
                last_reply = curr + max;
            }
            fastscan(&curr);
        }
        fastprint(replies);
    }
    return 0;
}
