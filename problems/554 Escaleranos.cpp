#include <bits/stdc++.h>

// Max amount of steps
const size_t max_steps = 101;
// Max amount of types of steps
const size_t max_types = 10;
// Modulo for output
const size_t mod = 1e9 + 7;

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Init arrays
    std::array<int, 2 * max_steps> steps_table{0};
    std::array<int, max_types> types;
    while (true) {
        int steps, n_types;
        // Read amount of steps
        std::cin >> steps;
        // Check if it's the end case
        if (steps == 0) break;
        // Read the types of steps
        std::cin >> n_types;
        for (int i = 0; i < n_types; ++i) {
            std::cin >> types[i];
        }
        // Base case
        steps_table[0] = 1;
        // Recursive cases
        for (int i = 0; i < steps; ++i) {
            for (int j = 0; j < n_types; ++j) {
                int size = types[j];
                steps_table[i + size] =
                    (steps_table[i + size] + steps_table[i]) % mod;
            }
        }
        // Print the result and reset the steps table
        std::cout << steps_table[steps] << "\n";
        steps_table.fill(0);
    }
    return 0;
}
