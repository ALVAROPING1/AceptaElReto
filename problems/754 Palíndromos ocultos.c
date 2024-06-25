#include "string.h"
#include <stdio.h>

int main() {
    int counts[256];
    register int c;
    // While there are lines to read
    while ((c = getchar_unlocked()) != -1) {
        memset(&counts['a'], 0, 26 * sizeof(counts[0]));
        // We already read the first character
        int length = 1;
        ++counts[c];
        // Count the amount of occurrences of each character
        while ((c = getchar_unlocked()) != '\n') {
            ++counts[c];
            ++length;
        }
        int i, j;
        // Get the character that will go in the center of the word (if it has
        // an odd length)
        int center = -1;
        for (i = 'a'; i <= 'z'; ++i) {
            // If the amount of occurrences of this character is odd, it could
            // go in the center
            if (counts[i] % 2 == 1) {
                // If the length of the word is even it can't have a center, and
                // if a center character has already been found there can't be
                // another
                if (length % 2 == 0 || center != -1) {
                    putchar_unlocked('N');
                    putchar_unlocked('O');
                    putchar_unlocked(' ');
                    putchar_unlocked('H');
                    putchar_unlocked('A');
                    putchar_unlocked('Y');
                    goto end;
                }
                // Store the center character
                center = i;
                --counts[i];
            }
        }
        // Print half of the occurrences of each character in lexicografical
        // order
        for (i = 'a'; i <= 'z'; ++i) {
            for (j = 0; j < counts[i] / 2; ++j)
                putchar_unlocked(i);
            counts[i] /= 2;
        }
        // If there is a center character, print it
        if (center != -1) putchar_unlocked(center);
        // Print the second half of the occurrences of each character in reverse
        // lexicografical to ensure the word is a palindrome
        while (--i >= 'a')
            for (j = 0; j < counts[i]; ++j)
                putchar_unlocked(i);
    end:
        putchar_unlocked('\n');
    }
    return 0;
}
