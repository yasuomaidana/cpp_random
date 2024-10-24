#include <iostream>
#include <vector>
#include "lib/calculate_interest.cpp"
using namespace std;

int main()
{
    // const vector<float> debt = {1000, 950.0, 897.5, 842.375};
    // const vector<float> payments = {0, 100, 100, 200, 200};
    // constexpr int allowed_years = 1;
    // auto [interest_rate, client_type, remaining_payments] = calculate_interest_rate_period(
    //     allowed_years, debt, payments);
    //
    // cout << "(" << interest_rate <<", "<<client_type<<", "<< remaining_payments <<")"<< endl;

    // Unit Test 1 Input:
    const int allowed_years_1 = 1;
    const vector<float> debt_1 = {1000, 950.0, 897.5, 842.375};
    const vector<float> payments_1 = {0, 100, 100, 100};
    auto [interest_rate_1, client_type_1, remaining_payments_1] = calculate_interest_rate_period(
        allowed_years_1, debt_1, payments_1);
    cout << "Unit Test 1 Output: result = (" << interest_rate_1 << ", " << client_type_1 << ", " << remaining_payments_1 << ")" << endl;

    // Unit Test 2 Input:
    const int allowed_years_2 = 1;
    const vector<float> debt_2 = {1000, 950.0, 897.5, 742.375, 579.49375};
    const vector<float> payments_2 = {0, 100, 100, 200, 200};
    auto [interest_rate_2, client_type_2, remaining_payments_2] = calculate_interest_rate_period(
        allowed_years_2, debt_2, payments_2);
    cout << "Unit Test 2 Output: result = (" << interest_rate_2 << ", " << client_type_2 << ", " << remaining_payments_2 << ")" << endl;

    // Unit Test 3 Input:
    const int allowed_years_3 = 1;
    const vector<float> debt_3 = {1000, 975.0, 923.75, 849.9375};
    const vector<float> payments_3 = {0, 75, 100, 120};
    auto [interest_rate_3, client_type_3, remaining_payments_3] = calculate_interest_rate_period(
        allowed_years_3, debt_3, payments_3);
    cout << "Unit Test 3 Output: result = (" << interest_rate_3 << ", " << client_type_3 << ", " << remaining_payments_3 << ")" << endl;

    // Unit Test 4 Input:
    const int allowed_years_4 = 1;
    const vector<float> debt_4 = {1000, 975.0, 923.75, 939.9375};
    const vector<float> payments_4 = {0, 75, 100, 30};
    auto [interest_rate_4, client_type_4, remaining_payments_4] = calculate_interest_rate_period(
        allowed_years_4, debt_4, payments_4);
    cout << "Unit Test 4 Output: result = (" << interest_rate_4 << ", " << client_type_4 << ", " << remaining_payments_4 << ")" << endl;

    return 0;
}
