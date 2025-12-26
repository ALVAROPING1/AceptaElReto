#include <stdbool.h>
#include <stdio.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

#define MAX 32

int start[MAX];
int end[MAX];

// Gets the last index in the array with a value smaller than or equal to
// `value`. As the array is small (<= 32 values), a full scan is faster than
// binary search thanks to better cache usage and less overhead
inline int search(int n, int arr[], int value) {
    int i;
    for (i = 0; i < n; ++i)
        if (arr[i] > value) break;
    return i - 1;
}

int main() {
    int nums, curr, prev;
    while (fastscan(&nums)) {
        fastscan(&prev);
        --nums;
        int pos = MAX - 1;
        // Initialize an empty range with the starting value
        start[pos] = prev;
        end[pos] = prev - 1;
        while (nums--) {
            fastscan(&curr);
            // Find the closest range that could contain the current value
            int i = search(MAX - pos, &start[pos], curr);
            // Check if the current value falls into one of the previous ranges
            if (i >= 0 && end[pos + i] >= curr) {
                // Consume remaining line and print the answer
                if (nums > 0)
                    while (getchar_unlocked() != '\n') {}
                putchar_unlocked('E');
                putchar_unlocked('L');
                putchar_unlocked('E');
                putchar_unlocked('G');
                putchar_unlocked('I');
                putchar_unlocked('R');
                putchar_unlocked(' ');
                putchar_unlocked('O');
                putchar_unlocked('T');
                putchar_unlocked('R');
                putchar_unlocked('A');
                goto end;
            }
            if (curr < prev) {
                // If the value is smaller than the previous one, it must be the
                // smallest value found. This is because if it wasn't, there
                // would have to be a range from that previous absolute minimum
                // to the previous value. Thus, the current value would be in
                // that range, meaning the previous check would have detected
                // it. Since that didn't happen, it would be a contradiction.
                // Thus, we can just append a new empty range with the current
                // value as start to the stack while maintaining the ordered
                // list invariant. Additionally, if the previous last range was
                // empty, we can get rid of it while we are at it since it will
                // always be empty until it is removed
                pos -= (start[pos]-1 != end[pos]);
                start[pos] = curr;
                end[pos] = curr - 1;
            } else {
                // If the value is greater than the previous one, we just need
                // to create a new range from the current absolute minimum
                // (first range, as the list is ordered) to the current value.
                // This new range is guaranteed to completely contain all ranges
                // up to the `i`-th (since that's the last range that ends
                // before the current value). Thus we can get rid of them while
                // we are at it to speed up future searches and reduce memory
                // usage
                start[pos + i] = start[pos];
                end[pos + i] = curr;
                pos = pos + i;
            }
            prev = curr;
        }
        // We didn't find any points that were contained in a range before them
        putchar_unlocked('S');
        putchar_unlocked('I');
        putchar_unlocked('E');
        putchar_unlocked('M');
        putchar_unlocked('P');
        putchar_unlocked('R');
        putchar_unlocked('E');
        putchar_unlocked(' ');
        putchar_unlocked('P');
        putchar_unlocked('R');
        putchar_unlocked('E');
        putchar_unlocked('M');
        putchar_unlocked('I');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
    }
    return 0;
}
