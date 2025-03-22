class Solution {
public:
    bool isComplete(vector<int>& component, vector<vector<int>>& adj) {
        int n = component.size();
        for(auto& v: component) {
            if(adj[v].size() < n - 1) return false;
        }
        return true;
    }

    void dfs(int v, vector<int>& component, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[v] = true;
        component.push_back(v);
        for(auto& u: adj[v]) {
            if(!vis[u]) dfs(u, component, adj, vis);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        vector<int> component;
        int res = 0;
        for(int i = 0; i < n; i++) {
            component.clear();
            if(!vis[i]){
                dfs(i, component, adj, vis);
            }
            // for(auto& u: component) cout << u << ' ';
            // cout << endl;
            if(!component.empty() && isComplete(component, adj)) res++;
        }
        return res;
    }
};