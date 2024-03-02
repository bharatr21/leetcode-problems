class Solution {
public:
    void topo(int v, vector<int>& indeg, vector<vector<int>>& adj, vector<int>& res, vector<int>& vis)
    {
        for(int u: adj[v])
        {
            indeg[u]--;
            if(indeg[u] == 0 && !vis[u])
            {
                vis[u] = 1;
                res.push_back(u);
                topo(u, indeg, adj, res, vis);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, i;
        vector<int> res;
        vector<int> indeg(n, 0);
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for(vector<int> v: prerequisites)
        {
            int a = v[0], b = v[1];
            indeg[a]++;
            adj[b].push_back(a);
        }
        for(i = 0; i < n; i++)
        {
            if(indeg[i] == 0 && !vis[i])
            {
                vis[i] = 1;
                res.push_back(i);
                topo(i, indeg, adj, res, vis);
            }
        }
        return (res.size() == n);
    }
};