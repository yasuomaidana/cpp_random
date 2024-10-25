//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "gtest/gtest.h"


#include <vector>
#include <tuple>
#include <unordered_set>

#include "../lib/critical_path_method/task_graph.h"

using namespace std;

// Include the header file where your functions are declared
TEST(TEST_GET_PATH, Test1)
{
    // Example function declarations (replace with actual ones)
    // std::unordered_set<float> get_payments_diff_set(const std::vector<float>& payments);
    // int type_of_user(const std::unordered_set<float>& payments_diff_set, const std::vector<float>& payments);
    // int calculate_m(const std::unordered_set<float>& payments_diff_set, const std::vector<float>& payments);
    // std::tuple<float, int, int> calculate_interest_rate_period(const int allowed_years, const std::vector<float>& debt, const std::vector<float>& payments);
    const vector<tuple<string, int>> tasks = {
        make_tuple("A", 10),
        make_tuple("B", 12),
        make_tuple("C", 5),
        make_tuple("D", 3),
        make_tuple("E", 2),
        make_tuple("F", 3),
        make_tuple("G", 15),
        make_tuple("H", 17),
    };
    const vector<vector<int>> dependencies = {
        // a  b  c  d  e  f  g  h
        {0, 1, 1, 0, 0, 0, 0, 0}, //a
        {0, 0, 0, 1, 0, 0, 0, 0}, //b
        {0, 0, 0, 1, 0, 1, 0, 0}, //c
        {0, 0, 0, 0, 1, 0, 0, 0}, //d
        {0, 0, 0, 0, 0, 0, 1, 0}, //e
        {0, 0, 0, 0, 0, 0, 1, 0}, //f
        {0, 0, 0, 0, 0, 0, 0, 0}, //g
        {0, 0, 0, 0, 0, 1, 0, 0}  //h
    };
    TaskGraph graph(tasks, dependencies);
    const auto roots = graph.get_roots();
    EXPECT_EQ(roots.size(), 2);
    const auto leaves = graph.get_leaves();

    graph.calculate_forward();
    EXPECT_EQ(leaves.size(), 1);
    EXPECT_EQ(1, 1);
}
