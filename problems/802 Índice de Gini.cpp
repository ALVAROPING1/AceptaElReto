#include <bits/stdc++.h>

inline void fastscan(unsigned int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscanll(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(long long number) {
    char buffer[32];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
}

int main() {
    unsigned int n, k;
    fastscan(&n);
    fastscan(&k);
    long long heap[1000]; // min heap
    unsigned int size = 0;
    auto comp = std::greater<long long>{};
    while (n != 0 && k != 0) {
        long long total = 0;
        long long rich = 0;
        long long curr;
        while (n--) { // For each person
            fastscanll(&curr);
            total += curr;
            // For the first k people, add them to the heap and consider them as
            // rich. For each person after that, consider them as rich if they
            // are richer than the least rich person considered (top of the min
            // heap)
            if (size < k) {
                rich += curr;
                heap[size++] = curr;
                std::push_heap(&heap[0], heap + size, comp);
            } else if (heap[0] < curr) {
                rich += curr - heap[0];
                std::pop_heap(&heap[0], &heap[size], comp);
                heap[size - 1] = curr;
                std::push_heap(&heap[0], &heap[size], comp);
            }
        }
        fastprint(total);
        putchar_unlocked(' ');
        fastprint(rich);
        putchar_unlocked('\n');
        fastscan(&n);
        fastscan(&k);
        size = 0;
    }
    return 0;
}
