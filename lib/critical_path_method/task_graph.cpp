//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "task_graph.h"

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
