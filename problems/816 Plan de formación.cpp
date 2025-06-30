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
    putchar_unlocked('\n');
}

#define INF 100000
#define MAX_P 1000
#define MAX_C 30
#define MAX (MAX_C + MAX_P + 2)

// Amount of nodes
int n;
// Matrix with the capacity of each edge in the graph
// TODO: try compressing information knowing the shape of the graph?
int capacity[MAX][MAX];

std::vector<int> adj[MAX];

int bfs(int s, int t, int parent[MAX]) {
    std::fill(&parent[0], &parent[n], -1);
    parent[s] = -2;
    std::queue<std::pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = std::min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

// Max flow problem solution using Edmonds-Karp algorithm
int maxflow(int s, int t) {
    int flow = 0;
    int parent[MAX];
    int new_flow;
    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

// We can transform the problem into a graph whose max flow solution corresponds
// with the solution. The graph can be divided into 4 layers such that the nodes
// on each layer are only connected to the nodes in the next layer:
//
// 1. Starting node
// 2. Problem nodes
// 3. Category nodes
// 4. End node
//
// The starting node is connected to all problem nodes with a capacity of 1
// (representing the fact that each problem can only be selected once). Each
// problem node is connected to the category nodes it belongs to with a capacity
// of 1 (representing the categories to which the problem can be assigned).
// Finally, each category node is connected to the end node with a capacity
// equal to the maximum amount of problem of that category that can be selected
//
// With this transformation, selecting a problem (adding more flow) requires
// assigning it to a category without going above the max amount of problems of
// that category

#define ADD_EDGE(a, b, cap)                                                    \
    capacity[a][b] = cap;                                                      \
    adj[a].push_back(b);                                                       \
    adj[b].push_back(a);

int main() {
    int c, p, curr;

    while (fastscan(&c)) {
        fastscan(&p);
        // Calculate the total amount of nodes in the graph
        n = p + c + 2;
        // Initialize the graph
        for (int i = 0; i < p; ++i)
            capacity[0][2 + c + i] = capacity[2 + c + i][0] = 0;
        for (int i = 0; i < c; ++i)
            capacity[1][2 + i] = capacity[2 + i][1] = 0;
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < c; ++j)
                capacity[2+c+i][2+j] = capacity[2+j][2+c+i] = 0;
        for (int i = 0; i < n; ++i)
            adj[i].clear();
        // Read the categories, creating the edges from the problem nodes to the
        // end node. We use node IDs 0/1 to represent the start/end nodes
        // respectively
        for (int i = 0; i < c; ++i) {
            int node = i + 2;
            fastscan(&curr);
            ADD_EDGE(node, 1, curr);
        }
        // Read the problems, creating the edges from the starting node to the
        // problem nodes and from those to the category nodes
        for (int i = 0; i < p; ++i) {
            int node = 2 + c + i;
            ADD_EDGE(0, node, 1); // Add edge from the starting node
            fastscan(&curr);
            while (curr != 0) { // Add edges to the categories
                curr = curr - 1 + 2;
                ADD_EDGE(node, curr, 1);
                fastscan(&curr);
            }
        }
        // Solve the max flow problem to obtain the solution
        fastprint(maxflow(0, 1));
    }
    return 0;
}
