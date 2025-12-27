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

#define READ_VALUE(v)                                                          \
    v = (getchar_unlocked() - '0') * 10 + getchar_unlocked() - '0';            \
    getchar_unlocked()

#define READ_TIME()                                                            \
    READ_VALUE(h);                                                             \
    READ_VALUE(m);

int main() {
    int h, m;
    READ_TIME();
    while (h != 0 || m != 0) {
        fastprint((24 - (h + 1)) * 60 + 60 - m);
        READ_TIME();
    }
    return 0;
}
