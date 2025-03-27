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

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        for(int i = 0; i < n; i++) {
            set<int> tmp(properties[i].begin(), properties[i].end());
            vector<int> vt(tmp.begin(), tmp.end());
            properties[i] = vt;
        }
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // set<int> res;
                vector<int> res;
                auto it = set_intersection(properties[i].begin(), properties[i].end(), properties[j].begin(), properties[j].end(), back_inserter(res));
                unordered_set<int> s(res.begin(), res.end());
                if(s.size() >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int comps = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                comps++;
                dfs(i, adj, vis);
            }
        }
        return comps;
    }
};