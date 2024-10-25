//
// Created by Yasuo Ignacio Maidana Pérez on 24/10/24.
//

#ifndef PATH_NODE_H
#define PATH_NODE_H
#include <string>
#include <vector>

using namespace std;


class PathNode
{
    string task_name;
    int duration;
    int forward;
    int backward;

public:
    PathNode(string task_name, int duration);

    void add_successor(PathNode& successor);
    void add_predecessor(PathNode& predecessor);
    bool operator<(const PathNode& other) const;

    vector<PathNode*> successors;
    vector<PathNode*> predecessors;
};


#endif //PATH_NODE_H
