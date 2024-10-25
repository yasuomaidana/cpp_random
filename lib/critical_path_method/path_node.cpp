//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#include "path_node.h"

PathNode::
PathNode(string task_name, const int duration) :
    task_name(move(task_name)),
    duration(duration),
    forward(0),
    backward(0)
{
}

void PathNode::add_successor(PathNode& successor)
{
    this->successors.push_back(&successor);
}

void PathNode::add_predecessor(PathNode& predecessor)
{
    this->predecessors.push_back(&predecessor);
}

bool PathNode::operator<(const PathNode& other) const
{
    return duration < other.duration;
}
