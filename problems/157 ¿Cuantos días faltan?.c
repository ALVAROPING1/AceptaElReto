#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
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

// Python:
// days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
// res = [0] * 13
// remaining = 0
// for i in range(len(days) - 1, -1, -1):
//     res[i] = remaining
//     remaining += days[i]
// print(f"int remaining[] = {{{', '.join(map(str, res))}}};")

int remaining[] = {365, 334, 306, 275, 245, 214, 184, 153, 122, 92, 61, 31, 0};

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int d, m;
        fastscan(&d);
        fastscan(&m);
        fastprint(remaining[m-1] - d);
    }
    return 0;
}
