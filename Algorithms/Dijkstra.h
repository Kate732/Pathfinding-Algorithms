#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;
using Pair = pair<int, string>; //this is an alias for easier reading when inisializing the pair

class Dijkstra {
public:

    //constructor that accepts and saves the graph
    Dijkstra(const unordered_map<string, unordered_map<string, int>>& graph) : graph(graph) {}

    // Function to find the shortest path using Dijkstra's Algorithm
    void FindShortestPath(const string& start, const string& destination);

private:
    unordered_map<string, unordered_map<string, int>> graph;
};

#endif




/*

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
using Pair = pair<int, string>; //to use the priority list

class Dijkstra {
public:
    // Constructor of the class that accepts the graph
    Dijkstra(const unordered_map<string, unordered_map<string, int>>& graph) : graph(graph) {}

    void FindShortestPath(const string& start, const string& destination);

private:
    unordered_map<string, unordered_map<string, int>> graph;
};

*/