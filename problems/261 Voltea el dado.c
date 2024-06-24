#include <stdbool.h>
#include <stdio.h>

// Max value
#define MAX 1000

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

int allowed[7][4] = {
    {0, 0, 0, 0}, // Unused
    {2, 3, 4, 5},
    {1, 3, 4, 6},
    {1, 2, 5, 6},
    {1, 2, 5, 6},
    {1, 3, 4, 6},
    {2, 3, 4, 5},
};

// Dynamic programming table
// wins[n][k] = whether the player wins if the current total is n and
// the previous number was k
bool loses[MAX + 6][7] = {{false}};

#define LOSES(k) loses[i + allowed[j][k]][allowed[j][k]]

int main() {
    // Precompute values
    int i, j;
    // Base cases: none, because they are already correctly initialized to false
    // Recursive cases
    for (i = MAX - 1; i > 0; --i)
        for (j = 6; j > 0; --j)
            loses[i][j] = !(LOSES(0) || LOSES(1) || LOSES(2) || LOSES(3));

    int n;
    fastscan(&n);
    while (n--) { // While there are lines to read
        int curr, prev;
        fastscan(&curr);
        fastscan(&prev);
        if (loses[curr][prev]) {
            putchar_unlocked('P');
            putchar_unlocked('I');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('D');
            putchar_unlocked('E');
        } else {
            putchar_unlocked('G');
            putchar_unlocked('A');
            putchar_unlocked('N');
            putchar_unlocked('A');
        }
        putchar_unlocked('\n');
    }
}
