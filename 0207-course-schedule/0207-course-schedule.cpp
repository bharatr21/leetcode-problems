class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for(vector<int> pre: prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        unordered_set<int> vis;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            vis.insert(u);
            for(int v: adj[u]) {
                if(--indeg[v] == 0 && !vis.count(v)) q.push(v);
            }
        }
        return (vis.size() == n);
    }
};