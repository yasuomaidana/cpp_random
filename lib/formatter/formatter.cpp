#include <iostream>
#include <vector>
//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//
using namespace std;
template<typename T>
void print2DArray(const vector<vector<T>>& arr) {
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

template<typename T1, typename T2>
void print_list_tuple(const vector<tuple<T1, T2>>& tasks) {
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