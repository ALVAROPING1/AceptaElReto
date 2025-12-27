#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool fastscan_check(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

const float EPSILON = 0.01F;

float distance(float x, int L, int p_x, int p_y) {
    float cosx = cos(x);
    return -cosx * p_y - sin(-x) * (L * cosx - p_x);
}

// Find maximum of unimodal function f() within [l, r].
// To find the minimum, reverse the if/else statement or reverse the comparison.
float ternary_search(float l, float r, int L, int p_x, int p_y) {
    while (r-l > EPSILON) {
        float third = (r - l) / 3;
        float m1 = l + third;
        float m2 = r - third;
        float d1 = distance(m1, L, p_x, p_y);
        float d2 = distance(m2, L, p_x, p_y);
        if (d1 < d2) l = m1;
        else r = m2;
    }
    return (l+r)/2;
}

int main() {
    int piane_W, piane_L, corridor_1, corridor_2;
    while (fastscan_check(&piane_W)) {
        fastscan(&piane_L);
        fastscan(&corridor_1);
        fastscan(&corridor_2);
        if (piane_W > piane_L) {
            int temp = piane_L;
            piane_L = piane_W;
            piane_W = temp;
        }
        if (piane_W > corridor_1 || piane_W > corridor_2) {
            putchar_unlocked('N');
            putchar_unlocked('O');
        } else {
            float m = ternary_search( 0, M_PI / 2, piane_L, corridor_2, corridor_1);
            if (distance(m, piane_L, corridor_2, corridor_1) < -piane_W) {
                putchar_unlocked('S');
                putchar_unlocked('I');
            } else {
                putchar_unlocked('N');
                putchar_unlocked('O');
            }
        }
        putchar_unlocked('\n');
    }
    return 0;
}
