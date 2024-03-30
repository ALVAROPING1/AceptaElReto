#include <bits/stdc++.h>

int gcd(int a, int b) {
    int min, max;
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    while (true) {
        int res = max % min;
        if (res == 0) { return min; }

        max = min;
        min = res;
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while (n > 0) {
        int res, curr;
        std::cin >> res;
        while (--n) {
            std::cin >> curr;
            res = lcm(res, curr);
        }
        std::cout << res << '\n';
        std::cin >> n;
    }
    return 0;
}
