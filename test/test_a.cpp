#include "gtest/gtest.h"

#include <vector>
#include <tuple>
#include <unordered_set>

// Include the header file where your functions are declared
// #include "your_header_file.h"

// Example function declarations (replace with actual ones)
std::unordered_set<float> get_payments_diff_set(const std::vector<float>& payments);
int type_of_user(const std::unordered_set<float>& payments_diff_set, const std::vector<float>& payments);
int calculate_m(const std::unordered_set<float>& payments_diff_set, const std::vector<float>& payments);
std::tuple<float, int, int> calculate_interest_rate_period(const int allowed_years, const std::vector<float>& debt, const std::vector<float>& payments);

using namespace std;
TEST(CalculateInterestRatePeriodTest, Test1) {
    constexpr int allowed_years = 1;
    const std::vector<float> debt = {1000, 950.0, 897.5, 842.375};
    const std::vector<float> payments = {0, 100, 100, 100};
    auto [interest_rate, client_type, remaining_payments] = calculate_interest_rate_period(allowed_years, debt, payments);
    EXPECT_NEAR(interest_rate, 0.05, 1e-3);
    EXPECT_EQ(client_type, 0);
    EXPECT_EQ(remaining_payments, 11);
}

TEST(CalculateInterestRatePeriodTest, Test2) {
    constexpr int allowed_years = 1;
    const vector<float> debt = {1000, 950.0, 897.5, 742.375, 579.49375};
    const vector<float> payments = {0, 100, 100, 200, 200};
    auto [interest_rate, client_type, remaining_payments] = calculate_interest_rate_period(allowed_years, debt, payments);
    EXPECT_NEAR(interest_rate, 0.05, 1e-3);
    EXPECT_EQ(client_type, 2);
    EXPECT_EQ(remaining_payments, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}