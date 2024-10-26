//
// Created by Yasuo Ignacio Maidana Pérez on 25/10/24.
//

#include "sales_analyzer.h"

array<int, 2> product_magnitude_frequency(const vector<complex<double>>& fft_result)
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

vector<tuple<string,array<int,3>>> sales_analyzer(const vector<vector<double>>& sales_data,
                                                           const vector<string>& products)
{
    vector<array<int, 2>> product_analysis;
    vector<tuple<string, array<int, 3>>> result{};
    constexpr int frequency_limit = 365;
    for (const auto& product : sales_data)
    {
        auto fft_result = fft_real(product);
        product_analysis.push_back(product_magnitude_frequency(fft_result));
    }
    int max_product_sales_index = -1;
    int max_product_sales = 0;
    int fastest_product_index = -1;
    int fastest_product = frequency_limit;
    int i = 0;
    for (const auto& product_result : product_analysis)
    {
        if (product_result[1] < frequency_limit)
        {
            if (product_result[0] > max_product_sales)
            {
                max_product_sales_index = i;
                max_product_sales = product_result[0];
            }
            if (product_result[1] < fastest_product)
            {
                fastest_product_index = i;
                fastest_product = product_result[1];
            }
        }
        i++;
    }
    if (max_product_sales_index != -1)
    {
        result.push_back({
            products[max_product_sales_index], frequency_formatter(product_analysis[max_product_sales_index][1])
        });
    }
    if (fastest_product_index != -1 && fastest_product_index != max_product_sales_index)
    {
        result.push_back({
            products[fastest_product_index], frequency_formatter(product_analysis[fastest_product_index][1])
        });
    }

    return result;
}

array<int, 3> frequency_formatter(const int frequency)
{
    const int months = frequency / 30;
    const int weeks = (frequency - months * 30) / 7;
    const int days = frequency - months * 30 - weeks * 7;

    return {months, weeks, days};
}
