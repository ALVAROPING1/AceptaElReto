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
    while (n--) {}
    return 0;
}

int solve2() { // Caso marca final
    int a, b;
    cin >> a >> b;
    while (a != 0 && b != 0) {
        int min, max;
        min = a + 74 * b;
        max = a + 79 * b;
        cout << "[" << min << " .. " << max << "]\n";
        cin >> a >> b;
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
