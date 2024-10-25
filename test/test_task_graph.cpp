//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "gtest/gtest.h"


#include <vector>
#include <tuple>
#include <unordered_set>

#include "../lib/critical_path_method/task_graph.h"

using namespace std;

void format_output(TaskGraph graph)
{
    auto critical_path = graph.calculate_critical_path();

    for (const auto& node : critical_path)
    {
        cout << node.task_name << " ";
    }
    cout << endl;

    cout << "Days: " << critical_path.back().forward << endl;
}

void print2DArray(const vector<vector<int>>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < arr[i].size(); ++j) {
            cout << arr[i][j];
            if (j < arr[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void printTasks(const vector<tuple<string, int>>& tasks) {
    cout << "[";
    for (size_t i = 0; i < tasks.size(); ++i) {
        // cout << "('" << get(tasks[i]) << "', " << get(tasks[i]) << ")";
        cout <<"('" << get<0>(tasks[i]) << "'," << get<1>(tasks[i])<< ")";
        if (i < tasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
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
    TaskGraph graph(tasks, dependencies);
    const auto roots = graph.get_roots();
    EXPECT_EQ(roots.size(), 2);
    const auto leaves = graph.get_leaves();

    // graph.calculate_forward();
    // graph.calculate_backward();
    // format_output(graph);
    const auto result = graph.result();
    printTasks(tasks);
    print2DArray(dependencies);
    cout << get<0>(result) << " " << get<1>(result) << endl;
    EXPECT_EQ(leaves.size(), 1);
    EXPECT_EQ(1, 1);
}
