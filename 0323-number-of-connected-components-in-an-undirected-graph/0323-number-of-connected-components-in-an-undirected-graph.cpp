class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[v] = true;
        for(auto& u: adj[v]) {
            if(!vis[u]) dfs(u, adj, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto& e: edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> vis(n, false);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                res++;
                dfs(i, adj, vis);
            }
        }
        return res;
    }
};