#include <iostream>
#include <unordered_map>
#include "Dijkstra.h"
#include "AStar.h"

using namespace std;

int main() {

    string start = "A";
    string destination = "F";

    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 10}, {"D", 12}, {"G", 11}, {"H", 4}}},
        {"B", {{"A", 10}, {"D", 8}, {"H", 20}}},
        {"C", {{"D", 17}, {"E", 8}, {"G", 13}, {"H", 10}}},
        {"D", {{"A", 12}, {"B", 8}, {"C", 17}, {"F", 16}, {"G", 24}, {"H", 14}}},
        {"E", {{"C", 8}, {"F", 8}, {"G", 11}, {"H", 5}}},
        {"F", {{"D", 16}, {"E", 8}, {"G", 18}, {"H", 21}}},
        {"G", {{"A", 11}, {"C", 13}, {"D", 24}, {"E", 11}, {"F", 18}, {"H", 30}}},
        {"H", {{"A", 4}, {"B", 20}, {"C", 10}, {"D", 14}, {"E", 5}, {"F", 21}, {"G", 30}}}
    };

    // new Dijkstra object that took the graph in
    Dijkstra dijkstra(graph);

    // Call the function in Dijkstra's class that finds and prints the shortest path it found
    dijkstra.FindShortestPath(start, destination);

    //same with A*
    AStar aStar(graph);

    aStar.FindShortestPath(start, destination);

    return 0;
}
