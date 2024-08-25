#include <vector>
#include <cassert>


void fibonacci(std::vector<int> &v, int n)
{ /* 1 1 2 3 5 8 13 ...*/
    v.clear();

    if (n >= 1) {
        v.push_back(1);
        if (n >= 2) {
            v.push_back(1);
        }
    }

    for (int i = 2; i < n; i++) {
        v.push_back(v[i-1] + v[i-2]);
    }
}

int main()
{
    std::vector<int> fib, expect{ 1, 1, 2, 3, 5 };

    fibonacci(fib, 5);
    assert(fib == expect);

    fibonacci(fib, 6);
    expect.push_back(8);
    assert(fib == expect);

    fib = std::vector<int>{4, 5};
    fibonacci(fib, 6);
    assert(fib == expect);

    expect.clear();
    expect.push_back(1);
    fibonacci(fib, 1);
    assert(fib == expect);

    expect.push_back(1);
    fibonacci(fib, 2);
    assert(fib == expect);

    return 0;
}
