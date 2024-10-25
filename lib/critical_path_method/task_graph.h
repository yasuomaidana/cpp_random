//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#ifndef TASK_GRAPH_H
#define TASK_GRAPH_H

#include "path_node.h"
#include <vector>

using namespace std;

class TaskGraph
{
    vector<PathNode> nodes;
    vector<vector<int>> dependencies;

    vector<PathNode> roots;

public:
    TaskGraph(const vector<tuple<string, int>>& tasks_durations, const vector<vector<int>>& dependencies);
    void calculate_forward();
    void calculate_backward();
    void calculate_critical_path();
    int calculate_duration();
    vector<PathNode> get_roots();

};


#endif //TASK_GRAPH_H
