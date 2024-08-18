#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <random>

std::vector<int> digits(int n, int base)
{
    std::vector<int> result = {};
    
    while (n > 0) {
        result.push_back(n % base);
        n /= base;
    }

    std::reverse(result.begin(), result.end());

    return result;
}


std::vector<int>::iterator bsearch(std::vector<int> &vec, int val)
{
    auto begin = vec.begin();
    auto end = vec.end();

    while (begin < end) {
        auto mid = begin + (end - begin) / 2;
        
        if (*mid == val) {
            return mid;
        }

        if (*mid > val) {
            end = mid;
        }

        if (*mid < val) {
            begin = mid + 1;
        }
    }

    return vec.end();

}


int partition(std::vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);  // put pivot in the right place
    return i + 1;
}


void quicksort_help(std::vector<int> &vec, int low, int high) 
{
    if (vec.size() <= 1) {
        return;
    }

    if (low < high) {
        int pi = partition(vec, low, high);

        quicksort_help(vec, low, pi - 1);
        quicksort_help(vec, pi + 1, high);
    }
}


void quicksort(std::vector<int> &vec)
{
    quicksort_help(vec, 0, vec.size() - 1);
}


int main()
{
    std::vector<int> d10_1337 = { 1, 3, 3, 7 },
                       d10_123  = { 1, 2, 3 },
                       d7_1234  = { 3, 4, 1, 2 },
                       d2_9     = { 1, 0, 0, 1 };

    std::vector<int> vect = digits(1337,10);
    for (int elem : vect) {
        std::cout << elem << std::endl;
    }
    assert(digits(1337, 10) == d10_1337);
    assert(digits(123, 10) == d10_123);
    assert(digits(1234, 7) == d7_1234);
    assert(digits(9, 2) == d2_9);

    /*Binary search*/
    using vec = std::vector< int >;
    vec a{ 1, 2, 3, 4, 5 }, b{ 1, 2, 3, 4 }, c{ 1, 3, 7, 9, 51 };

    assert( bsearch( a, 1 ) == std::next( a.begin(), 0 ) );
    assert( bsearch( a, 2 ) == std::next( a.begin(), 1 ) );
    assert( bsearch( a, 3 ) == std::next( a.begin(), 2 ) );
    assert( bsearch( a, 4 ) == std::next( a.begin(), 3 ) );
    assert( bsearch( a, 5 ) == std::next( a.begin(), 4 ) );
    assert( bsearch( a, 0 ) == a.end() );
    assert( bsearch( a, 6 ) == a.end() );

    assert( bsearch( b, 1 ) == std::next( b.begin(), 0 ) );
    assert( bsearch( b, 2 ) == std::next( b.begin(), 1 ) );
    assert( bsearch( b, 3 ) == std::next( b.begin(), 2 ) );
    assert( bsearch( b, 4 ) == std::next( b.begin(), 3 ) );
    assert( bsearch( b, 0 ) == b.end() );
    assert( bsearch( b, 5 ) == b.end() );

    assert( bsearch( c, 1 )  == std::next( c.begin(), 0 ) );
    assert( bsearch( c, 2 )  == c.end() );
    assert( bsearch( c, 3 )  == std::next( c.begin(), 1 ) );
    assert( bsearch( c, 4 )  == c.end() );
    assert( bsearch( c, 5 )  == c.end() );
    assert( bsearch( c, 7 )  == std::next( c.begin(), 2 ) );
    assert( bsearch( c, 9 )  == std::next( c.begin(), 3 ) );
    assert( bsearch( c, 11)  == c.end() );
    assert( bsearch( c, 51 ) == std::next( c.begin(), 4 ) );
    assert( bsearch( c, 0 )  == c.end() );

    std::vector< int >
        aa{ 1, 2 },
        bb{ 2, 1 },
        cc{ 3, 2, 4, 1 },
        dd{ 3, 3, 1, 1, 2 },
        ee{ 1, 2, 3, 4, 6, 5, 7, -7, 1, 3, 1, 4, 5, 0, 9, -1, 0 };

    quicksort(aa);
    quicksort(bb);

    assert(std::is_sorted(aa.begin(), aa.end()));
    assert(std::is_sorted(bb.begin(), bb.end()));

    std::mt19937 rand;

    for (int i = 0; i < 100; ++ i)
    {
        quicksort(cc);
        quicksort(dd);
        quicksort(ee);

        assert(std::is_sorted(cc.begin(), cc.end()));
        assert(std::is_sorted(dd.begin(), dd.end()));
        assert(std::is_sorted(ee.begin(), ee.end()));

        std::shuffle(cc.begin(), cc.end(), rand);
        std::shuffle(dd.begin(), dd.end(), rand);
        std::shuffle(ee.begin(), ee.end(), rand);
    }

    return 0;
}
