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
}

#define MAX 50

struct Point {
    int x, y;
};

const struct Point dir4[]{
    { 1,  0},
    { 0,  1},
    {-1,  0},
    { 0, -1}
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

// Calculates the new direction in which the cube faces according to the
// direction of movement and the current rotation
inline int rotate(int rotation, Point delta) {
    switch (rotation) {
    case 0:
        if (delta.x == 1) return 1;
        if (delta.x == -1) return 3;
        if (delta.y == 1) return 4;
        if (delta.y == -1) return 5;
    case 1:
        if (delta.x == 0) return 1;
        if (delta.x == -1) return 0;
        if (delta.x == 1) return 2;
    case 2:
        if (delta.x == 1) return 3;
        if (delta.x == -1) return 1;
        if (delta.y == 1) return 5;
        if (delta.y == -1) return 4;
    case 3:
        if (delta.x == 0) return 3;
        if (delta.x == -1) return 2;
        if (delta.x == 1) return 0;
    case 4:
        if (delta.y == 0) return 4;
        if (delta.y == -1) return 0;
        if (delta.y == 1) return 2;
    case 5:
        if (delta.y == 0) return 5;
        if (delta.y == -1) return 2;
        if (delta.y == 1) return 0;
    }
    return 0;
}

inline int distance(Point start, Point end) {
    return std::abs(end.x - start.x) + std::abs(end.y - start.y);
}

std::priority_queue<std::tuple<int, int, std::tuple<int, int, int>>> Q;

struct Graph {
    Point edges[MAX][MAX][4];
    int sizes[MAX][MAX];
};

std::pair<int, int> a_star(Graph& graph, Point start, Point end) {
    bool visited[MAX][MAX][6] = {{{0}}};
    clearpq(Q);
    int h = -distance(start, end);
    Q.push(std::make_tuple(h, -0, std::make_tuple(start.x, start.y, 0)));
    int min = -1;
    while (!Q.empty()) {
        auto arc = Q.top();
        Q.pop();
        int d = std::get<1>(arc);
        auto state = std::get<2>(arc);
        int rotation = std::get<2>(state);
        Point v = Point{std::get<0>(state), std::get<1>(state)};

        if (v.x == end.x && v.y == end.y) {
            // If this is the first time we reached the end, we have the minimum
            // cost
            if (min == -1) min = -d;
            // If the cube is facing down, we have found the best solution
            if (rotation == 0) return {min, -d};
        }

        if (not visited[v.y][v.x][rotation]) {
            visited[v.y][v.x][rotation] = true;
            for (int i = 0; i < graph.sizes[v.y][v.x]; ++i) {
                auto delta = graph.edges[v.y][v.x][i];
                int nx = v.x + delta.x;
                int ny = v.y + delta.y;
                int nr = rotate(rotation, delta);
                auto next = std::make_tuple(nx, ny, nr);
                // Heuristic used for A*: manhattan distance plus the amount of
                // rotations needed for the cube to face down
                int rotations = nr == 0 ? 0 : (nr != 2 ? 1 : 2);
                int h = d - 1 - distance({nx, ny}, end) - rotations;
                Q.push(std::make_tuple(h, d - 1, next));
            }
        }
    }
    return {min, -1};
}

inline void impossible() {
    putchar_unlocked('I');
    putchar_unlocked('M');
    putchar_unlocked('P');
    putchar_unlocked('O');
    putchar_unlocked('S');
    putchar_unlocked('I');
    putchar_unlocked('B');
    putchar_unlocked('L');
    putchar_unlocked('E');
}

#define MAP(x) (2 * x + 1)

int main() {
    int tx, ty;
    fastscan(&tx);
    fastscan(&ty);
    char map[MAP(MAX)][MAP(MAX)];
    Graph graph;
    while (tx != 0 && ty != 0) {
        Point start, end;
        int mtx = MAP(tx), mty = MAP(ty);
        // Read the map
        for (int y = 0; y < mty; ++y) {
            for (int x = 0; x < mtx; ++x)
                map[y][x] = getchar_unlocked();
            getchar_unlocked(); // Ignore new line
        }
        // Parse the map into a graph
        for (int y = 0; y < ty; ++y) {
            for (int x = 0; x < tx; ++x) {
                int mx = MAP(x), my = MAP(y);
                char c = map[mx][my];
                // Check if the tile contains the start/end
                if (c == 'O') start = {x, y};
                else if (c == 'D') end = {x, y};
                // Reset the available neighbors
                graph.sizes[y][x] = 0;
                // For each possible neighbor, append it to the neighbors if we
                // can move to it
                for (Point delta : dir4) {
                    int nx = mx + delta.x;
                    int ny = my + delta.y;
                    if (nx >= 0 && nx < mtx && ny >= 0 && ny < mty &&
                        map[ny][nx] == ' ')
                        graph.edges[y][x][graph.sizes[y][x]++] = delta;
                }
            }
        }

        // Find the solution and print the results
        auto res = a_star(graph, start, end);
        if (res.first == -1) impossible();
        else fastprint(res.first);
        putchar_unlocked(' ');
        if (res.second == -1) impossible();
        else fastprint(res.second);
        putchar_unlocked('\n');
        fastscan(&tx);
        fastscan(&ty);
    }
    return 0;
}
