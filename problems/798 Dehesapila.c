#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int main() { // Caso marca final
    int n;
    fastscan(&n);
    int stack[100];
    while (n != 0) {
        int prev_max = 0, size = -1;
        int i, current;
        while (n--) { // For each cart
            fastscan(&current);
            if (current > prev_max) {
                // If the current cart is greater than the previous max, all
                // carts between those must have been pushed into the stack
                // to extract the current cart
                for (i = prev_max + 1; i < current; ++i)
                    stack[++size] = i;
                prev_max = current;
            } else { // current < prev_max
                // If the current cart is smaller than the max, it must have
                // been popped from the stack. If it's not at the top of the
                // stack, the target state is impossible
                if (current != stack[size]) {
                    while (getchar_unlocked() != '\n') {}
                    putchar_unlocked('N');
                    putchar_unlocked('O');
                    goto end;
                } else
                    --size;
            }
        }
        putchar_unlocked('S');
        putchar_unlocked('I');
    end:
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
