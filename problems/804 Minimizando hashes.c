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
    int child[2];
    int frequency;
} Node;

int main() {
    int n;
    fastscan(&n);
    // Use a memory pool to store the tree nodes, so that we can easily reuse
    // the memory and don't need to be allocating memory on each new node
    // The size was manually obtained through trial and error: too little
    // results in RTE while too much results in MLE. From there binary search
    // was used to get as close to RTE as possible
    // The stack isn't big enough for 18MB smh. >:(
    Node* mem = (Node*) malloc(1516000 * sizeof(Node));
    int size = 0;
    while (n != 0) {
        // Maintain a binary tree with the sequences seen
        mem[size].frequency = 0;
        mem[size].child[0] = 0;
        mem[size].child[1] = 0;
        ++size;
        int result = 0;
        while (n--) {
            int curr = 0;
            char c;
            while ((c = getchar_unlocked()) != '\n') { // For each hash
                // Convert the hash to a binary string
                c -= 'a';
                // Update the amount of characters required
                switch (mem[curr].frequency) {
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
                ++mem[curr].frequency;
                if (mem[curr].child[(int) c] == 0) {
                    mem[size].frequency = 0;
                    mem[size].child[0] = 0;
                    mem[size].child[1] = 0;
                    mem[curr].child[(int) c] = size++;
                }
                curr = mem[curr].child[(int) c];
            }
            ++mem[curr].frequency;
        }
        fastprint(result);
        size = 0;
        fastscan(&n);
    }
    return 0;
}
