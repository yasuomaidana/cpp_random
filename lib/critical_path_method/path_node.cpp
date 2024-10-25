//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "path_node.h"

PathNode::
PathNode(const string& task_name, const int duration) :
    task_name(task_name),
    duration(duration)
{
}

void PathNode::add_successor(PathNode& successor)
{
    this->successors.push_back(successor);
}

void PathNode::add_predecessor(PathNode& predecessor)
{
    this->predecessors.push_back(predecessor);
}

bool PathNode::operator<(const PathNode& other) const
{
    return duration < other.duration;
}

bool PathNode::operator>(const PathNode& other) const
{
    return duration > other.duration;
}
