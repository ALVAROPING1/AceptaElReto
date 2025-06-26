#include <stdbool.h>
#include <stdio.h>
#include <string.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

inline void fastprint(int number, char suffix) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked(suffix);
}

#define VERTICES 100
#define EDGES 1000

// Representation of a graph using lists of lists, to allow faster querying of
// node neighbors
typedef struct Graph {
    int edges[VERTICES][VERTICES];
    int sizes[VERTICES];
} Graph;

// Recursive dfs to find cycles in a graph
bool dfs(Graph* graph, bool visited[], int parent, int v) {
    visited[v] = true; // Mark the node as visited
    bool res = false; // Initialize result
    int j;
    for (j = 0; j < graph->sizes[v]; ++j) { // For each neighbor
        int u = graph->edges[v][j];
        // Skip it if it's the parent
        if (u == parent) continue;
        // If we had already visited it, we found a cycle
        if (visited[u]) res = true;
        // Otherwise, recursively search a cycle that goes through the node
        else if (dfs(graph, visited, v, u)) res = true;
    }
    return res;
}

int main() {
    int v, e, i;
    while (fastscan(&v)) {
        fastscan(&e);
        Graph graph = {{{0}}, {0}};
        // Whether each vertex has an edge
        bool non_isolated[VERTICES] = {0};
        // Whether each vertex has been visited in the dfs
        bool visited[VERTICES] = {0};
        // Amount of isolated nodes
        int isolated = v;
        for (i = 0; i < e; ++i) { // Parse the edges
            int a, b;
            fastscan(&a);
            fastscan(&b);
            --a, --b;
            graph.edges[a][graph.sizes[a]++] = b;
            graph.edges[b][graph.sizes[b]++] = a;
            // If this was the first edge of either of the nodes, decrement the
            // amount of isolated nodes
            isolated -= !non_isolated[a];
            isolated -= !non_isolated[b];
            non_isolated[a] = true;
            non_isolated[b] = true;
        }
        int trees = 0, graphs = 0;
        // For each vertex
        for (i = 0; i < v; ++i) {
            // If we have visited it already in the dfs or it is isolated, skip
            // it
            if (visited[i] != 0 || !non_isolated[i]) continue;
            // Perform a dfs to find a cycle and visit all nodes in the
            // connected component, then increment the appropriate count based
            // on the result
            if (dfs(&graph, visited, -1, i)) ++graphs;
            else ++trees;
        }
        // Print results
        fastprint(isolated, ' ');
        fastprint(trees, ' ');
        fastprint(graphs, '\n');
    }
    return 0;
}
