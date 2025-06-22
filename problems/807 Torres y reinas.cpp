#include <bits/stdc++.h>

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
    putchar_unlocked('\n');
}

struct Point {
    char x, y;
    int score;
};

enum Type { E, R, Q };

#define MAX 8

bool cols[MAX] = {};           // Columns filled
bool rows[MAX] = {};           // Rows filled
Type right_diag[MAX * 2] = {}; // Up-right diagonals filled
Type left_diag[MAX * 2] = {};  // Up-left diagonals filled

Point scores[MAX * MAX] = {}; // Array of sorted tiles
int size;                     // Amount of tiles
int n;                        // Amount of pieces to place
int max_score;                // Max score found

void solve(int idx, int q, int r, int score) {
    // Base case: we have no more pieces to place
    if (q == 0 && r == 0) {
        // Update max score found
        if (score > max_score) max_score = score;
        return;
    }

    // Calculate max possible score from this point as current score + next
    // (q+r) biggest scores
    int max = score;
    for (int i = idx, rem = q + r; idx < size && rem > 0; ++i, --rem)
        max += scores[i].score;

    // For each remaining tile
    for (; idx < size; ++idx) {
        // Prune search tree by max possible score
        if (max <= max_score) return;

        Point* point = &scores[idx];
        int x = point->x, y = point->y;
        // Calculate diagonal IDs. This takes advantage of the fact that (y+x)
        // and (y-x) are constant for tiles in the same right/left diagonal
        int rd = y + x;         // Right diagonal ID
        int ld = y - x + n - 1; // Left diagonal ID

        // If the current tile isn't being attacked, try to place a piece
        if (!cols[x] && !rows[y] && right_diag[rd] != Q && left_diag[ld] != Q) {
            // Store pieces in the current diagonals. Can be either empty or a
            // rook
            Type prev_right = right_diag[rd];
            Type prev_left = left_diag[ld];
            // Mark the current row/column as attacked
            cols[x] = true;
            rows[y] = true;
            // Try to place a queen if there are remaining queens and the
            // diagonals are empty (if there was a rook, the queen would attack
            // it and invalidate the state)
            if (q > 0 && right_diag[rd] == E && left_diag[ld] == E) {
                // Mark the diagonals as having a queen
                right_diag[rd] = Q;
                left_diag[ld] = Q;
                solve(idx + 1, q - 1, r, score + point->score);
            }
            // Try to place a rook if there are remaining rooks. Doesn't
            // matter if there is a rook already in the diagonal as there can be
            // multiple rooks in the same diagonal
            if (r > 0) {
                // Mark the diagonals as having a rook
                right_diag[rd] = R;
                left_diag[ld] = R;
                solve(idx + 1, q, r - 1, score + point->score);
            }
            // Restore the state
            cols[x] = false;
            rows[y] = false;
            right_diag[rd] = prev_right;
            left_diag[ld] = prev_left;
        }
        // Update the max possible score assuming we leave this tile empty
        max += scores[idx + q + r].score - scores[idx].score;
    }
}

int main() {
    int q, r;
    while (fastscan(&q)) {
        fastscan(&r);
        max_score = 0;
        n = q + r;
        size = 0;
        // Read board scores
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                scores[size].y = i;
                scores[size].x = j;
                fastscan(&scores[size].score);
                ++size;
            }
        // Sort tiles in descending order by their score to prioritize higher
        // value tiles first
        std::sort(&scores[0], &scores[size], [](Point p1, Point p2) {
            return p1.score > p2.score;
        });
        // Solve the problem recursively
        solve(0, q, r, 0);
        fastprint(max_score);
        // Reset board state
        memset(cols, 0, sizeof(cols));
        memset(rows, 0, sizeof(rows));
        memset(right_diag, 0, sizeof(right_diag));
        memset(left_diag, 0, sizeof(left_diag));
    }
    return 0;
}
