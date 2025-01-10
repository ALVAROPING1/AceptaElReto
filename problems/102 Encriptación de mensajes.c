#include <stdio.h>

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

#define IDX(c) c - 'a'
#define DECRYPT(c, l)                                                          \
    c = (c - l + diff) % MOD + l;                                              \
    result += vocal[c];                                                        \
    line[i++] = c;

const int MAX = 64;
const int MOD = 'Z' - 'A' + 1;
int vocal[128] = {
    ['a'] = 1,
    ['e'] = 1,
    ['i'] = 1,
    ['o'] = 1,
    ['u'] = 1,
    ['A'] = 1,
    ['E'] = 1,
    ['I'] = 1,
    ['O'] = 1,
    ['U'] = 1,
};

int main() {
    char line[MAX];
    while (1) {
        int result = 0;
        int i = 0;
        register int c = getchar_unlocked();
        int diff = 'p' - c;
        if (diff < 0) diff = MOD + diff;
        c = getchar_unlocked();
        while (c != '\n' && c != EOF) {
            if (c >= 'A' && c <= 'Z') {
                DECRYPT(c, 'A');
            } else if (c >= 'a' && c <= 'z') {
                DECRYPT(c, 'a');
            } else line[i++] = c;
            c = getchar_unlocked();
        }
        if (i == 3 && line[0] == 'F' && line[1] == 'I' && line[2] == 'N')
            return 0;
        fastprint(result);
    }
    return 0;
}
