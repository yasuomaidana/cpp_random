#ifndef CALCULATE_INTEREST_H
#define CALCULATE_INTEREST_H

#include <vector>
#include <unordered_set>
#include <tuple>
using namespace std;

/**
 * @brief Computes the set of differences between consecutive payments.
 *
 * @param payments A vector of payment amounts.
 * @return An unordered set of differences between consecutive payments.
 */
unordered_set<float> get_payments_diff_set(const std::vector<float>& payments);

/**
 * @brief Determines the type of user based on the payment differences.
 *
 * @param payments_diff_set A set of differences between consecutive payments.
 * @param payments A vector of payment amounts.
 * @return An integer representing the type of user.
 */
int type_of_user(const std::unordered_set<float>& payments_diff_set, const std::vector<float>& payments);

/**
 * @brief Calculates the value of m based on the payment differences.
 *
 * @param payments_diff_set A set of differences between consecutive payments.
 * @param payments A vector of payment amounts.
 * @return An integer representing the value of m.
 */
int calculate_m(const std::unordered_set<float>& payments_diff_set, const std::vector<float>& payments);

/**
 * @brief Calculates the interest rate period based on the allowed years, debt, and payments.
 *
 * @param allowed_years The number of years allowed for the interest rate period.
 * @param debt A vector of debt amounts.
 * @param payments A vector of payment amounts.
 * @return A tuple containing the interest rate, client type, and remaining payments.
 */
tuple<float, int, int> calculate_interest_rate_period(int allowed_years, const std::vector<float>& debt, const std::vector<float>& payments);

#endif // CALCULATE_INTEREST_H