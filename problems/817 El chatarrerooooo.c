#include <math.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint_decimal(float number) {
    char buffer[16];
    int integer = number;
    float decimal = number - integer;
    register int i = -1;
    do {
        buffer[++i] = (integer % 10) + '0';
        integer /= 10;
    } while (integer);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    if (decimal == 0) return;
    putchar_unlocked('.');
    sprintf(buffer, "%g", decimal);
    i = 2;
    do {
        putchar_unlocked(buffer[i]);
    } while (buffer[++i] != '\0');
}

typedef struct Point {
    int x, y;
} Point;

// Calculates the area of a polygon
float area() {
    // Read the amount of vertices
    int size;
    fastscan(&size);
    // Read the first vertex
    Point start;
    fastscan(&start.x);
    fastscan(&start.y);
    // Initialize sliding window
    Point prev = start, curr;
    --size;
    float res = 0;
    // For each edge, update the total area
    while (size--) {
        fastscan(&curr.x);
        fastscan(&curr.y);
        res += (prev.x - curr.x) * (prev.y + curr.y);
        prev = curr;
    }
    // Add the contribution of the edge from the last vertex to the first one
    res += (curr.x - start.x) * (curr.y + start.y);
    // The area is signed, so we need to take the absolute value
    return fabs(res);
}

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        float res = 0;
        // For each piece, calculate its area and add the results
        while (n--)
            res += area();
        fastprint_decimal(res / 2);
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
