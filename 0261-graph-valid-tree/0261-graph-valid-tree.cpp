class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent, bool& flag)
    {
        vis[u] = 1;
        for(auto v: adj[u])
        {
            if(vis[v] && parent[u] != v && parent[u] != -1) {flag = false; break;}
            else if(!vis[v])
            {
                parent[v] = u;
                dfs(v, adj, vis, parent, flag);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int i, ct = 0;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> vis(n, 0);
        vector<int> parent(n, -1);
        for(vector<int> v: edges)
        {
            int a = v[0], b = v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(ct > 0) return false;
                ct++;
                dfs(i, adj, vis, parent, flag);
            }
        }
        return flag;
    }
};