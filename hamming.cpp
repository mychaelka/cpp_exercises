#include <string>
#include <cctype>
#include <cassert>

int hamming(const std::string &a, const std::string &b) {

    /*Check that both strings are of the same length*/
    assert(a.size() == b.size());

    int hamming_distance = 0;

    for (size_t i = 0; i <= a.size(); i++) {
        if (std::tolower(a[i]) != std::tolower(b[i])) {
            hamming_distance += 1;
        }
    }

    return hamming_distance;
}


int main() {
    assert(hamming("Python", "python") == 0);
    assert(hamming("AbCd", "aBcD") == 0);
    assert(hamming("string", "string") == 0);
    assert(hamming("aabcd", "abbcd") == 1);
    assert(hamming("abcd", "ghef") == 4);
    assert(hamming("Abcd", "bbcd") == 1);
    assert(hamming("gHefgh", "ghefkl") == 2);
}