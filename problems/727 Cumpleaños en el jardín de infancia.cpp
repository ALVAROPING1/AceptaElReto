#include <bits/stdc++.h>

inline void fastscan_positive(int* number) {
    register int c;
    *number = 0;
    c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number, char delimiter) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked(delimiter);
}

using line = std::pair<int, int>;

const int constexpr MAX = 200000;

int main() {
    int cases;
    std::vector<line> lines;
    std::vector<int> kids;
    lines.reserve(MAX);
    kids.reserve(MAX);
    fastscan_positive(&cases);
    while (cases--) {
        int n, i;
        fastscan_positive(&n);
        // Read the columns
        for (i = 0; i < n - 1; ++i) {
            int amount;
            fastscan_positive(&amount);
            // For each column, read its lines
            while (amount--) {
                int height;
                fastscan_positive(&height);
                // Record the height of the line and where it starts from
                lines.push_back({height, i});
            }
        }
        // Sort the lines according to their height
        std::sort(lines.begin(), lines.end(), [](const line& a, const line& b) {
            return a.first < b.first;
        });
        // Generate the initial position of each kid
        for (i = 0; i < n; ++i)
            kids.push_back(i);
        // Process the lines from top to bottom. For each one, swap the kids at
        // each end of the line
        for (auto l : lines)
            std::swap(kids[l.second], kids[l.second + 1]);

        // After processing all lines, each position contains the ID of the kid
        // that ended up on it
        int worse = 0;
        int same = 0;
        int better = 0;
        for (i = 0; i < n; ++i) {
            if (i < kids[i]) ++worse;
            else if (i > kids[i]) ++better;
            else ++same;
        }

        fastprint(worse, ' ');
        fastprint(same, ' ');
        fastprint(better, '\n');
        lines.clear();
        kids.clear();
    }
    return 0;
}
