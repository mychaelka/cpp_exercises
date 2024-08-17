#include <cassert>
#include <string>
#include <vector>
#include <iostream>

bool is_palindrome(const std::string &s) 
{
    size_t length = s.length();
    for (size_t i = 0; i < length / 2; i++) {
        if (s[i] != s[length - i - 1]) {
            return false;
        }
    }
    return true;
}


int comb(int n, int k) {
    /*n! / ((n-k)! * k!) */

    assert(n >= k);

    int result = 1;
    int nom = n, denom = 1;

    while (nom > std::max(k, n - k))
    {
        assert(denom <= std::min(k, n - k));

        result *= nom;
        assert(result % denom == 0);
        result /= denom;

        --nom;
        ++denom;
    }

    return result;
}


std::vector<int> pascal(int n)
{
    std::vector<int> result = {};

    for (int i = 0; i <= n; i++)
    {
        result.push_back(comb(n, i));
    }

    return result;
}


int main()
{
    assert(is_palindrome("abba"));
    assert(is_palindrome("abcba"));
    assert(is_palindrome("abbabba"));
    assert(is_palindrome("abcdcba"));
    assert(!is_palindrome("abbas"));
    assert(!is_palindrome("abbaa"));
    assert(is_palindrome(""));
    assert(!is_palindrome("ab"));
    assert(is_palindrome("a"));

    std::vector<int> pascal0 = {1};
    std::vector<int> pascal1 = {1, 1};
    std::vector<int> pascal5 = {1, 5, 10, 10, 5, 1};
    std::vector<int> pascal7 = {1, 7, 21, 35, 35, 21, 7, 1};

    assert(pascal(0) == pascal0);
    assert(pascal(1) == pascal1);
    assert(pascal(5) == pascal5);
    assert(pascal(7) == pascal7);
}