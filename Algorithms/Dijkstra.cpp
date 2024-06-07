#include "Dijkstra.h"

void Dijkstra::FindShortestPath(const string& start, const string& destination) {
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;
    for (const auto& node : graph) { //for loop to run through a map
        distances[node.first] = INT_MAX; //set the distance of all nodes to infinity
    }
    distances[start] = 0; //set start to 0

    //priority queue to select the node with the smallest distance
    //it stores points in vector of Pairs and sort them (greater<Pair>) so the smallest values are on top
    priority_queue<Pair, vector<Pair>, greater<Pair>> priorityQueue;
    priorityQueue.push({ 0, start });

    while (!priorityQueue.empty()) {
        Pair current = priorityQueue.top(); //saves current node
        priorityQueue.pop(); //deletes it from queue
        int currentDistance = current.first; 
        string currentNode = current.second;

        if (currentNode == destination) { //if we reached the destination then we need to do path reconstruction
            vector<string> path;
            //move back one point at a time, checking if it's not empty
            for (string current = destination; !current.empty(); current = previous[current]) {
                path.push_back(current); //add it to the path
            }
            reverse(path.begin(), path.end()); //reverse the vector to get it in the right order
            for (const string& node : path) {
                cout << node << " "; //print it out
            }
            cout << endl;
            cout << "Total distance: " << currentDistance << endl;
            return; //exits the function
        }

        for (const auto& neighbor : graph[currentNode]) { //runing through all next points
            const string& neighborNode = neighbor.first;
            int weight = neighbor.second; //save the cost to nex node
            int distance = currentDistance + weight; //total distance

            if (distance < distances[neighborNode]) { //if it found smaller distance -> overwrite it with the new one
                distances[neighborNode] = distance;
                previous[neighborNode] = currentNode; //move to the next point
                priorityQueue.push({ distance, neighborNode });
            }
        }
    }

    cout << "There is no path between " << start << " and " << destination << endl; //if no path was found
}
