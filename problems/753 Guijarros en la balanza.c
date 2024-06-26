#include <stdbool.h>
#include <stdio.h>

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

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

// Maximum amount of weights
#define MAX 12

// For some reason these variables being global results in a much faster time
int weights[MAX];
int n;
int target;

struct pair {
    int pos, current;
};

int main() {
    struct pair stack[1 << MAX];
    fastscan(&n);
    while (n != 0) {
        int total = 0;
        int i = n;
        // Read all the weights and calculate target value of each group
        while (i--) {
            fastscan(&weights[i]);
            total += weights[i];
        }
        target = total / 2;
        // Sort the array to iterate through the possibilities from greatest to
        // smallest. This is a heuristic, it doesn't guarantee a faster
        // solution, but takes polynomial (O(n²)) time and starts pruning paths
        // that overshoot the target faster in the exponential (O(2^n)) solution
        // space
        insertion_sort(weights, n);
        // All elements are taken or not taken. Either subgroup must sum the
        // same. If any values overshoot the target, at least 1 of the groups
        // won't be able to fulfil the condition and thus it's not possible
        if (weights[n-1] > target) goto no;
        // Initialize brute force search
        // Assume the largest weight is always taken taken to halve the search
        // space (the cases in which the elements are in the opposite group)
        stack[0].pos = n-2;
        stack[0].current = weights[n-1];
        i = 0;
        // DFS through all possible combinations of weights taken
        while (1) {
            // If the current weight is the target, it's possible and we can
            // stop the search
            if (stack[i].current == target) {
                putchar_unlocked('S');
                putchar_unlocked('I');
                goto end;
            };
            // If we have already surpased the target value or made a choice for
            // all weights, this path doesn't lead to a solution. Pop the
            // current state and continue with the next
            if (stack[i].current > target || stack[i].pos == -1) {
                --i;
                if (i < 0) break;
                continue;
            };
            // Pop the current state since it has already been processed
            int pos = stack[i].pos;
            int curr = stack[i].current;
            // Push the successor states to the stack: the next weight can
            // either be taken or not. Push the take choice second so it's
            // processed earlier as it's more likely to reach an end earlier
            stack[i].pos = pos - 1;
            stack[i].current = curr;
            stack[++i].pos = pos - 1;
            stack[i].current = curr + weights[pos];
        }
    no:
        putchar_unlocked('N');
        putchar_unlocked('O');
    end:
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
