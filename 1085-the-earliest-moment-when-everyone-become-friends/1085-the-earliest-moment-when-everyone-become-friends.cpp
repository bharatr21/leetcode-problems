class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int numComponents;
    UnionFind(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
        numComponents = n;
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool isSameComponent(int x, int y) {
        return (find(x) == find(y));
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int xpar = find(x);
        int ypar = find(y);
        if(xpar == ypar) return false;
        if(rank[xpar] >= rank[ypar]) {
            parent[ypar] = xpar;
            rank[xpar] += rank[ypar];
        }
        else {
            parent[xpar] = ypar;
            rank[ypar] += rank[xpar];
        }
        numComponents--;
        return true;
    }

    int getNumComponents() {
        return numComponents;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UnionFind uf = UnionFind(n);
        for(vector<int> v: logs) {
            int timestamp = v[0], a = v[1], b = v[2];
            bool flag = uf._union(a, b);
            if(uf.getNumComponents() == 1) return timestamp;
        }
        return -1;
    }
};