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
        root->forward = root->duration;
        expand_forward.push(*root);
    }

    while (!expand_forward.empty())
    {
        auto current = expand_forward.top();
        expand_forward.pop();
        for (auto& successor : current.successors)
        {
            successor.get().forward = max(successor.get().forward, current.forward + successor.get().duration);
            expand_forward.push(successor);
        }
    }
}

void TaskGraph::calculate_backward()
{
    auto leaves = get_leaves();
    stack<PathNode> expand_backward;
    for (auto& leaf : leaves)
    {
        leaf->backward = leaf->forward - leaf->duration;
        expand_backward.push(*leaf);
    }
    while (!expand_backward.empty())
    {
        auto current = expand_backward.top();
        expand_backward.pop();
        for (auto& predecessor : current.predecessors)
        {
            int late_finish = current.backward;
            for (auto& successor : predecessor.get().successors)
            {
                late_finish = min(late_finish, successor.get().backward);
            }

            predecessor.get().backward = late_finish - predecessor.get().duration;
            expand_backward.push(predecessor);
        }
    }
}

string TaskGraph::calculate_critical_path()
{
    const auto roots = get_roots();
    PathNode critical_node = *roots[0];
    string critical_path;
    for (const auto& root : roots)
    {
        if (root->backward == 0)
        {
            critical_node = *root;
            break;
        }
    }
    critical_path += critical_node.task_name;
    stack<PathNode> expand_backward;
    expand_backward.push(critical_node);
    while (!expand_backward.empty())
    {
        auto current = expand_backward.top();
        expand_backward.pop();
        for (auto& predecessor : current.successors)
        {
            if (predecessor.get().backward == current.forward)
            {
                critical_path += "->" + predecessor.get().task_name;
                expand_backward.push(predecessor);
            }
        }
    }
    return critical_path;
}

vector<PathNode*> TaskGraph::get_roots()
{
    vector<PathNode*> roots;
    for (auto& node : nodes)
    {
        if (node.predecessors.empty())
        {
            roots.push_back(&node);
        }
    }

    return roots;
}

vector<PathNode*> TaskGraph::get_leaves()
{
    vector<PathNode*> leaves;
    for (auto& node : nodes)
    {
        if (node.successors.empty())
        {
            leaves.push_back(&node);
        }
    }
    return leaves;
}
