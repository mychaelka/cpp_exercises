#include <vector>
#include <cassert>
#include <iostream>


auto accumulate(auto f, const std::vector<int> vec)
{
    decltype(f(vec[0])) result = 0; 

    for (int elem : vec) {
        result += f(elem);
    }

    return result;
}

int main()
{
    auto f = [](int x) {return x * x;};
    auto g = [](int x) {return x / 2;};
    auto h = [](int x) {return x;};

    std::vector vec{1, 2, 3, 4};

    std::cout << accumulate(f, vec) << std::endl;

    assert(accumulate(f, vec) == 30);
    assert(accumulate(g, vec) ==  4);
    assert(accumulate(h, vec) == 10);

    return 0;
}