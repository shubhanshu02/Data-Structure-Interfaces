#include <iostream>
using namespace std;
#define capacity 1000

class disjointSet {
    int parent[capacity];
    int rank[capacity];
    public:
        disjointSet() {
            for (int i = 0; i< capacity; i++) {
                rank[i] = -1;
                parent[i] = -1;
            }
        }
        void makeSet(int i) {
            parent[i] = i;
            rank[i] = 0;
        }
        int find(int i) {
            if (parent[i] == -1) return -1;
            while (i != parent[i]) {
                i = parent[i];
            }
            return i;
        }
        void Union(int i, int j) {
            if (parent[i] == -1 && parent[j] == -1) return;
            int i_id = find(i);
            int j_id = find(j);
            if (i_id == j_id) return;
            if (rank[i_id] > rank[j_id]) {
                parent[j_id] = i_id;
            }
            else {
                parent[i_id] = j_id;
                if (rank[i_id] == rank[j_id]) rank[j_id]++;
            }
        }
};

int main() {
    disjointSet d;
    d.makeSet(5);
    d.makeSet(2);
    d.makeSet(1);
    d.makeSet(4);
    d.Union(1,2);
    d.find(4);
}