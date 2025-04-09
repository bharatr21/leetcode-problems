class Solution {
public:
    void dfs(int idx, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[idx] = true;
        for(auto& neigh: adj[idx]) {
            if(!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int>& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                res++;
                dfs(i, adj, vis);
            }
        }
        return res;
    }
};