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

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int rows, cols;
    fastscan(&rows);
    fastscan(&cols);
    char row[201];
    while (rows != 0 && cols != 0) {
        int n = cols * 2 + 1; // Size of a row in characters
        int on_initial = 0, on_final = 0;
        int error = 0, on = 0, off = 0; // Wrong phones for each initial type
        int col, i;
        while (rows--) { // For each row
            // Read the row
            for (i = 0; i < n; ++i)
                row[i] = getchar_unlocked();
            getchar_unlocked();                // Ignore line jump
            for (col = 0; col < cols; ++col) { // Go through the row
                int col_goal = col + cols + 1;
                // Count whether the current phone is wrong
                switch (row[col]) {
                case '0':
                    off += (row[col_goal] != '0');
                    break;
                case '1':
                    on += (row[col_goal] != '1');
                    ++on_initial;
                    break;
                case 'R':
                    ++error;
                    break;
                }
                // Count the amount of on phones in the initial and target state
                on_initial += row[col] != '0';
                on_final += row[col_goal] == '1';
            }
        }
        // If there are more on phones in the target than there could be in the
        // initial state (considering on + error phones), the target is
        // impossible
        if (on_final > on_initial) {
            putchar_unlocked('I');
            putchar_unlocked('M');
            putchar_unlocked('P');
            putchar_unlocked('O');
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked('B');
            putchar_unlocked('L');
            putchar_unlocked('E');
            putchar_unlocked('\n');
        } else {
            // Swap pairs of wrong on and off phones
            // If there were more wrong on phones (all wrong off have been
            // fixed), turn off remaining wrong on, and set the error phones to
            // the correct state
            if (on >= off) fastprint(on + error);
            // If there were more wrong off phones, swap the remaining wrong off
            // with error phones and set the error phones to the correct
            // state
            else fastprint(on + min(off - on, error) + error);
        }
        fastscan(&rows);
        fastscan(&cols);
    }
    return 0;
}
