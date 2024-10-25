//
// Created by Yasuo Ignacio Maidana Pérez on 25/10/24.
//

#ifndef SALES_ANALYZER_H
#define SALES_ANALYZER_H

#include "fft.h"
using namespace std;

array<int,2> product_magnitude_frequency(const vector<complex<double>>& fft_result);

#endif //SALES_ANALYZER_H
