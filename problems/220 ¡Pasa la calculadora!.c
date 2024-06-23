#include <stdbool.h>
#include <stdio.h>

// Max value in the calculator
#define MAX 31
// Maximum number that can be last pressed
#define MAX_PREV 9

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

#ifdef CALCULATE

int allowed[10][4] = {
    {0, 0, 0, 0}, // Unused
    {2, 3, 4, 7},
    {1, 3, 5, 8},
    {1, 2, 6, 9},
    {1, 5, 6, 7},
    {2, 4, 6, 8},
    {3, 4, 5, 9},
    {1, 4, 8, 9},
    {2, 5, 7, 9},
    {3, 6, 7, 8},
};

// Dynamic programming table
// loses[n][k] = whether the player loses if the calculator has n and
// previous number was k
bool loses[MAX + MAX_PREV][10] = {{false}};

#define LOSES(k) loses[i + allowed[j][k]][allowed[j][k]]

#else

// Precalculated result for each input
bool loses[MAX + 1][MAX_PREV + 1] = {
    // clang-format off
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1},
    {0,1,1,1,1,1,1,1,1,1},
    {0,0,1,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,1,1},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,1},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,1,1},
    {0,0,1,0,1,0,1,1,0,1},
    {0,0,0,0,0,0,0,0,0,1},
    {0,1,1,0,1,1,0,0,0,1},
    {0,0,1,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0,1,0,1},
    {0,0,1,1,1,0,0,0,1,1},
    {0,0,0,1,1,1,0,1,1,0},
    {0,0,0,0,0,0,1,0,0,1},
    {0,1,0,0,0,1,1,0,1,1},
    {0,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    // clang-format on
};

#endif

int main() {
#ifdef CALCULATE
    // Precompute values
    int i, j;
    // Base cases: none, because they are already correctly initialized to false
    // Recursive cases
    for (i = MAX - 1; i > 0; --i)
        for (j = MAX_PREV; j > 0; --j)
            loses[i][j] = !(LOSES(0) || LOSES(1) || LOSES(2) || LOSES(3));

    for (i = 0; i < MAX + 1; ++i) {
        printf("{");
        for (j = 0; j <= MAX_PREV; ++j)
            printf("%d,", loses[i][j]);
        printf("},\n");
    }
#endif
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
