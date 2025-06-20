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
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

// To solve the problem, we try to insert numbers as much to the right as
// possible, and only consider adding nodes to the left if the right subtree
// can't have all nodes with the given max height. This guarantees the internal
// nodes closest to the root (which are inserted first) are as small as possible
// as requested

void solve(int m, int M, int h, int last) {
    // Base cases
    // Tree is empty
    if (M < m) return;
    // Tree has a single node => insert it
    if (m == M) {
        fastprint(m);
        // Only add a space if it's not the last. The last number printed will
        // always be the biggest
        if (m != last) putchar_unlocked(' ');
        return;
    }
    // Recursive case
    // Max amount of nodes in the subtrees
    int max_subtree = (1 << (h - 1)) - 1;
    // Assign as many nodes to the right subtree as possible to guarantee the
    // root of this subtree is as small as possible
    int mid = max(M - max_subtree, m);
    // Print the root of this tree
    fastprint(mid);
    putchar_unlocked(' ');
    // Solve the child subtrees recursively. Start with the left subtree to
    // insert smaller numbers first
    solve(m, mid - 1, h - 1, last);
    solve(mid + 1, M, h - 1, last);
}

int main() {
    int n;
    fastscan(&n);
    while (n--) {
        int k, h;
        fastscan(&k);
        fastscan(&h);
        // Problem is only impossible if a complete tree with the given height
        // can't have the requested amount of nodes. The amount of nodes in a
        // complete tree of height h is 2^h-1
        if ((1 << h) - 1 < k) {
            putchar_unlocked('I');
            putchar_unlocked('M');
            putchar_unlocked('P');
            putchar_unlocked('O');
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked('B');
            putchar_unlocked('L');
            putchar_unlocked('E');
        } else {
            // If the problem has a solution, solve it recursively
            solve(1, k, h, k);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
