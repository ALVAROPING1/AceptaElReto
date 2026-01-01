#include <stdio.h>

// Max value (+1 since it's an inclusive range)
#define MAX 1000 + 1

// Modulo used for output
const int mod = 1000000007;

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
}

// ╔═══════════════════════════════════════════════════════════════════════════╗
// ║                       Dynamic programming solution                        ║
// ╚═══════════════════════════════════════════════════════════════════════════╝

// Calculates each binomial coefficient mod P using pascal's theorem

inline void solve1() {
    // Dynamic programming table
    // binomial[n][k] = (n choose k) mod P
    int binomial[MAX][MAX] = {{0}};

    // Precompute all binomial coefficients
    int i, j;
    // Base cases
    binomial[0][0] = 1;
    for (i = 1; i < MAX; ++i) {
        binomial[i][0] = 1;
        binomial[i][i] = 1;
    }
    // Recursive cases using pascal's theorem
    for (i = 1; i < MAX; ++i) {
        for (j = 1; j < i; ++j) {
            binomial[i][j] =
                (binomial[i - 1][j - 1] + binomial[i - 1][j]) % mod;
        }
    }

    // Read first line
    int n, k;
    fastscan(&n);
    fastscan(&k);
    while (n != 0 || k != 0) { // While there are lines to read
        // Print the result and read the next line
        fastprint(binomial[n][k]);
        putchar_unlocked('\n');
        fastscan(&n);
        fastscan(&k);
    }
}

// ╔═══════════════════════════════════════════════════════════════════════════╗
// ║                            Factorial solution                             ║
// ╚═══════════════════════════════════════════════════════════════════════════╝

// Calculates each binomial coefficient mod P using Fermat's little theorem
// Source:
// https://usaco.guide/gold/combo?lang=cpp#solution---binomial-coefficients

// Cache for the factorial of each number and its modular inverse
// fac[x] = x! mod P
int fac[MAX];
// fac[x] = (x!)⁻¹ mod P
int inv[MAX];

// Binary exponentiation modulo M
inline int exponential(long long x, long long n, long long m) {
    x %= m; // note: m * m must be less than 2^63 to avoid long long overflow
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

// Calculates the factorial up to MAX
inline void factorial() {
    fac[0] = 1;
    int i;
    for (i = 1; i < MAX; i++) {
        fac[i] = ((long long)fac[i - 1]) * i % mod;
    }
}

// Calculates the inverse of the factorial up to MAX
inline void inverses() {
    // Base case
    // According to Fermat's little theorem:
    // a^p = a (mod p) => a^(p-1) = 1 (mod p) => a * a^(p-2) = 1 (mod p)
    // => a⁻¹ = a^(p-2) (mod p)
    // (x!)⁻¹ = (x!)^(p-2) (mod p)
    inv[MAX - 1] = exponential(fac[MAX - 1], mod - 2, mod);
    int i;
    // Recursive case
    for (i = MAX - 1; i > 0; i--) {
        // ((n-1)!)⁻¹ = ((n-1)!)⁻¹ * 1
        //            = ((n-1)!)⁻¹ * n⁻¹ * n
        //            = ((n-1)! * n)⁻¹ * n
        //            = (n!)⁻¹ * n (mod p)
        inv[i - 1] = ((long long)inv[i]) * i % mod;
    }
}

inline int binomial_coefficient(int n, int k) {
    return ((long long)fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

inline void precompute() {
    factorial();
    inverses();
}

inline void query(int n, int k) {
    if (k > n) putchar_unlocked('0');
    else fastprint(binomial_coefficient(n, k));
}

inline void solve2() {
    precompute();
    // Read first line
    int n, k;
    fastscan(&n);
    fastscan(&k);
    while (n != 0 || k != 0) { // While there are lines to read
        // Print the result and read the next line
        query(n, k);
        putchar_unlocked('\n');
        fastscan(&n);
        fastscan(&k);
    }
}

int main() {
    solve2();
    return 0;
}
