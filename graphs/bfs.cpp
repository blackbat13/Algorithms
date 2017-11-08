//
// Created by Damian Kurpiewski on 04.07.2017.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// Incidence list of the graph
vector<vector<int> > graph;

/// True if node was visited, false otherwise
vector<bool> visited;

/// Prepares example graph adding vertices to incidence list
void prepare_example_graph() {
    graph = vector<vector<int> >(7);
    graph[0].push_back(1);
    graph[0].push_back(6);

    graph[1].push_back(0);
    graph[1].push_back(6);
    graph[1].push_back(3);
    graph[1].push_back(2);

    graph[2].push_back(1);
    graph[2].push_back(3);

    graph[3].push_back(2);
    graph[3].push_back(1);
    graph[3].push_back(6);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(4);
    graph[5].push_back(3);
    graph[5].push_back(6);

    graph[6].push_back(0);
    graph[6].push_back(1);
    graph[6].push_back(3);
    graph[6].push_back(5);
}

/// Iterative bfs algorithm
/// \param node - starting node to visit
void bfs(int node) {
    queue<int> nodes;

    nodes.push(node);

    while (!nodes.empty()) {
        node = nodes.front();
        nodes.pop();
        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        cout << "Visited node: " << node << endl;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            if (!visited[next_node]) {
                nodes.push(next_node);
            }
        }
    }
}

int main() {

    prepare_example_graph();
    visited = vector<bool>(graph.size(), false);

    bfs(0);

    return 0;
}