#include <stdbool.h>
#include <stdio.h>
#include <string.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
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

// Max amount of tiles in the board
#define MAX_TILES 100 * 100
// Max size of the ring buffer queue
#define Q_SIZE 1024

#define INC(x) x = (x + 1) % Q_SIZE
#define PUSH(distance, position)                                               \
    do {                                                                       \
        Q[q_head].d = distance + 1;                                            \
        Q[q_head].pos = position;                                              \
        INC(q_head);                                                           \
    } while (0)

typedef struct {
    int d;
    int pos;
} Node;

Node Q[Q_SIZE];

int dijkstra(int tiles, int K, int shortcuts[MAX_TILES + 1]) {
    bool visited[MAX_TILES + 1] = {0};
    unsigned int q_head = 1;
    unsigned int q_tail = 0;
    Q[0].d = 0;
    Q[0].pos = 1;
    int i;
    while (1) {
        int d = Q[q_tail].d;
        int pos = Q[q_tail].pos;
        INC(q_tail);
        if (tiles - pos <= K) return d + 1;
        if (!visited[pos]) {
            visited[pos] = true;
            int max = 0;
            // Add neighbors with a shortcut
            for (i = 1; i <= K; ++i) {
                int next = pos + i;
                if (next <= tiles) {
                    if (shortcuts[next] != 0) PUSH(d, shortcuts[next]);
                    else max = next;
                }
            }
            // Add the last neighbor without a shortcut. Without taking a
            // shortcut, moving less than the maximum possible is never optimal
            if (max != 0) PUSH(d, max);
        }
    }
}

int main() {
    int N, K, S, E;
    fastscan(&N);
    fastscan(&K);
    fastscan(&S);
    fastscan(&E);
    int shortcuts[MAX_TILES + 1];
    while (N != 0 || K != 0 || S != 0 || E != 0) {
        int tiles = N * N;
        memset(shortcuts, 0, sizeof(shortcuts));
        int s = S + E;
        while (s--) {
            int s, e;
            fastscan(&s);
            fastscan(&e);
            shortcuts[s] = e;
        }
        fastprint(dijkstra(tiles, K, shortcuts));
        fastscan(&N);
        fastscan(&K);
        fastscan(&S);
        fastscan(&E);
    }
    return 0;
}
