#include <math.h>
#include <stdbool.h>
#include <stdio.h>

inline bool fastscan(long long* number) {
    *number = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return false;
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
    return true;
}

// The light is on iff the amount of divisors of the number is odd
// To not get a TLE, the key is that the amount of divisors of a number is odd
// iff it's a perfect square. Proof:
//
// The divisors of a number are any subset of its prime decomposition
// If N = p^a q^b ... r^c => each prime can be chosen up to its exponent + 1
// times => the amount of divisors is (a+1) (b+1) ... (c+1)
// That product is odd <=> all terms are odd
//                     <=> all exponents are even
//                     <=> the primes can be split in 2 equal groups
//                     <=> the number is a perfect square

inline bool is_perfect_square(long long n) {
    long long x = sqrt(n);
    return x * x == n;
}

int main() {
    long long n;
    while (fastscan(&n)) {
        if (is_perfect_square(n)) {
            putchar_unlocked('E');
            putchar_unlocked('N');
            putchar_unlocked('C');
            putchar_unlocked('E');
            putchar_unlocked('N');
            putchar_unlocked('D');
            putchar_unlocked('I');
            putchar_unlocked('D');
            putchar_unlocked('A');
            putchar_unlocked('\n');
        } else {
            putchar_unlocked('A');
            putchar_unlocked('P');
            putchar_unlocked('A');
            putchar_unlocked('G');
            putchar_unlocked('A');
            putchar_unlocked('D');
            putchar_unlocked('A');
            putchar_unlocked('\n');
        }
    }
    return 0;
}
