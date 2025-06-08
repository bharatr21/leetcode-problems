class Solution {
public:
    int cycleStart = -1;
    void dfs(int idx, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& parent) {
        vis[idx] = true;
        for(auto neigh: adj[idx]) {
            if(!vis[neigh]) {
                parent[neigh] = idx;
                dfs(neigh, adj, vis, parent);
            } else if(neigh != parent[idx] && cycleStart == -1) {
                cycleStart = neigh;
                parent[neigh] = idx;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1, false);
        vector<int> parent(n+1);
        for(vector<int>& e: edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, adj, vis, parent);
        unordered_map<int, int> cycleset;
        cycleset[cycleStart] = 1;
        int node = parent[cycleStart];
        while(node != cycleStart) {
            cycleset[node] = 1;
            node = parent[node];
        }
        for(int i = edges.size() - 1; i >= 0; i--) {
            vector<int> e = edges[i];
            int a = e[0], b = e[1];
            if(cycleset.count(a) && cycleset.count(b)) return e;
        }
        return {};
    }
};