class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(vector<int>& e: prerequisites) {
            int a = e[0], b = e[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        unordered_set<int> vis;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto idx = q.front();
            q.pop();
            vis.insert(idx);
            for(auto& neigh: adj[idx]) {
                if(--indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return (vis.size() == n);
    }
};