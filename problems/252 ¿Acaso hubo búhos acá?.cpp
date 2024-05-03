#include <bits/stdc++.h>

// Max line size (+1 for the null terminator byte)
const size_t MAX = 101;

int get_line(char line[MAX]) {
    register int i = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); c != '\n'; c = getchar_unlocked())
        if (c != ' ') line[i++] = c;
    line[i] = '\0';
    return i;
}

char lowercase(char c) {
    return (c >= 'A' and c <= 'Z') ? c - 'A' + 'a' : c;
}

bool is_palindrome(char input[], int n) {
    int end = n / 2;
    // Iterate through half of the line
    for (int i = 0; i < end; ++i) {
        // Check if it's palindrome at the current character
        if (lowercase(input[i]) != lowercase(input[n - i - 1])) return false;
    }
    return true;
}

bool not_end_case(char line[]) {
    return line[0] != 'X' || line[1] != 'X' || line[2] != 'X' ||
           line[3] != '\0';
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char line[MAX];
    // Read first line
    int n = get_line(line);
    while (not_end_case(line)) { // While there are lines to read
        // Print the result, reset the stack, and read the next line
        std::cout << (is_palindrome(line, n) ? "SI" : "NO") << "\n";
        n = get_line(line);
    }
    return 0;
}
