#include "AStar.h"

void AStar::FindShortestPath(const string& start, const string& destination) {
    //priority queue to have the points with the smallest f-score
    priority_queue<APair, vector<APair>, greater<APair>> openSet;

    //points that were already been calculated
    unordered_set<string> closedSet;

    //sometimes heuristic function can return not only whole numbers, that's why we contain double
    //destination from start to current node
    unordered_map<string, double> gScore;

    //calculated total cost from start to destination through current node
    unordered_map<string, double> fScore;

    //map to store the previous node
    unordered_map<string, string> previousPoint;

    for (const auto& node : graph) { //for loop to run through a map
        gScore[node.first] = numeric_limits<double>::infinity(); //set the distance of all nodes to infinity
        fScore[node.first] = numeric_limits<double>::infinity();
    }
    gScore[start] = 0; //set start to 0
    fScore[start] = heuristic(start, destination, gScore);

    openSet.push({ fScore[start], start });

    while (!openSet.empty()) {
        APair topElement = openSet.top();
        double current_fScore = topElement.first;
        string currentNode = topElement.second;
        openSet.pop();

        if (currentNode == destination) { //if we reached the destination then we need to do path reconstruction
            vector<string> path;
            string current = destination;
            while (current != start) {
                path.push_back(current);
                current = previousPoint[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            for (const string& node : path) {
                cout << node << " ";
            }
            cout << endl;
            cout << "Total distance: " << current_fScore << endl;
            return;
        }

        closedSet.insert(currentNode);

        for (const auto& neighbor : graph[currentNode]) {
            const string& neighborNode = neighbor.first;
            int weight = neighbor.second;
            double possible_gScore = gScore[currentNode] + weight; //potential g-score if it will be smaller the previous

            if (closedSet.find(neighborNode) != closedSet.end())
                continue; //it means the shortest path to this point has been already found, so skip this interaction

            if (possible_gScore < gScore[neighborNode]) {
                previousPoint[neighborNode] = currentNode;
                gScore[neighborNode] = possible_gScore;
                fScore[neighborNode] = gScore[neighborNode] + heuristic(neighborNode, destination, gScore);
                openSet.push({ fScore[neighborNode], neighborNode });
            }
        }
    }

    cout << "There is no path between " << start << " and " << destination << endl; //if no path was found
}

double AStar::heuristic(const string& from, const string& to, unordered_map<string, double> gScore) {
    double d = abs(gScore[from] - gScore[to]); //this could be potentially Manhattan distance
    return d;
    //when this function returns 0, this algorithm does the same as Dijkstra's
    //return 0;
}
