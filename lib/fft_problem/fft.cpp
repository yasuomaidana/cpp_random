//
// Created by Yasuo Ignacio Maidana Pérez on 25/10/24.
//

#include "fft.h"

vector<complex<double>> fft(vector<complex<double>>& A, const complex<double> omega)
{
    const size_t n = A.size();

    // Base case
    if (n == 1)
    {
        return A;
    }

    vector<complex<double>> twiddle(n / 2);
    for (size_t j = 0; j < n / 2; ++j) {
        twiddle[j] = pow(omega, j);
    }


    // Split into even and odd sub-arrays
    vector<complex<double>> A_even(n / 2), A_odd(n / 2);
    for (size_t i = 0; i < n / 2; ++i)
    {
        A_even[i] = A[2 * i];
        A_odd[i] = A[2 * i + 1];
    }

    // Recursive calls
    const vector<complex<double>> F_even = fft(A_even, omega * omega);
    const vector<complex<double>> F_odd = fft(A_odd, omega * omega);

    // Combine results
    vector<complex<double>> F(n);
    for (size_t j = 0; j < n / 2; ++j)
    {
        F[j] = F_even[j] + twiddle[j] * F_odd[j];
        F[j + n / 2] = F_even[j] - twiddle[j] * F_odd[j];
    }

    return F;
}

vector<complex<double>> fft_real(const vector<double>& data)
{
    const size_t n = data.size();

    // Convert real data to complex
    vector<complex<double>> A(n);
    for (size_t i = 0; i < n; ++i) {
        A[i] = complex<double>(data[i], 0.0);
    }

    // Calculate the nth root of unity
    const complex<double> omega = polar(1.0, 2.0 * M_PI / n);

    // Compute the FFT
    return fft(A, omega);
}
