//
// Created by Damian Kurpiewski on 04.07.2017.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/// Incidence list of the weighted graph
vector<vector<pair<int, int> > > graph;

/// Distance to each node from starting node
vector<int> distances;

/// Prepares example graph adding vertices to incidence list
void prepare_example_graph() {
    graph = vector<vector<pair<int, int> > >(7);
    graph[0].push_back(make_pair(1, 5));
    graph[0].push_back(make_pair(6, 5));

    graph[1].push_back(make_pair(0, 5));
    graph[1].push_back(make_pair(6, 5));
    graph[1].push_back(make_pair(3, 3));
    graph[1].push_back(make_pair(2, 3));

    graph[2].push_back(make_pair(1, 3));
    graph[2].push_back(make_pair(3, 1));

    graph[3].push_back(make_pair(2, 1));
    graph[3].push_back(make_pair(1, 3));
    graph[3].push_back(make_pair(6, 3));
    graph[3].push_back(make_pair(4, 5));
    graph[3].push_back(make_pair(5, 4));

    graph[4].push_back(make_pair(3, 5));
    graph[4].push_back(make_pair(5, 2));

    graph[5].push_back(make_pair(4, 2));
    graph[5].push_back(make_pair(3, 4));
    graph[5].push_back(make_pair(6, 5));

    graph[6].push_back(make_pair(0, 5));
    graph[6].push_back(make_pair(1, 5));
    graph[6].push_back(make_pair(3, 3));
    graph[6].push_back(make_pair(5, 5));
}

/// Iterative bfs algorithm
/// \param node - starting node to visit
void dijkstra(int node) {
    queue<pair<int, pair<int, int> > > nodes;

    distances = vector<int>(graph.size(), INT_MAX);
    distances[0] = 0;

    for (int i = 0; i < graph[0].size(); i++) {
        nodes.push(make_pair(graph[0][i].second, make_pair(0, graph[0][i].first)));
    }

    while (!nodes.empty()) {
        int distance;
        int from_node;
        int new_distance;
        node = nodes.front().second.second;
        distance = nodes.front().first;
        from_node = nodes.front().second.first;

        nodes.pop();

        new_distance = distances[from_node] + distance;

        if (new_distance >= distances[node]) {
            continue;
        }

        distances[node] = new_distance;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            distance = graph[node][i].second;
            nodes.push(make_pair(distance, make_pair(node, next_node)));
        }
    }
}

int main() {

    prepare_example_graph();

    dijkstra(0);

    for (int i = 0; i < distances.size(); i++) {
        cout << distances[i] << " ";
    }

    cout << endl;

    return 0;
}