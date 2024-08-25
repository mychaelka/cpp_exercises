#include <vector>
#include <cmath>
#include <cassert>

void stats(const std::vector<double> &data,
            double &median, double &mean, double &stddev)
{
    int n = data.size();
    double sum = 0, square_error_sum = 0;

    for (double x_i : data)
        sum += x_i;

    mean = sum / n;

    if (n % 2 == 1)
        median = data[n / 2];
    else
        median = (data[n / 2] + data[n / 2 - 1]) / 2;

    for (double x_i : data)
        square_error_sum += (x_i - mean) * (x_i - mean);

    double variance = square_error_sum/(n - 1);
    stddev = std::sqrt(variance);
}

int main() /* demo */
{
    double median, mean, stddev;
    std::vector< double > sample = {2, 4, 4, 4, 5, 5, 5, 7, 9};
    stats(sample, median, mean, stddev);

    assert(mean == 5);
    assert(median == 5);
    assert(stddev == 2);

    sample.push_back(1100);
    stats(sample, median, mean, stddev);

    assert(median == 5);
    assert(mean > 100);
    assert(stddev > 100);
}
