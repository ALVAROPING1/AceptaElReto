#include <bits/stdc++.h>

// Max amount of identifiers
const int MAX_IDS = 1000;
// Max length of identifiers (+1 for the null terminator)
const int MAX_LEN = 51;

// Converts a word to lower case while copying it
void lowercase(char word[], char lower[]) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] >= 'A' and word[i] <= 'Z') lower[i] = word[i] - 'A' + 'a';
        else lower[i] = word[i];
        ++i;
    }
    lower[i] = '\0';
}

// Copies the upper cases of src to dest
template <typename T> void copycase(T dest, T src) {
    int i = 0;
    while (dest[i] != '\0') {
        dest[i] = std::min(dest[i], src[i]);
        ++i;
    }
}

struct Pair {
    char lower[MAX_LEN]{0};
    char correct[MAX_LEN]{0};
};

int main() {
    // Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Pair> words;
    std::vector<Pair*> ids;
    words.reserve(MAX_IDS);
    ids.reserve(MAX_IDS);

    int n;
    std::cin >> n;
    std::cin.ignore();
    while (std::cin) {
        // For each identifier
        while (n--) {
            Pair curr{};
            // Get the identifier and convert it to lower case
            std::cin.getline(curr.correct, MAX_LEN);
            lowercase(curr.correct, curr.lower);
            // Check of the identifier has already been found
            auto res = std::find_if(words.begin(), words.end(), [&](Pair x) {
                return strcmp(x.lower, curr.lower) == 0;
            });
            // If it hasn't, add it to the list of found identifiers
            if (res == words.end()) {
                words.push_back(curr);
                // If it has, copy the upper case letters to the previous
                // instance
            } else {
                copycase(res->correct, curr.correct);
            }
            // Add the identifier to the list of identifiers to print at the end
            ids.push_back(&*res);
        }
        // Print all identifiers with the correct case
        for (auto word : ids) {
            std::cout << word->correct << "\n";
        }
        std::cout << "---\n";
        // Reset the words and ids buffers
        words.clear();
        ids.clear();
        std::cin >> n;
        std::cin.ignore();
    }
    return 0;
}
