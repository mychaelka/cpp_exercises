#include <cmath>
#include <cassert>


auto newton = [](auto f, auto df, double ini, double prec)
{
    double x = ini, y = ini - f(x) / df(x);

    while (std::fabs(y - x) >= prec)
    {
        x = y;
        y = y - f(x) / df(x);
    }

    return y;
};


double sqrt(double x, double prec)
{
    return newton([=](double z) {return z * z - x;},
                  [=](double z) {return 2 * z;}, 1, prec);
}

double cbrt(double n, double prec)
{
    return newton([=](double z) {return z * z * z - n;},
                  [=](double z) {return 3 * z * z;}, 1, prec);
}


double root(int n, double x, double prec)
{
    auto  f = [=](double z) {return std::pow(z, n) - x;};
    auto df = [=](double z) {return n * std::pow(z, n - 1);};
    return newton(f, df, 1, prec);
}


auto taylor = [](auto coeff, double x, double prec)
{
    double r = 0, pow = 1, fact = 1;
    int i = 0;

    while (pow / fact > prec / 10)
    {
        r += coeff(i) * pow / fact;
        fact *= ++i;
        pow *= x;
    }

    return r;
};


auto trig_coeff(int a, int b, int c, int d)
{
    return [=](int i) {return i % 4 == 0 ? a : i % 4 == 1 ? b :
                                 i % 4 == 2 ? c : d;};
}


double sine(double x, double prec)
{
    return taylor(trig_coeff(0, 1, 0, -1), x, prec);
}

double cosine(double x, double prec)
{
    return taylor(trig_coeff(1, 0, -1, 0), x, prec);
}


double pi(double prec)
{
    auto  f = [=](double x) {return cosine(x, prec);};
    auto df = [=](double x) {return -sine(x, prec);};
    return 2 * newton(f, df, 1, prec);
}

int main()
{
    for (int decimals = 1; decimals < 10; ++ decimals)
    {
        double p = std::pow(10, -decimals);

        assert(std::fabs(sqrt(2, p) - std::sqrt(2)) < p);
        assert(std::fabs(cbrt(2, p) - std::cbrt(2)) < p);

        assert(std::fabs(root(2, 2, p) - std::sqrt(2)) < p);
        assert(std::fabs(root(3, 2, p) - std::cbrt(2)) < p);
        assert(std::fabs(root(4, 16, p) - 2) < p);

        assert(std::fabs(pi(p) - 4 * std::atan(1)) < p);
    }
}
