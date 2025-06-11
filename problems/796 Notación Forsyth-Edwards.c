#include <stdbool.h>
#include <stdio.h>
// clang-format off
typedef struct { int x, y; } Point;
const Point dir4[] = { { 1,  0}, { 0,  1}, {-1,  0}, { 0, -1} };
const Point dir4diagonal[] = { { 1,  1}, { -1,  1}, {-1,  -1}, { 1, -1} };
const Point dir8[] = { { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, {-1,  0}, {-1, -1}, { 0, -1}, { 1, -1} };
const Point knight[] = { { 2, 1 }, { 2, -1 }, { -2, 1 }, { -2, -1 }, { 1, 2 }, { 1, -2 }, { -1, 2 }, { -1, -2 } };
// clang-format on

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

#define POS_INVALID(row, col) row < 0 || row >= 8 || col < 0 || col >= 8

#define CHECK_DIR(dirs)                                                        \
    for (i = 0; i < sizeof(dirs) / sizeof(dirs[0]); ++i) {                     \
        Point off = dirs[i];                                                   \
        int row2 = row;                                                        \
        int col2 = col;                                                        \
        while (true) {                                                         \
            row2 += off.y;                                                     \
            col2 += off.x;                                                     \
            if (POS_INVALID(row2, col2) || board[row2][col2] > 1) break;       \
            board[row2][col2] = 1;                                             \
        }                                                                      \
    }

#define CHECK_POS(dirs)                                                        \
    for (i = 0; i < sizeof(dirs) / sizeof(dirs[0]); ++i) {                     \
        Point off = dirs[i];                                                   \
        int row2 = row + off.y;                                                \
        int col2 = col + off.x;                                                \
        if (POS_INVALID(row2, col2) || board[row2][col2] != 0) continue;       \
        board[row2][col2] = 1;                                                 \
    }

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        char board[8][8] = {0};
        int row = 0, col = 0;
        char c;
        // Parse input
        while ((c = getchar_unlocked()) != '\n') {
            if (c == '/') {
                ++row;
                col = 0;
            } else if (c >= '0' && c <= '9') col += c - '0';
            else {
                board[row][col] = c;
                ++col;
            }
        }
        int i;
        // Process attacked tiles
        for (row = 0; row < 8; ++row) {
            for (col = 0; col < 8; ++col) {
                char piece = board[row][col];
                switch (piece) {
                case 0:
                case 1:
                    break;
                case 'p':
                case 'P': {
                    int dir = piece == 'p' ? 1 : -1;
                    int row2 = row + dir;
                    if (row2 < 0 || row2 >= 8) break;
                    if (col > 0 && board[row2][col - 1] == 0)
                        board[row2][col - 1] = 1;
                    if (col < 7 && board[row2][col + 1] == 0)
                        board[row2][col + 1] = 1;
                } break;
                case 'r':
                case 'R':
                    CHECK_DIR(dir4);
                    break;
                case 'b':
                case 'B':
                    CHECK_DIR(dir4diagonal);
                    break;
                case 'q':
                case 'Q':
                    CHECK_DIR(dir8);
                    break;
                case 'n':
                case 'N':
                    CHECK_POS(knight);
                    break;
                case 'k':
                case 'K':
                    CHECK_POS(dir8);
                    break;
                }
            }
        }
        // Count empty spaces
        int empty = 0;
        for (i = 0; i < sizeof(board) / sizeof(board[0][0]); ++i)
            if (((char*) board)[i] == 0) ++empty;
        fastprint(empty);
    }
    return 0;
}
