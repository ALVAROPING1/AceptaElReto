#include <stdbool.h>
#include <stdio.h>

int fastscan(char buffer[]) {
    register int i = -1;
    // Keep on extracting characters if they are integers
    while ((buffer[++i] = getchar_unlocked() - '0') >= 0) {}
    return i;
}

const bool even_numbers[20] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                               1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

int main() {
    char line[16];
    int len = fastscan(line);
    while (line[0] != 0) {
        if (line[len - 1] == 0) {
            putchar_unlocked('N');
            putchar_unlocked('O');
            goto end;
        }
        int carry = 0;
        int i = len;
        while (i--) {
            int sum = line[i] + line[len - i - 1] + carry;
            carry = sum > 10;
            if (even_numbers[sum]) {
                putchar_unlocked('N');
                putchar_unlocked('O');
                goto end;
            }
        }
        putchar_unlocked('S');
        putchar_unlocked('I');
    end:
        putchar_unlocked('\n');
        len = fastscan(line);
    }
    return 0;
}
