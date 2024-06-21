#include <bits/stdc++.h>

template <typename T> inline void fastscan(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
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

class Trie {
    struct Node {
        std::vector<Node> children;
        int amount{0};
        Node() : children{} {}
    };

    Node root{};

    int char2index(char c) {
        return (c >= 'A' && c <= 'Z') ? c - 'A' : c - 'a';
    }

  public:
    void insert(char first_char) {
        Node* node = &root;
        for (register int c = first_char; c != ' '; c = getchar_unlocked()) {
            int idx = char2index(c);
            if (node->children.size() == 0) { node->children.resize(26); }
            node = &node->children[idx];
        }
        node->amount += getchar_unlocked() - '0';
        getchar_unlocked(); // Skip the newline character
    }

    int search() {
        Node* node = &root;
        for (register int c = getchar_unlocked(); c > ' ';
             c = getchar_unlocked()) {
            int idx = char2index(c);
            node = &node->children[idx];
        }
        int amount = node->amount;
        node->amount = 0;
        return amount;
    }

    void clear() {
        root = Node{};
    }
};

int main() {
    Trie memory{};
    int n;
    fastscan(n);
    while (n != 0) {
        while (n--) {
            register int c = getchar_unlocked();
            if (c != '?') memory.insert(c);
            else {
                getchar_unlocked(); // Skip space character
                int k, total = 0;
                fastscan(k);
                while (k--)
                    total += memory.search();
                fastprint(total);
            }
        }
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('\n');
        fastscan(n);
        memory.clear();
    }
    return 0;
}
