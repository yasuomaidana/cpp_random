//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "gtest/gtest.h"


#include <vector>
#include <tuple>
#include <unordered_set>

#include "../lib/critical_path_method/task_graph.h"
#include "../lib/formatter/formatter.cpp"

using namespace std;




tuple<string, int> format_output(vector<tuple<string, int>> tasks, const vector<vector<int>> dependencies, int test_i)
{
    cout << "Unit Test  " << test_i << " Input:"<<endl;
    TaskGraph graph(tasks, dependencies);
    cout << "task_durations = ";
    print_list_tuple(tasks);

    cout << "dependencies = ";
    print2DArray(dependencies);

    graph.calculate_forward();
    graph.calculate_backward();
    auto critical_path = graph.calculate_critical_path();

    auto result = graph.result();
    cout << "sequence = " << get<0>(result) << endl;
    cout << "duration = " << get<1>(result) << endl;
    cout << endl;
    return result;
}

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
        {0, 0, 0, 0, 0, 1, 0, 0} //h
    };
    tuple<string, int> result = format_output(tasks, dependencies, 1);

    string expected_result = "A -> B -> D -> E -> G";
    int expected_duration = 7;
    EXPECT_EQ(get<0>(result), expected_result);
    EXPECT_EQ(get<1>(result), expected_duration);
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}