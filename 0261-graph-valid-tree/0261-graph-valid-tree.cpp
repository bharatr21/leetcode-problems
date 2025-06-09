class Solution {
public:
    bool cycle = false;
    void dfs(int idx, vector<vector<int>>& adj, unordered_set<int>& vis, vector<int>& parent) {
        vis.insert(idx);
        for(auto& neigh: adj[idx]) {
            if(!vis.count(neigh)) {
                parent[neigh] = idx;
                dfs(neigh, adj, vis, parent);
            } else if(parent[idx] != neigh && parent[idx] != -1) {
                cycle = true;
                break;
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_set<int> vis;
        vector<int> parent(n, -1);
        for(vector<int>& e: edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, adj, vis, parent);
        return (vis.size() == n && !cycle);
    }
};