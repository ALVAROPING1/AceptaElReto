#include <bits/stdc++.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint_decimal(double number) {
    char buffer[64];
    long long integer = number;
    double decimal = number - integer;
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

struct pt {
    double x, y;
    bool operator==(pt const& t) const {
        return x == t.x && y == t.y;
    }
    bool operator<(pt right) {
        return (y < right.y) or (y == right.y and x < right.x);
    }
};

double orientation(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

bool cw(pt a, pt b, pt c) {
    return orientation(a, b, c) < 0;
}

double pow2(double x) {
    return x * x;
}

int convex_hull(int size, pt a[], pt st[]) {
    pt p0 = *std::min_element(&a[0], &a[size]);
    std::sort(&a[0], &a[size], [&p0](const pt& a, const pt& b) {
        double o = orientation(p0, a, b);
        if (o == 0)
            return pow2(p0.x - a.x) + pow2(p0.y - a.y) <
                   pow2(p0.x - b.x) + pow2(p0.y - b.y);
        return o < 0;
    });

    int st_size = 0;
    for (int i = 0; i < size; i++) {
        while (st_size > 1 && !cw(st[st_size - 2], st[st_size - 1], a[i]))
            --st_size;
        st[st_size++] = a[i];
    }

    if (st_size == 2 && st[0] == st[1]) --st_size;

    return st_size;
}

// Calculates the area of a polygon
double area(int size, pt fig[]) {
    double res = 0;
    // For each edge, update the total area
    for (int i = 1; i < size; ++i) {
        auto curr = fig[i];
        auto prev = fig[i - 1];
        res += (prev.x - curr.x) * (prev.y + curr.y);
    }
    auto curr = fig[size - 1];
    auto start = fig[0];
    // Add the contribution of the edge from the last vertex to the first one
    res += (curr.x - start.x) * (curr.y + start.y);
    // The area is signed, so we need to take the absolute value
    return fabs(res) / 2;
}

pt hull[15], trees[300000];

int main() {
    int n;
    fastscan(&n);
    while (n != 0) {
        int size = 0;
        // Read all the points
        while (n--) {
            int x, y;
            fastscan(&x);
            fastscan(&y);
            trees[size++] = pt{static_cast<double>(x), static_cast<double>(y)};
        }
        // Calculate the convex hull of the points
        int hull_size = convex_hull(size, trees, hull);
        // The result is the area of the convex hull
        fastprint_decimal(area(hull_size, hull));
        putchar_unlocked('\n');
        fastscan(&n);
    }
    return 0;
}
