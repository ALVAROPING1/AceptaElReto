#include <bits/stdc++.h>
#include <utility>
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
    int frames, copias;
    cin >> frames >> copias;
    while (frames != 0 && copias != 0) {
        vector<pair<int, int>> v;
        for (int i = 0; i < copias; ++i) {
            int k;
            cin >> k;
            while (k--) {
                int min, max;
                cin >> min;
                cin.ignore(1, ',');
                cin >> max;
                v.push_back(make_pair(min, max));
            }
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; } );
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
            cout << "NO\n";
        } else {
            cout << "SI\n";
        }
        cin >> frames >> copias;
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
