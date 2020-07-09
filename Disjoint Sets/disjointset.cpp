#include <iostream>
using namespace std;
#define capacity 1000

class disjointSet {
    int parent[capacity];
    int rank[capacity];
    public:
        disjointSet() {
            for (int i = 0; i< capacity; i++) {
                rank[i] = 0;
                parent[i] = i;
            }
        }
        void makeSet(int i) {
            parent[i] = i;
            rank[i] = 0;
        }
        int find(int i) {
            while (i != parent[i]) {
                i = parent[i];
            }
            return i;
        }
        void union(int i, int j) {
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