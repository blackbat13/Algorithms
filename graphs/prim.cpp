//
// Created by Damian Kurpiewski on 06.07.2017.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/// Incidence list of the weighted graph
vector<vector<pair<int, int> > > graph;

vector<vector<pair<int, int> > > min_spanning_tree;

vector<bool> visited;

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

void prim(int node) {
    priority_queue<pair<int, pair<int, int> > > edges;
    int next_node, distance, from_node;

    min_spanning_tree = vector<vector<pair<int, int> > >(graph.size());
    visited = vector<bool>(graph.size());
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        next_node = graph[node][i].first;
        distance = graph[node][i].second;
        edges.push(make_pair(-distance, make_pair(node, next_node)));
    }

    while (!edges.empty()) {
        pair<int, pair<int, int> > edge = edges.top();
        edges.pop();

        from_node = edge.second.first;
        node = edge.second.second;
        distance = -edge.first;
        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        min_spanning_tree[from_node].push_back(make_pair(node, distance));
        min_spanning_tree[node].push_back(make_pair(from_node, distance));

        for (int i = 0; i < graph[node].size(); i++) {
            next_node = graph[node][i].first;
            distance = graph[node][i].second;
            if (!visited[next_node]) {
                edges.push(make_pair(-distance, make_pair(node, next_node)));
            }
        }
    }
}

int main() {

    prepare_example_graph();

    prim(0);

    for (int i = 0; i < min_spanning_tree.size(); i++) {
        for (int j = 0; j < min_spanning_tree[i].size(); j++) {
            if (min_spanning_tree[i][j].first > i) {
                cout << i << " -(" << min_spanning_tree[i][j].second << ")-> " << min_spanning_tree[i][j].first << endl;
            }
        }
    }

    return 0;
}