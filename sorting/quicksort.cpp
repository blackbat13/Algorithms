#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void quick_sort(int tab[], int left, int right) {
    if (right <= left) {
        return;
    }

    int pivot = tab[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (tab[i] < pivot) {
            i++;
        }

        while (pivot < tab[j]) {
            j--;
        }

        if (i > j) {
            break;
        }

        swap(tab[i], tab[j]);

        i++;
        j--;
    }

    quick_sort(tab, left, j);
    quick_sort(tab, i, right);
}

void quick_sort_stack(int tab[], int n) {
    stack<pair<int, int> > st;
    st.push(make_pair(0, n - 1));
    while(!st.empty()) {
        pair<int, int> el = st.top();
        st.pop();
        int left = el.first;
        int right = el.second;

        if (right <= left) {
            continue;
        }

        int pivot = tab[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (tab[i] < pivot) {
                i++;
            }

            while (pivot < tab[j]) {
                j--;
            }

            if (i > j) {
                break;
            }

            swap(tab[i], tab[j]);

            i++;
            j--;
        }

        st.push(make_pair(left, j));
        st.push(make_pair(i, right));
    }
}

void quick_sort_queue(int tab[], int n) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(0, n - 1));
    while(!qu.empty()) {
        pair<int, int> el = qu.front();
        qu.pop();
        int left = el.first;
        int right = el.second;

        if (right <= left) {
            continue;
        }

        int pivot = tab[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (tab[i] < pivot) {
                i++;
            }

            while (pivot < tab[j]) {
                j--;
            }

            if (i > j) {
                break;
            }

            swap(tab[i], tab[j]);

            i++;
            j--;
        }

        qu.push(make_pair(left, j));
        qu.push(make_pair(i, right));
    }
}

int main() {
    int tab[] = {7, 2, -2, 7, 7, 293, 1, 5, 94, -5};
     quick_sort(tab, 0, 9);
//    quick_sort_stack(tab, 10);
//    quick_sort_queue(tab, 10);
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;
    return 0;
}