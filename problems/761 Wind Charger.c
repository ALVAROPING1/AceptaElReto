#include <stdbool.h>
#include <stdio.h>

bool fastscan_check(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == -1) return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

void fastscan_neg(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    bool negative = false;
    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    if (negative) *number *= -1;
}

void fastprint(int number) {
    char buffer[16];
    register int i = -1;
    if (number < 0) {
        putchar_unlocked('-');
        number *= -1;
    }
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
}

// Maximum map side length
const int MAX = 30;
const int INF = 1000000000;

typedef struct {
    int start, end, cost;
} edge;

#define PUSH(X, Y)                                                             \
    {                                                                          \
        edges[e].start = start;                                                \
        edges[e].end = (Y) * W + X;                                            \
        edges[e].cost = 1;                                                     \
        ++e;                                                                   \
    }

int main() {
    char map[MAX][MAX];
    edge edges[MAX * MAX * 4];
    int d[MAX * MAX];

    int W, H, x, y, i;
    while (fastscan_check(&W)) {
        fastscan(&H);
        // Read map
        for (y = 0; y < H; ++y) {
            for (x = 0; x < W; ++x)
                map[y][x] = getchar_unlocked();
            getchar_unlocked();
        }
        int e = 0; // Total amount of edges
        int n = 0; // Total amount of valid nodes
        // Get all the graph edges
        for (y = 0; y < H; ++y)
            for (x = 0; x < W; ++x) {
                // Skip positions with black holes as we can't stand in them.
                // Also skip target point as we can't leave it once we reach it
                if (map[y][x] == '#' || (y == H - 1 && x == W - 1)) continue;
                ++n;
                int start = y * W + x; // ID of the current position node
                if (map[y][x] == 'O') {
                    int wx, wy;
                    fastscan(&wx);
                    fastscan(&wy);
                    edges[e].start = start;
                    edges[e].end = (wy - 1) * W + (wx - 1);
                    fastscan_neg(&edges[e].cost);
                    ++e;
                    continue;
                }
                if (y > 0 && map[y - 1][x] != '#') PUSH(x, y - 1);
                if (x > 0 && map[y][x - 1] != '#') PUSH(x - 1, y);
                if (y < H - 1 && map[y + 1][x] != '#') PUSH(x, y + 1);
                if (x < W - 1 && map[y][x + 1] != '#') PUSH(x + 1, y);
            }
        // Use bellman-ford to calculate shortest path
        // Reset distance vector
        for (i = 0; i < W * H; ++i)
            d[i] = INF;
        d[0] = 0; // The distance to the starting point is 0
        // Repeat once for each vertex
        for (i = 0; i < n; ++i) {
            bool converged = true;
            edge* curr;
            // Iterate through all edges
            for (curr = &edges[0]; curr < &edges[e]; ++curr)
                // If the start of the edge can be reached
                if (d[curr->start] < INF) {
                    // If this edge improves the distance to the end node,
                    // update it
                    int cost = d[curr->start] + curr->cost;
                    if (d[curr->end] > cost) {
                        d[curr->end] = cost;
                        converged = false;
                    }
                }
            // If no distance changed in the current iteration, the solution has
            // converged and we don't need to do more iterations
            if (converged) {
                // Calculate the ID of the target node
                int target = (H - 1) * W + (W - 1);
                // If the distance to the target node is infinite, there is no
                // path to it
                if (d[target] == INF) {
                    putchar_unlocked('I');
                    putchar_unlocked('M');
                    putchar_unlocked('P');
                    putchar_unlocked('O');
                    putchar_unlocked('S');
                    putchar_unlocked('I');
                    putchar_unlocked('B');
                    putchar_unlocked('L');
                    putchar_unlocked('E');
                } else fastprint(d[target]); // Otherwise, print its cost
                goto end;
            }
        }
        // If we didn't converge to a solution, we found a negative cycle
        putchar_unlocked('E');
        putchar_unlocked('X');
        putchar_unlocked('P');
        putchar_unlocked('L');
        putchar_unlocked('O');
        putchar_unlocked('S');
        putchar_unlocked('I');
        putchar_unlocked('O');
        putchar_unlocked('N');
    end:
        putchar_unlocked('\n');
    }
    return 0;
}
