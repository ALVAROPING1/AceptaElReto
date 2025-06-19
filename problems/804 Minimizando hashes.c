#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
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
    putchar_unlocked('\n');
}

typedef struct Node {
    struct Node* child[2];
    int frequency;
} Node;

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        // Maintain a binary tree with the sequences seen
        Node root;
        root.frequency = 0;
        root.child[0] = NULL;
        root.child[1] = NULL;
        int result = 0;
        while (n--) {
            Node* curr = &root;
            char c;
            while ((c = getchar_unlocked()) != '\n') { // For each hash
                // Convert the hash to a binary string
                c -= 'a';
                // Update the amount of characters required
                switch (curr->frequency) {
                // We already saw prefix once, so we need to type 2 extra
                // characters for desambiguation (once for the current hash and
                // once for the first time we saw this prefix)
                case 1:
                    result += 2;
                // We haven't seen this prefix yet, so no extra characters
                case 0:
                    break;
                // We have seen this prefix multiple times, so we just need an
                // extra character for the current hash
                default:
                    ++result;
                    break;
                }
                // Append the current character to the tree and update the
                // frequency of the path
                ++curr->frequency;
                if (curr->child[(int) c] == NULL) {
                    Node* next = (Node*) malloc(sizeof(Node));
                    next->frequency = 0;
                    next->child[0] = NULL;
                    next->child[1] = NULL;
                    curr->child[(int) c] = next;
                }
                curr = curr->child[(int) c];
            }
            curr->frequency++;
        }
        fastprint(result);
        fastscan(&n);
    }
    return 0;
}
