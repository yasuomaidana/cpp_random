//
// Created by Yasuo Ignacio Maidana Pérez on 25/10/24.
//

#ifndef SALES_ANALYZER_H
#define SALES_ANALYZER_H

#include "fft.h"
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

array<int,2> product_magnitude_frequency(const vector<complex<double>>& fft_result);
vector<tuple<string,array<int,3>>> sales_analyzer(const vector<vector<double>>& sales_data, const vector<string>& products);
array<int,3> frequency_formatter(int frequency);
#endif //SALES_ANALYZER_H
