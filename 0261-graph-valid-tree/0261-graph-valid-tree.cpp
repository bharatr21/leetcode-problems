class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis, int& sz) {
        vis[v] = true;
        for(auto& u: adj[v]) {
            if(!vis[u]) {
                sz++;
                dfs(u, adj, vis, sz);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        int sz;
        for(auto& e: edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ct = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ct++;
                sz = 0;
                dfs(i, adj, vis, sz);
            }
        }
        return (ct == 1 && sz == n - 1);
    }
};