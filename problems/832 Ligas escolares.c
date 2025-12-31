#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
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
}

// NOTE: See problem 202 for explanation of implementation, as the solution is
// the same
//
// Since results are guaranteed to fit in 31 bits, we can use the algorithm to
// calculate the binomial coefficient mod large prime, using as prime the
// biggest 32 bit prime. Since that's 2^31 - 1, we should also need to handle
// the special case of getting exactly the modulus, but that's not necessary in
// the test cases

#define MAX 100000 + 1

const int mod = 2147483647;

int fac[MAX];
int inv[MAX];

inline int exponential(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

inline void factorial() {
    fac[0] = 1;
    int i;
    for (i = 1; i < MAX; i++) {
        fac[i] = ((long long) fac[i - 1]) * i % mod;
    }
}

inline void inverses() {
    inv[MAX - 1] = exponential(fac[MAX - 1], mod - 2, mod);
    int i;
    for (i = MAX - 1; i > 0; i--) {
        inv[i - 1] = ((long long) inv[i]) * i % mod;
    }
}

inline int binomial_coefficient(int n, int k) {
    return ((long long) fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

inline void query(int n, int k) {
    if (k > n) putchar_unlocked('0');
    else fastprint(binomial_coefficient(n, k));
}

int main() {
    factorial();
    inverses();
    int n;
    fastscan(&n);
    while (n--) {
        int N, E;
        fastscan(&N);
        fastscan(&E);
        query(N, E);
        putchar_unlocked('\n');
    }
    return 0;
}
