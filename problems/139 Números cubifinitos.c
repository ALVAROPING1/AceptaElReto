#include <stdbool.h>
#include <stdio.h>

inline int fastprint(char buffer[], int number) {
    register int i = -1;
    do {
        buffer[++i] = (number % 10);
        number /= 10;
    } while (number);
    return i + 1;
}

inline int read_line(char buf[], int* number) {
    *number = 0;
    int size = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    while (c >= '0') {
        buf[size] = c - '0';
        *number = *number * 10 + buf[size++];
        c = getchar_unlocked();
    }
    int i;
    for (i = 0; i < size / 2; ++i) {
        int tmp = buf[i];
        buf[i] = buf[size - i - 1];
        buf[size - i - 1] = tmp;
    }
    return size;
}

inline void print_buf(int size, char buf[size]) {
    while (size--)
        putchar_unlocked(buf[size] + '0');
    putchar_unlocked(' ');
    putchar_unlocked('-');
}

inline int next(int size, char buf[size], int* n) {
    int i;
    *n = 0;
    for (i = 0; i < size; ++i)
        *n += buf[i] * buf[i] * buf[i];
    return fastprint(buf, *n);
}

// Maximum possible value for the cube of the digits
#define MAX (9 * 9 * 9) * 7 + 1

#define ARROW_END()                                                            \
    putchar_unlocked('>');                                                     \
    putchar_unlocked(' ');

int main() {
    int n;
    char buf[16];
    int size = read_line(buf, &n);
    while (buf[size - 1] != 0) {
        bool seen[MAX] = {0};
        print_buf(size, buf);
        if (n == 1) {
            ARROW_END();
            goto end;
        }
        putchar_unlocked(' ');
        if (n < MAX) seen[n] = true;
        size = next(size, buf, &n);
        while (1) {
            print_buf(size, buf);
            if (n == 1 || seen[n]) {
                ARROW_END();
                if (seen[n]) {
                    putchar_unlocked('n');
                    putchar_unlocked('o');
                    putchar_unlocked(' ');
                }
                break;
            }
            putchar_unlocked(' ');
            seen[n] = true;
            size = next(size, buf, &n);
        }
    end:
        putchar_unlocked('c');
        putchar_unlocked('u');
        putchar_unlocked('b');
        putchar_unlocked('i');
        putchar_unlocked('f');
        putchar_unlocked('i');
        putchar_unlocked('n');
        putchar_unlocked('i');
        putchar_unlocked('t');
        putchar_unlocked('o');
        putchar_unlocked('.');
        putchar_unlocked('\n');
        size = read_line(buf, &n);
    }
    return 0;
}
