class Solution {
public:
    void dfs(int idx, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[idx] = true;
        for(auto& neigh: adj[idx]) {
            if(!vis[neigh]) dfs(neigh, adj, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) adj[i].push_back(j);
            }
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