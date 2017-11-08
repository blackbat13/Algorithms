//
// Created by Damian Kurpiewski on 06.07.2017.
//

#include <iostream>
#include <vector>

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
//    graph[3].push_back(4);
    graph[3].push_back(5);

//    graph[4].push_back(3);
//    graph[4].push_back(5);

//    graph[5].push_back(4);
    graph[5].push_back(3);
    graph[5].push_back(6);

    graph[6].push_back(0);
    graph[6].push_back(1);
    graph[6].push_back(3);
    graph[6].push_back(5);
}

/// Recursive dfs algorithm
/// \param node - current node to visit
void dfs(int node) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];
        if (!visited[next_node]) {
            dfs(next_node);
        }
    }
}

int count_connected_components() {
    int result = 0;
    visited = vector<bool>(graph.size(), false);
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            result++;
            dfs(i);
        }
    }

    return result;
}

int main() {

    prepare_example_graph();

    cout << "Number of connected components in graph: " << count_connected_components() << endl;

    return 0;
}