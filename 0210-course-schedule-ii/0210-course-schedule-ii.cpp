class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, empty;
        unordered_set<int> seen;
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        queue<int> q;
        // vector<bool> vis(n, false);
        for(auto& p: prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                seen.insert(i);
                res.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()) {
            int el = q.front();
            q.pop();
            for(auto neigh: adj[el]) {
                if(--indeg[neigh] == 0 && !seen.count(neigh)) {
                    res.push_back(neigh);
                    seen.insert(neigh);
                    q.push(neigh);
                }
            }
        }
        return (seen.size() == n) ? res : empty;
    }
};