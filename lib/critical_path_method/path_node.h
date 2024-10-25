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
public:
    PathNode(const string& task_name, int duration);

    void add_successor(PathNode& successor);
    void add_predecessor(PathNode& predecessor);
    bool operator<(const PathNode& other) const;
    bool operator>(const PathNode& other) const;

    vector<reference_wrapper<PathNode>> successors;
    vector<reference_wrapper<PathNode>> predecessors;
    string task_name;
    int duration;
    int forward = 0;
    int backward = 0;
};


#endif //PATH_NODE_H
