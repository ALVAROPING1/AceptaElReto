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

// Queue implementation based on a circular buffer on static memory
template <typename T> class Queue {
    // Size of the buffer. Manually binary searched from test results
    const static constexpr int SIZE = 610;
    T q_[SIZE];
    int start_ = 0, end_ = 0;

  public:
    Queue() {}
    void clear() {
        start_ = end_ = 0;
    }

    void push(T x) {
        q_[end_] = x;
        end_ = (end_ + 1) % SIZE;
    }

    T pop() {
        T res = q_[start_];
        start_ = (start_ + 1) % SIZE;
        return res;
    }

    bool empty() {
        return start_ == end_;
    }
};

// Source:
// https://www.geeksforgeeks.org/dsa/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/

#define NIL 0
#define INF INT_MAX

// A class to represent Bipartite graph for Hopcroft Karp implementation
class BipGraph {
    // m and n are number of vertices on left and right sides of Bipartite Graph
    int m, n;

    // adj[u] stores adjacents of left side vertex 'u'. The value of u ranges
    // from 1 to m. 0 is used for dummy vertex
    std::vector<std::vector<int>> adj;

    std::vector<int> pairU, pairV, dist;
    Queue<int> Q;

  public:
    BipGraph() {}

    void reset(int m, int n) {
        this->m = m;
        this->n = n;
        adj.resize(m + 1);
        for (int i = 0; i < m + 1; ++i)
            adj[i].clear();

        // pairU[u] stores pair of u in matching where u is a vertex on left
        // side of Bipartite Graph. If u doesn't have any pair, then pairU[u] is
        // NIL
        pairU.resize(m + 1);

        // pairV[v] stores pair of v in matching. If v doesn't have any pair,
        // then pairU[v] is NIL
        pairV.resize(n + 1);

        // dist[u] stores distance of left side vertices dist[u] is one more
        // than dist[u'] if u is next to u'in augmenting path
        dist.resize(m + 1);
    }

    // To add edge from u to v and v to u
    void addEdge(int u, int v) {
        adj[u + 1].push_back(v + 1); // Add u to v’s list.
    }

    // Returns true if there is an augmenting path
    bool bfs() {
        Q.clear();
        // First layer of vertices (set distance as 0)
        for (int u = 1; u <= m; u++) {
            // If this is a free vertex, add it to queue
            if (pairU[u] == NIL) {
                dist[u] = 0;
                Q.push(u);
            } else
                // Else set distance as infinite so that this vertex is
                // considered next time
                dist[u] = INF;
        }
        // Initialize distance to NIL as infinite
        dist[NIL] = INF;
        // Q contains vertices of left side only
        while (!Q.empty()) {
            int u = Q.pop();
            for (int v : adj[u]) {
                int u2 = pairV[v];
                // Ignore the node if we already reached it
                if (dist[u2] != INF) continue;
                dist[u2] = dist[u] + 1;
                // If pairV[v] is connected to NIL, we found an augmenting
                // path
                if (u2 == NIL) return true;
                Q.push(u2);
            }
        }
        return false;
    }

    // Adds augmenting path if there is one beginning with u
    bool dfs(int u) {
        if (u == NIL) return true;
        // Adjacent to u
        for (int v : adj[u]) {
            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u] + 1) {
                // If dfs for pair of v also returns true
                if (dfs(pairV[v])) {
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

    // Returns size of maximum matching
    int hopcroftKarp() {
        // Initialize NIL as pair of all vertices
        for (int u = 0; u <= m; u++)
            pairU[u] = NIL;
        for (int v = 0; v <= n; v++)
            pairV[v] = NIL;
        int result = 0;
        // Keep updating the result while there is an augmenting path
        while (bfs()) {
            for (int u = 1; u <= m; u++)
                // If current vertex is free and there is
                // an augmenting path from current vertex
                if (pairU[u] == NIL && dfs(u)) result++;
        }
        return result;
    }
};

// The problem can be solved by transforming it into a bipartite graph in which
// the maximum matching size (maximum amount of edges that can be chosen such
// that no 2 pairs of edges share a vertex) corresponds with the solution. This
// problem can be solved with a standard algorithm
//
// In order to transform the problem into a graph, we need to encode the placed
// towers. Selections have to be represented as edges in the matching, so
// placing a tower must be represented as choosing an edge of the graph. Thus,
// we need to encode the positions in their vertices, and we need to do so in
// such a way that towers in positions that would attack each other would share
// a vertex
//
// We can do this by choosing the vertices to be horizontal/vertical
// groups of tiles not separated by a broken tile (with horizontal group
// belonging to one bipartite group and vertical groups to the other), with
// edges connecting the horizontal/vertical groups that share a tile. Thus,
// choosing an edge represents placing a tower at the tile where the
// horizontal/vertical groups overlap, and towers that would attack eachother
// would share the vertex corresponding to the horizontal/vertical group they
// are attacking eachother through

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
        // Read the map
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                map[i][j] = getchar_unlocked();
            getchar_unlocked(); // Consume line jump
        }
        int n = 0, k = 0;
        int hor[MAX][MAX];
        int vert[MAX][MAX];
        // Create nodes for each of the horizontal/vertical groups of tiles
        LABEL_COMPONENTS(hor, n, true);
        LABEL_COMPONENTS(vert, k, false);
        // Connect the nodes according to the overlap between
        // horizontal/vertical groups
        g.reset(n, k);
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (map[row][col] == '.')
                    g.addEdge(hor[row][col], vert[row][col]);
            }
        }
        // Solve the maximum matching problem in the resulting bipartite graph
        // to obtain the solution
        fastprint(g.hopcroftKarp());
        fastscan(&size);
    }
    return 0;
}
