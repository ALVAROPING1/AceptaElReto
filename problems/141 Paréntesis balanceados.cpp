#include <bits/stdc++.h>

template <typename T, int capacity> class Stack {
    std::array<T, capacity> array_;
    size_t n_{0};

  public:
    void push(T value) {
        array_[n_] = value;
        ++n_;
    }

    T pop() {
        --n_;
        return array_[n_];
    }

    constexpr const size_t size() const {
        return n_;
    }

    void clear() {
        n_ = 0;
    }
};

// Generate array with conversions from character (open delimiter) to
// corresponding closing delimiter
auto gen_open() {
    std::array<char, 256> res{0};
    res['('] = ')';
    res['['] = ']';
    res['{'] = '}';
    return res;
}

// Generate array with conversions from character to whether it's a closing
// delimiter
auto gen_close() {
    std::array<char, 256> res{0};
    res[')'] = true;
    res[']'] = true;
    res['}'] = true;
    return res;
}

// Max line size (+1 for the null terminator byte)
const size_t MAX = 10001;

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Stack<char, MAX> stack;
    char input[MAX];
    // Precompute tables
    auto open_table = gen_open();
    auto close_table = gen_close();
    // Read first line
    std::cin.getline(input, MAX);
    while (std::cin) { // While there are lines to read
        bool wrong = false;
        // Iterate through the line
        for (auto c : input) {
            if (c == '\0') break;
            // If the character is an opening delimiter, push to the stack
            char val = open_table[c];
            if (val != '\0') { stack.push(val); }
            // If the character is a closing delimiter and it doesn't match the
            // expected one, end the iteration with an error
            if (close_table[c] and stack.pop() != c) {
                wrong = true;
                break;
            }
        }
        // Print the result, reset the stack, and read the next line
        std::cout << (wrong or stack.size() != 0 ? "NO" : "YES") << "\n";
        stack.clear();
        std::cin.getline(input, MAX);
    }
    return 0;
}
