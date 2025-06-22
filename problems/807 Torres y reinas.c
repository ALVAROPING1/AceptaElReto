#include <stdbool.h>
#include <stdio.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
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
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

// This is very slow, but good enough for AC
int solve(int row,
                int n,
                int q,
                int r,
                bool cols[8],
                char right_diag[16],
                char left_diag[16],
                int score[8][8]) {
    if (row == n) return 0;

    int res = -1, i;
    for (i = 0; i < n; i++) {
        // Check if the queen can be placed
        if (cols[i] || right_diag[row + i] == 2 ||
            left_diag[row - i + n - 1] == 2)
            continue;
        char prev_right = right_diag[row + i];
        char prev_left = left_diag[row - i + n - 1];

        cols[i] = 1;
        if (right_diag[row + i] == 0 && left_diag[row - i + n - 1] == 0) {
            right_diag[row + i] = 2;
            left_diag[row - i + n - 1] = 2;
            if (q > 0) {
                int score1 = solve(
                    row + 1, n, q - 1, r, cols, right_diag, left_diag, score);
                if (score1 != -1) res = max(res, score1 + score[row][i]);
            }
        }

        right_diag[row + i] = 1;
        left_diag[row - i + n - 1] = 1;
        if (r > 0) {
            int score2 = solve(
                row + 1, n, q, r - 1, cols, right_diag, left_diag, score);
            if (score2 != -1) res = max(res, score2 + score[row][i]);
        }
        cols[i] = 0;
        right_diag[row + i] = prev_right;
        left_diag[row - i + n - 1] = prev_left;
    }
    return res;
}

int main() {
    int q, r;
    int score[8][8];
    while (fastscan(&q)) {
        fastscan(&r);
        bool cols[8] = {0};
        char right_diag[16] = {0};
        char left_diag[16] = {0};
        int n = q + r;
        int i, j;
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                fastscan(&score[i][j]);
        int res =
            solve(0, q + r, q, r, cols, right_diag, left_diag, score);
        if (res == -1) putchar_unlocked('0');
        else fastprint(res);
        putchar_unlocked('\n');
    }
    return 0;
}
