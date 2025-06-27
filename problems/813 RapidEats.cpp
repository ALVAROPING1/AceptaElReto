#include <bits/stdc++.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
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

#define VERTICES 20000

struct Edge {
    int node, cost;
};

template <class T, class S, class C>
void clearpq(std::priority_queue<T, S, C>& q) {
    struct HackedQueue : private std::priority_queue<T, S, C> {
        static S& Container(std::priority_queue<T, S, C>& q) {
            return q.*&HackedQueue::c;
        }
    };
    HackedQueue::Container(q).clear();
}

std::priority_queue<std::pair<int, int>> Q;

int dijkstra(std::vector<Edge> graph[], int nodes, int start, int end) {
    bool visited[VERTICES] = {0};
    clearpq(Q);
    Q.push({-0, start});
    while (!Q.empty()) {
        std::pair<int, int> arc = Q.top();
        Q.pop();
        int v = arc.second;
        int p = arc.first;
        if (v == end) return -p;
        if (not visited[v]) {
            visited[v] = true;
            for (unsigned int i = 0; i < graph[v].size(); ++i) {
                int u = graph[v][i].node;
                int w = graph[v][i].cost;
                Q.push({p - w, u});
            }
        }
    }
    return std::numeric_limits<int>::max();
}

int main() {
    // Use a vector of edges as the graph will be sparse (nodes² >> edges) and
    // we don't have enough memory to store all possible edges of a dense graph
    // with an adjacency matrix
    std::vector<Edge> graph[VERTICES];
    int n, c, k;
    while (fastscan(&n)) {
        // Clear the graph, reusing any memory that was already allocated in a
        // previous test
        for (int i = 0; i < n; ++i)
            graph[i].clear();
        fastscan(&c);
        // Parse the edges
        for (int i = 0; i < c; ++i) {
            int a, b, cost;
            fastscan(&a);
            fastscan(&b);
            fastscan(&cost);
            --a, --b;
            graph[a].push_back({b, cost});
            graph[b].push_back({a, cost});
        }

        // There are few queries (<=10) and a ton of nodes, so use dijkstra for
        // each query instead of floyd-warshall (which we don't have enough
        // memory for anyways)
        fastscan(&k);
        while (k--) {
            int a, b;
            fastscan(&a);
            fastscan(&b);
            --a, --b;
            int cost = dijkstra(graph, n, a, b);
            if (cost == std::numeric_limits<int>::max()) {
                putchar_unlocked('N');
                putchar_unlocked('O');
                putchar_unlocked(' ');
                putchar_unlocked('L');
                putchar_unlocked('L');
                putchar_unlocked('E');
                putchar_unlocked('G');
                putchar_unlocked('A');
            } else {
                fastprint(cost);
            }
            putchar_unlocked('\n');
        }
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('\n');
    }
    return 0;
}
