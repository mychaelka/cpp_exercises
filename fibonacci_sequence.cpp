#include <cassert>
#include <vector>
#include <iostream>

std::vector<int> fib_sequence(int n) {
    std::vector<int> result;
    result.resize(n, 1);

    for (int i = 2; i <= n; i++) {

        result[i] = result[i - 1] + result[i - 2];
    }

    return result;
}

int main() {
    std::vector<int> empty;
    std::vector seq1{1};
    std::vector seq2{1, 1};
    std::vector seq3{1, 1, 2};
    std::vector seq4{1, 1, 2, 3};
    std::vector seq7{ 1, 1, 2, 3, 5, 8, 13 };

    assert(fib_sequence(0) == empty);
    assert(fib_sequence(1) == seq1);
    assert(fib_sequence(2) == seq2);
    assert(fib_sequence(3) == seq3);
    assert(fib_sequence(4) == seq4);
    assert(fib_sequence(7) == seq7);
}