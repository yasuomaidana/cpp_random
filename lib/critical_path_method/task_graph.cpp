//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "task_graph.h"

#include <iostream>

TaskGraph::TaskGraph(const vector<tuple<string, int>>& tasks_durations, const vector<vector<int>>& dependencies)
{
    this->dependencies = dependencies;
    for (auto& task_duration : tasks_durations)
    {
        nodes.emplace_back(get<0>(task_duration), get<1>(task_duration));
    }
    for (int i = 0; i < dependencies.size(); i++)
    {
        for (int j = 0; j < dependencies[i].size(); j++)
        {
            if (dependencies[i][j] == 1)
            {
                nodes[i].add_successor(nodes[j]);
                nodes[j].add_predecessor(nodes[i]);
            }
        }
    }
}

void TaskGraph::calculate_forward()
{
    auto roots = get_roots();

    // priority_queue<PathNode, vector<PathNode>, greater<PathNode>> expand_forward;
    stack<PathNode> expand_forward;
    for (auto& root : roots)
    {
        root.forward = root.duration;
        expand_forward.push(root);
    }

    while (!expand_forward.empty())
    {
        auto current = expand_forward.top();
        expand_forward.pop();
        for (auto& successor : current.successors)
        {
            successor->forward = max(successor->forward, current.forward + successor->duration);
            expand_forward.push(*successor);
        }
    }
}

vector<PathNode> TaskGraph::get_roots()
{
    if (roots.empty())
    {
        copy_if(nodes.begin(), nodes.end(), back_inserter(roots),
             [](const PathNode& node)
             {
                 return node.predecessors.empty();
             });
    }
    return roots;
}

vector<PathNode> TaskGraph::get_leaves()
{
    vector<PathNode> leaves;
    copy_if(nodes.begin(), nodes.end(), back_inserter(leaves),
         [](const PathNode& node)
         {
             return node.successors.empty();
         });
    return leaves;
}
