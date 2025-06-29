#include <bits/stdc++.h>

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

#define MAX 100

// source: https://www.geeksforgeeks.org/dsa/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/
// TODO: Understand/simplify/optimize the algorithm

#define NIL 0
#define INF INT_MAX

// A class to represent Bipartite graph for Hopcroft
// Karp implementation
class BipGraph {
    // m and n are number of vertices on left
    // and right sides of Bipartite Graph
    int m, n;

    // adj[u] stores adjacents of left side
    // vertex 'u'. The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
    std::vector<std::list<int>> adj;

    // These are basically pointers to arrays needed
    // for hopcroftKarp()
    std::vector<int> pairU, pairV, dist;

  public:
    BipGraph() {}
    void addEdge(int u, int v); // To add edge

    // Returns true if there is an augmenting path
    bool bfs();

    // Adds augmenting path if there is one beginning
    // with u
    bool dfs(int u);

    // Returns size of maximum matching
    int hopcroftKarp();

    void reset(int m, int n) {
        this->m = m;
        this->n = n;
        adj.clear();
        adj.resize(m + 1);

        // pairU[u] stores pair of u in matching where u
        // is a vertex on left side of Bipartite Graph.
        // If u doesn't have any pair, then pairU[u] is NIL
        pairU.resize(m + 1);

        // pairV[v] stores pair of v in matching. If v
        // doesn't have any pair, then pairU[v] is NIL
        pairV.resize(n + 1);

        // dist[u] stores distance of left side vertices
        // dist[u] is one more than dist[u'] if u is next
        // to u'in augmenting path
        dist.resize(m + 1);
    }
};

// Returns size of maximum matching
int BipGraph::hopcroftKarp() {
    // Initialize NIL as pair of all vertices
    for (int u = 0; u <= m; u++)
        pairU[u] = NIL;
    for (int v = 0; v <= n; v++)
        pairV[v] = NIL;

    // Initialize result
    int result = 0;

    // Keep updating the result while there is an
    // augmenting path.
    while (bfs()) {
        // Find a free vertex
        for (int u = 1; u <= m; u++)

            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u] == NIL && dfs(u)) result++;
    }
    return result;
}

// Returns true if there is an augmenting path, else returns
// false
bool BipGraph::bfs() {
    std::queue<int> Q; // an integer queue

    // First layer of vertices (set distance as 0)
    for (int u = 1; u <= m; u++) {
        // If this is a free vertex, add it to queue
        if (pairU[u] == NIL) {
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }

        // Else set distance as infinite so that this vertex
        // is considered next time
        else
            dist[u] = INF;
    }

    // Initialize distance to NIL as infinite
    dist[NIL] = INF;

    // Q is going to contain vertices of left side only.
    while (!Q.empty()) {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();

        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL]) {
            // Get all adjacent vertices of the dequeued vertex u
            std::list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = *i;

                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF) {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }

    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}

// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u) {
    if (u != NIL) {
        std::list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Adjacent to u
            int v = *i;

            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u] + 1) {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        // If there is no augmenting path beginning with u.
        dist[u] = INF;
        return false;
    }
    return true;
}

// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v) {
    adj[u + 1].push_back(v + 1); // Add u to v’s list.
}

#define LABEL_COMPONENTS(res, n, dir)                                          \
    for (int i = 0; i < size; ++i) {                                           \
        int j = 0;                                                             \
        while (j < size) {                                                     \
            while (j < size && map[dir ? i : j][dir ? j : i] == 'X')           \
                j++;                                                           \
            if (j == size) break;                                              \
            while (j < size && map[dir ? i : j][dir ? j : i] == '.') {         \
                res[dir ? i : j][dir ? j : i] = n;                             \
                j++;                                                           \
            }                                                                  \
            n++;                                                               \
        }                                                                      \
    }

int main() {
    int size;
    fastscan(&size);
    char map[MAX][MAX];
    BipGraph g{};
    while (size != 0) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                map[i][j] = getchar_unlocked();
            getchar_unlocked(); // Consume line jump
        }

        int n = 0, k = 0;
        int hor[MAX][MAX];
        int vert[MAX][MAX];
        LABEL_COMPONENTS(hor, n, true);
        LABEL_COMPONENTS(vert, k, false);

        g.reset(n, k);
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (map[row][col] == '.') {
                    g.addEdge(hor[row][col], vert[row][col]);
                }
            }
        }

        fastprint(g.hopcroftKarp());
        fastscan(&size);
    }
    return 0;
}
