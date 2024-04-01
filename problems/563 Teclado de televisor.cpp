#include <bits/stdc++.h>

// Max amount of rows in the keyboard
const int MAX_ROWS = 8;
// Max amount of columns in the keyboard
const int MAX_COLS = 20;
// Max size of the query words
const int MAX_WORD_LEN = 100;
// Max amount of possible nodes
const int MAX_NODES = 'Z' - 'A' + 12;

using Keyboard = std::array<std::string, MAX_ROWS>;
using Graph = std::array<std::array<int, MAX_NODES>, MAX_NODES>;
using IDs = std::array<char, 256>;

// Calculates the IDs
char gen_ids(Keyboard& keyboard, IDs& ids, int F, int C) {
    // Clears the previous data
    ids.fill(-1);
    char nodes = 0;
    // For each character in the keyboard
    for (int row = 0; row < F; ++row) {
        for (int col = 0; col < C; ++col) {
            // If it doesn't have an ID, set its ID to current total amount of
            // set IDs
            char c = keyboard[row][col];
            if (ids[c] == -1) ids[c] = nodes++;
        }
    }
    return nodes;
}

// Parses the keyboard into an adjacency matrix
void parse_kb(Keyboard& keyboard, int F, int C, IDs& ids, Graph& graph) {
    // Array of processed keys
    std::array<bool, MAX_NODES> visited{false};
    // Iterates through the characters in the keyboard
    for (int row = 0; row < F; ++row) {
        for (int col = 0; col < C; ++col) {
            // Get the ID of the key
            char c = keyboard[row][col];
            char id = ids[c];
            // Only process it if it hasn't been seen already
            if (visited[id]) continue;
            visited[id] = true;
            // Reset the graph for the row corresponding to this node
            graph[id].fill(std::numeric_limits<int>::max() / 2);
            // Add an edge from the current key to the key at its left/top
            graph[id][ids[keyboard[row][(col - 1 + C) % C]]] = 1;
            graph[id][ids[keyboard[(row - 1 + F) % F][col]]] = 1;
            // Set the distance from the key to itself to 0
            graph[id][id] = 0;
            // Search for the right key
            for (int right = 0; right < C; ++right) {
                // Move right until we find a new key
                char other = keyboard[row][(col + right) % C];
                if (c != other) {
                    // Add an edge from the current key to the found key
                    graph[id][ids[other]] = 1;
                    break;
                }
            }
            // Search for the bottom key
            for (int below = 0; below < F; ++below) {
                // Move down until we find a new key
                char other = keyboard[(row + below) % F][col];
                if (c != other) {
                    // Add an edge from the current key to the found key
                    graph[id][ids[other]] = 1;
                    break;
                }
            }
        }
    }
}

// Applies the Floyd-Warshall algorithm to the graph to get the distance between
// each pair of nodes
void floyd_warshal(Graph& graph, int nodes) {
    for (int k = 0; k < nodes; ++k)
        for (int i = 0; i < nodes; ++i)
            for (int j = 0; j < nodes; ++j)
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
}

// Processes the query words
void process_queries(
    Graph& graph, IDs& ids, char start_id, int N, std::string word) {
    // For each query word
    for (int i = 0; i < N; ++i) {
        // Get the word
        // std::cin.getline() doesn't work for whatever reason
        std::getline(std::cin, word);
        int total = 0;        // Total distance
        char prev = start_id; // Previous key
        // For each char in the word
        for (char c : word) {
            char curr = ids[c];         // Get its ID
            total += graph[prev][curr]; // Add the distance from the current key
            prev = curr;                // Move to the key
        }
        std::cout << total << "\n";
    }
    std::cout << "---\n";
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Keyboard keyboard;
    Graph graph;
    IDs ids;
    std::string word;
    word.reserve(MAX_WORD_LEN);
    for (auto s : keyboard) {
        s.reserve(MAX_COLS);
    }

    int F, C, N;
    std::cin >> F >> C >> N;
    std::cin.ignore();
    while (F != 0 or C != 0 or N != 0) {
        // Read the keyboard
        for (int i = 0; i < F; ++i)
            // std::cin.getline() doesn't work for whatever reason
            std::getline(std::cin, keyboard[i]);

        // Parse the keyboard
        auto nodes = gen_ids(keyboard, ids, F, C);
        parse_kb(keyboard, F, C, ids, graph);
        floyd_warshal(graph, nodes);
        process_queries(graph, ids, ids[keyboard[0][0]], N, word);

        std::cin >> F >> C >> N;
        std::cin.ignore();
    }
    return 0;
}
