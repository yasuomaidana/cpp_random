//
// Created by Yasuo Ignacio Maidana Pérez on 25/10/24.
//

#include "sales_analyzer.h"

array<int,2> product_magnitude_frequency(const vector<complex<double>>& fft_result)
{
    constexpr double f_s = 1.0 / 86400; // Sampling frequency in Hz (1/day)
    const size_t n = fft_result.size();

    vector<double> frequencies(n);
    for (size_t i = 0; i < n; ++i)
    {
        frequencies[i] = static_cast<double>(i) * f_s / n;
    }

    double average_sales_per_day = sqrt(fft_result[0].real()); // DC component
    int fundamental_index = 1; // Start from 1 to skip DC

    for (size_t i = 2; i < n / 2; ++i)
    {
        // Only search up to n/2 (Nyquist)
        if (abs(fft_result[i].real()) > abs(fft_result[fundamental_index].real()))
        {
            fundamental_index = i;
        }
    }

    const double product_frequency = frequencies[fundamental_index];
    const double product_sale_amplitude = sqrt(fft_result[fundamental_index].real());

    const int product_frequency_in_days = static_cast<int>(1.0 / product_frequency / 3600.0 / 24.0);

    const int product_sales = static_cast<int>(product_sale_amplitude) + static_cast<int>(average_sales_per_day);
    return {product_sales, product_frequency_in_days};
}
