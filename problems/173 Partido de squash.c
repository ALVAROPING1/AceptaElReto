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
}

#define NOT(x) (x) == 'A' ? 'B' : 'A'

inline void print_result(int points[], int not_first) {
    if (not_first) putchar_unlocked(' ');
    fastprint(points['A']);
    putchar_unlocked('-');
    fastprint(points['B']);
    points['A'] = 0;
    points['B'] = 0;
}

int main() {
    int c;
    int points['B' + 1];
    while ((c = getchar_unlocked()) != 'F') {
        points['A'] = 0;
        points['B'] = 0;
        int prev_winner = 'A';
        int not_first = 0;
        int printed;
        do {
            printed = 1;
            if (c == prev_winner) {
                ++points[c];
                if (points[c] - points[NOT(c)] >= 2 && points[c] >= 9) {
                    print_result(points, not_first);
                    not_first = 1;
                    printed = 0;
                }
            } else prev_winner = c;
        } while ((c = getchar_unlocked()) != 'F');
        if (printed) print_result(points, not_first);
        getchar_unlocked();
        putchar_unlocked('\n');
    }
    return 0;
}
