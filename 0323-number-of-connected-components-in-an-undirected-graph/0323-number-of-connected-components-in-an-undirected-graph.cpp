class Solution {
public:
    void dfs(int u, vector<int>& vis, vector<vector<int>>& adj)
    {
        vis[u] = 1;
        for(auto v: adj[u])
        {
            if(!vis[v])
            {
                dfs(v, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> vis(n, 0);
        int i, ct = 0;
        for(vector<int> v: edges)
        {
            int a = v[0], b = v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ct++;
                dfs(i, vis, adj);
            }
        }
        return ct;
    }
};