class DSU {
    public:
        int size;
        vector<int> parent;
        vector<int> rank;
    DSU(int n): size(n) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(int i = 0; i < n; i++) rank[i] = 1;
    }

    int findParent(int x) {
        if(parent[x] == x) return x;
        return (parent[x] = findParent(parent[x]));
    }

    void Union(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        auto dsu = DSU(n);
        for(auto& edge: edges) {
            dsu.Union(edge[0], edge[1]);
        }
        vector<unsigned int> cost(n, -1);
        for(auto& edge: edges) {
            int par = dsu.findParent(edge[0]);
            cost[par] = cost[par] & edge[2];
        }
        vector<int> res;
        for(auto& query: queries) {
            int start = query[0], end = query[1];
            if(dsu.findParent(start) != dsu.findParent(end)) {
                res.push_back(-1);
            }
            else {
                int par = dsu.findParent(start);
                res.push_back(cost[par]);
            }
        }
        return res;
    }
};