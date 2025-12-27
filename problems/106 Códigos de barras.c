#include <stdbool.h>
#include <stdio.h>

#define MAX 14

inline int read_line(char buf[]) {
    register int i = 0;
    do {
        buf[i] = getchar_unlocked();
    } while (buf[i++] != '\n');
    return i - 1;
}

int main() {
    char line[MAX];

    int n = read_line(line);
    while (n != 1 || line[0] != '0') {
        int acc = 0;
        int i = n - 1;
        int odd = false;
        do {
            acc = (acc + (line[i] - '0') * (odd ? 3 : 1)) % 10;
            odd = !odd;
        } while (i--);
        if (acc != 0) {
            putchar_unlocked('N');
            putchar_unlocked('O');
        } else {
            putchar_unlocked('S');
            putchar_unlocked('I');
            if (n > 8) {
                putchar_unlocked(' ');
                const char* country = "Desconocido";
                if (n < 13 || line[0] == '0') country = "EEUU";
                else if (line[0] == '3') {
                    if (line[1] == '8' && line[2] == '0') country = "Bulgaria";
                } else if (line[0] == '5') {
                    if (line[1] == '0') country = "Inglaterra";
                    else if (line[1] == '3' && line[2] == '9')
                        country = "Irlanda";
                    else if (line[1] == '6' && line[2] == '0')
                        country = "Portugal";
                } else if (line[0] == '7') {
                    if (line[1] == '0') country = "Noruega";
                    else if (line[1] == '5' && line[2] == '9')
                        country = "Venezuela";
                } else if (line[0] == '8' && line[2] == '0') {
                    if (line[1] == '5') country = "Cuba";
                    else if (line[1] == '9') country = "India";
                }
                int i = 0;
                do {
                    putchar_unlocked(country[i++]);
                } while (country[i] != '\0');
            }
        }
        putchar_unlocked('\n');
        n = read_line(line);
    }
    return 0;
}
