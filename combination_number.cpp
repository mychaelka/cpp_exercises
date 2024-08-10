#include <cassert>
#include <cstdint>
#include <algorithm>


auto comb(auto n, auto k) {
    /*n! / ((n-k)! * k!) */

    assert(n >= k);

    decltype(n) result = 1;
    decltype(n) nom = n, denom = 1;

    /* Cyklus provedeme pro ‹nom_f› v klesajícím rozsahu ⟦⟨n, k)⟧
     * resp. ⟦⟨n, n - k)⟧, podle toho která spodní mez je větší.
     * Protože jednotlivé mezihodnoty na spodní hranici iterace
     * nezávisí, je jistě výhodnější provést méně iterací. */

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

int main()
{
    assert(comb(1, 1) == 1);
    assert(comb(2, 1) == 2);
    assert(comb(4, 1) == 4);
    assert(comb(4, 2) == 6);
    assert(comb(4, 3) == 4);
    assert(comb(5, 2) == 10);

    for (std::int64_t i = 1; i < 60; ++i)
        for (std::int64_t k = 1; k < i; ++k)
            assert(comb(i + 1, k + 1) ==
                comb(i, k) + comb(i, k + 1));

    return 0;
}