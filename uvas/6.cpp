#include <bits/stdc++.h>
// clang-format off
using namespace std;
using ll = long long;
template<typename T> struct Point { T x, y; };
const struct Point<int> dir4[]{ { 1,  0}, { 0,  1}, {-1,  0}, { 0, -1} };
const struct Point<int> dir8[]{ { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, {-1,  0}, {-1, -1}, { 0, -1}, { 1, -1} };
inline char lowercase(char c) { return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c; }
template<typename T> inline int gcd(T a, T b) {
    T min, max;
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    while (1) {
        T res = max % min;
        if (res == 0) return min;
        max = min;
        min = res;
    }
}
template<typename T> inline int lcm(T a, T b) { return a * b / gcd(a, b); }
inline vector<bool> primes(const int n) {
    vector<bool> nums(n, true); nums[0] = false; nums[1] = false;
    for (int i = 2; i*i < n; ++i) if (nums[i])
        for (int j = i*i; j < n; j += i) nums[j] = false;
    return nums;
}
template<typename T, typename U> inline U sum(vector<T> nums) {
    U res = 0;
    for (auto x: nums) res += x;
    return res;
}
template<typename T, typename U> inline U mul(vector<T> nums) {
    U res = 1;
    for (auto x: nums) res *= x;
    return res;
}
// clang-format on

int solve1() { // Num casos
    int n;
    cin >> n;
    while (n--) {
        // Codigo
    }
    return 0;
}

int solve2() { // Caso marca final
    int n;
    cin >> n;
    while (n != 0) {
        int timbal[600000];
        for (int i = 0; i < n*2; i += 2) {
            cin >> timbal[i];
            cin >> timbal[i+1];
        }
        int current;
        int res = 0;
        int i = 0;
        cin >> current;
        while (current != 0) {
            if (i >= n*2) {
                cin >> current;
                ++res;
                continue;
            }
            if (current >= timbal[i] && current <= timbal[i+1]) {
                cin >> current;
                continue;
            }
            if (i+2 >= n*2 || current < timbal[i+2]) {
                cin >> current;
                ++res;
                continue;
            }
            i += 2;
        }
        cout << res << "\n";
        cin >> n;
    }
    return 0;
}

int solve3() { // Fin entrada
    int a;
    cin >> a;
    while (cin) {
        // Code
        cin >> a;
    }
    return 0;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return solve2();
}
