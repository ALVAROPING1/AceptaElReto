#include <bits/stdc++.h>

template <typename T> inline bool fastscan_check(T& number) {
    number = 0;
    register int c = getchar_unlocked();
    if (c == -1) return false;
    while (c < '0')
        c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0'); c = getchar_unlocked())
        number = number * 10 + c - '0';
    return true;
}

template <typename T> inline void fastscan(T& number) {
    number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0'); c = getchar_unlocked())
        number = number * 10 + c - '0';
}

// Maximum amount of participants
const int MAX = 100000;
// Maximum amount of participant comparisons
const int MAX_EDGES = 300000;

int n;
char color[MAX];
int equivalent[MAX];
int size[MAX];
std::vector<int> graph[MAX];

struct arc {
    int a, b;
    char type;
};

inline int findSet(int i) {
    while (equivalent[i] != i) {
        equivalent[i] = equivalent[equivalent[i]];
        i = equivalent[i];
    }
    return i;
}

inline void union_set(int i, int j) {
    if (size[i] < size[j]) {
        equivalent[i] = j;
        size[j] += size[i];
    } else {
        equivalent[j] = i;
        size[i] += size[j];
    }
}

inline bool dfs(int v) {
    int stack[MAX];
    int depth = 0;
    stack[0] = v;
    while (depth >= 0) {
        int curr = stack[depth];
        if (color[curr] != 1) {
            color[curr] = 1;
            for (int u : graph[curr]) {
                if (color[u] == 1) return true;
                if (color[u] == 0) stack[++depth] = u;
            }
        } else {
            --depth;
            color[curr] = 2;
        }
    }
    return false;
}

int main() {
    struct arc edges[MAX_EDGES];
    while (fastscan_check(n)) {
        for (int i = 0; i < n; ++i) {
            graph[i].clear();
            color[i] = 0;
            equivalent[i] = i;
            size[i] = 1;
        }
        int e = 0;
        int c;
        fastscan(c);
        while (c--) {
            int a, b;
            fastscan(a);
            int type = getchar_unlocked();
            getchar_unlocked(); // Ignore space
            fastscan(b);
            a = findSet(a - 1);
            b = findSet(b - 1);
            if (type == '=') union_set(a, b);
            else {
                edges[e].a = a;
                edges[e].b = b;
                edges[e].type = type;
                ++e;
            }
        }
        while (e--) {
            int a = findSet(edges[e].a);
            int b = findSet(edges[e].b);
            if (edges[e].type == '<') graph[b].push_back(a);
            else graph[a].push_back(b);
        }
        for (int v = 0; v < n; ++v) {
            if (equivalent[v] == v && color[v] == 0 && dfs(v)) {
                putchar_unlocked('T');
                putchar_unlocked('R');
                putchar_unlocked('A');
                putchar_unlocked('M');
                putchar_unlocked('P');
                putchar_unlocked('A');
                putchar_unlocked('S');
                goto end;
            }
        }
        // We didn't detect cheats
        putchar_unlocked('D');
        putchar_unlocked('E');
        putchar_unlocked('S');
        putchar_unlocked('C');
        putchar_unlocked('O');
        putchar_unlocked('N');
        putchar_unlocked('F');
        putchar_unlocked('I');
        putchar_unlocked('A');
        putchar_unlocked('D');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
    }
    return 0;
}
