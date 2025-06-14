#include <stdio.h>
#include <string.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastscan_line(char line[]) {
    // Keep on extracting characters if they aren't the line terminator
    register int i = 0;
    register int c = getchar_unlocked();
    if (c == EOF) return;
    for (; c != '\n'; c = getchar_unlocked())
        line[i++] = c;
    line[i] = '\0';
}

inline void fastprint_word(char line[], int start, int end) {
    do {
        putchar_unlocked(line[start]);
    } while (++start != end);
}

typedef struct Word {
    char initial, final;
    char inner[26];
    int pos, end;
} Word;

inline int parse_word(char line[], int pos, Word* word) {
    word->final = 0;
    memset(word->inner, 0, 26);
    int start = pos;
    char c = line[pos];
    word->initial = c;
    word->pos = start;
    ++pos;
    if (line[pos] != ' ') {
        while (line[pos + 1] != ' ') {
            c = line[pos];
            ++word->inner[c - 'a'];
            ++pos;
        }
        word->final = line[pos++];
    }
    word->end = pos;
    return pos + 1;
}

inline Word* find_word(int words, Word dict[], Word* word) {
    Word* res = NULL;
    int i;
    for (i = 0; i < words; ++i) {
        Word* dict_word = &dict[i];
        if (dict_word->initial == word->initial &&
            dict_word->final == word->final &&
            memcmp(dict_word->inner, word->inner, 26) == 0) {
            if (res == NULL) res = &dict[i];
            else return NULL;
        }
    }
    return res;
}

#define MAX_WORDS 200
#define MAX MAX_WORDS * 15 + 2

int main() {
    int n;
    fastscan(&n);
    char line_dict[MAX];
    char line[MAX];
    Word dictionary[MAX_WORDS];
    while (n--) {
        // Parse dictionary words
        fastscan_line(line_dict);
        int words = 0, pos = 0;
        while (line_dict[pos] != '.')
            pos = parse_word(line_dict, pos, &dictionary[words++]);
        // Process text words
        fastscan_line(line);
        pos = 0;
        while (line[pos] != '.') {
            Word word;
            pos = parse_word(line, pos, &word);
            Word* dict_word = find_word(words, dictionary, &word);
            if (dict_word == NULL) fastprint_word(line, word.pos, word.end);
            else fastprint_word(line_dict, dict_word->pos, dict_word->end);
            putchar_unlocked(' ');
        }
        putchar_unlocked('.');
        putchar_unlocked('\n');
    }
    return 0;
}
