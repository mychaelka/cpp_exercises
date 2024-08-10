#include <cassert>

int fibonacci(int n) {
    int a = 1, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}

int main() {

    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(7) == 13);
    assert(fibonacci(10) == 55);
    assert(fibonacci(15) == 610);
    assert(fibonacci(20) == 6765);
}