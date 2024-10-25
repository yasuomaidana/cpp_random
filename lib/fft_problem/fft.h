//
// Created by Yasuo Ignacio Maidana Pérez on 25/10/24.
//

#ifndef FFT_H
#define FFT_H

#include <complex>
#include <vector>
#include <cmath>

using namespace std;

vector<complex<double>> fft(vector<std::complex<double>>& A, complex<double> omega);
vector<complex<double>> fft_real(const vector<double>& data);

#endif //FFT_H
