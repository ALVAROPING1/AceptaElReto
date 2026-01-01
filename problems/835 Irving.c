#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

inline bool fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    while (c < '0')
        c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return c == '\n';
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

typedef struct {
    int size, y;
} Segment;

#define COND_NEG(cond, x) dir == cond? x : -x;

// Parse the next segment from the input
inline bool next(Segment* curr) {
    char dir = getchar_unlocked();
    if (dir == EOF) exit(0);
    int size;
    bool last;
    if (dir >= 'a') {
        // Lowercase letter -> single tile movement
        size = 1;
        last = getchar_unlocked() == '\n';
    } else {
        // Uppercase letter -> multiple tile movement
        dir += 'a' - 'A';
        getchar_unlocked();
        last = fastscan(&size);
    }
    // Update the segment with the parsed data
    switch (dir) {
    case 'n':
    case 's':
        curr->size = 0;
        curr->y += COND_NEG('n', size);
        break;
    case 'e':
    case 'o':
        curr->size = COND_NEG('e', size);
        break;
    }
    return last;
}

// Calculates the area of the polygon
inline int area() {
    int res = 0;
    bool last;
    Segment curr = {0, 0};
    do {
        last = next(&curr);
        // Add the contribution of the current segment to the total signed area
        // NOTE: segments are axis aligned, so we can use the area of rectangles
        // between the segment and x axis instead of trapezoids
        res += curr.size * curr.y;
    } while (!last);
    return abs(res);
}

int main() {
    while (1)
        fastprint(area());
    return 0;
}
