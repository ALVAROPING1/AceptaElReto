#include <stdio.h>

// Max line size (+1 for the null terminator byte)
const size_t MAX = 10001;

char open_table[128] = {0};
char close_table[128] = {0};

int main() {
    char stack[MAX];
    // Precompute tables
    // Generate array with conversions from character (open delimiter) to
    // corresponding closing delimiter
    open_table['('] = ')';
    open_table['['] = ']';
    open_table['{'] = '}';
    // Generate array with conversions from character to whether it's a closing
    // delimiter
    close_table[')'] = 1;
    close_table[']'] = 1;
    close_table['}'] = 1;

    // Read first line
    int c;
    while ((c = getchar_unlocked()) != EOF) { // While there are lines to read
        int n = 0;
        // Iterate through the line
        do {
            // If the character is an opening delimiter, push to the stack
            char val = open_table[c];
            if (val != '\0') stack[n++] = val;
            // If the character is a closing delimiter and it doesn't match the
            // expected one, end the iteration with an error
            if (close_table[c] && stack[--n] != c) {
                while (getchar_unlocked() != '\n') {}
                putchar_unlocked('N');
                putchar_unlocked('O');
                goto end;
            }
        } while((c = getchar_unlocked()) != '\n');
        if (n == 0) {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
    end:
        putchar_unlocked('\n');
    }
    return 0;
}
