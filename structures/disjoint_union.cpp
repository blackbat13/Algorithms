//
// Created by Damian Kurpiewski on 10.07.2017.
//

#include <iostream>
#include <vector>

using namespace std;

class DisjointUnion {
    struct Element {
        int parent, rank;

        Element(int parent, int rank) {
            this->parent = parent;
            this->rank = rank;
        }
    };

    vector<Element> subsets;
public:
    DisjointUnion(int num_of_elements) {
        for (int i = 0; i < num_of_elements; i++) {
            subsets.push_back(Element(i, 0));
        }
    }

    int find(int x) {
        if (this->subsets[x].parent != x) {
            this->subsets[x].parent = find(this->subsets[x].parent);
        }

        return this->subsets[x].parent;
    }

    void unionn(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            return;
        }

        if (this->subsets[x_root].rank < this->subsets[y_root].rank) {
            this->subsets[x_root].parent = y_root;
        } else if (this->subsets[x_root].rank > this->subsets[y_root].rank) {
            this->subsets[y_root].parent = x_root;
        } else {
            this->subsets[y_root].parent = x_root;
            this->subsets[x_root].rank += 1;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    DisjointUnion disjoint_union = DisjointUnion(10);
    disjoint_union.unionn(0, 1);
    cout << disjoint_union.is_same(0, 1) << endl;
    cout << disjoint_union.is_same(1, 2) << endl;
    return 0;
}