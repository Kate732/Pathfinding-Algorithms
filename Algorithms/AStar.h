#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using APair = pair<double, string>;

class AStar {
public:
    //constructor that accepts and saves the graph
    AStar(const unordered_map<string, unordered_map<string, int>>& graph) : graph(graph) {}
    void FindShortestPath(const string& start, const string& destination);

private:
    unordered_map<string, unordered_map<string, int>> graph;
    double heuristic(const string& from, const string& to, unordered_map<string, double> gScore); //heuristic function
};

#endif
