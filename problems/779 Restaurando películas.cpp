#include <bits/stdc++.h>
#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; c >= '0'; c = getchar_unlocked())
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

using Interval = std::pair<int, int>;

int main() {
    int frames, copies;
    fastscan(&frames);
    fastscan(&copies);
    while (frames != 0 && copies != 0) {
        std::vector<Interval> v;
        while (copies--) {
            int k;
            fastscan(&k);
            while (k--) {
                int min, max;
                fastscan(&min);
                fastscan(&max);
                v.push_back(std::make_pair(min, max));
            }
        }
        std::sort(v.begin(), v.end(), [](Interval a, Interval b){ return a.first < b.first; } );
        int start = 1;
        int end = frames;
        for (auto intv : v) {
            if (intv.first > start) {
                break;
            }
            if (intv.second >= end) {
                start = end + 1;
                break;
            }
            if (intv.second >= start) {
                start = intv.second + 1;
            }
        }
        if (start <= end) {
            putchar_unlocked('N');
            putchar_unlocked('O');
        } else {
            putchar_unlocked('S');
            putchar_unlocked('I');
        }
        putchar_unlocked('\n');
        fastscan(&frames);
        fastscan(&copies);
    }
    return 0;
}
