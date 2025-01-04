#include <bits/stdc++.h>

// Read positive number
template <typename T> inline void fastscan_positive(T& number) {
    number = 0;
    // Keep on extracting characters if they are integers
    for (register int c = getchar_unlocked(); (c >= '0' && c <= '9');
         c = getchar_unlocked())
        number = number * 10 + c - '0';
}

// Read positive/negative number
template <typename T> inline void fastscan(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    // Extract current character from buffer
    c = getchar_unlocked();
    if (c == '-') {
        negative = true;
        // Extract the next character from the buffer
        c = getchar_unlocked();
    }

    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        number = number * 10 + c - '0';

    if (negative) number *= -1;
}

// Read an entire line, returning its length
template <typename T> inline int fastscan_line(T& line) {
    // Keep on extracting characters if they aren't the line terminator
    register int i = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return 0;
    for (; c != '\n'; c = getchar_unlocked())
        line[i++] = c;
    line[i] = '\0';
    return i;
}

template <typename T> inline void fastprint(T number) {
    // if (number < 0) {
    //     putchar_unlocked('-');
    //     number *= -1;
    // }
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

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int abs(int x) {
    return x * ((x >= 0) * 2 - 1);
}

inline char lowercase(char c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

inline int gcd(int a, int b) {
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (1) {
        int res = b % a;
        if (res == 0) return a;
        b = a;
        a = res;
    }
}

inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// One of the fastest sorting algorithms for very small (~10 elements) list
void insertion_sort(int arr[], int size) {
    int i, j;
    for (i = 1; i < size; ++i) {
        int temp = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = temp;
    }
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // Replace stdin for debugging
    freopen("in.txt", "r", stdin);
}
