class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> res, emp, indeg(n, 0);
        vector<bool> vis(n, false);
        for(vector<int>& e: prerequisites) {
            int a = e[0], b = e[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto idx = q.front();
            q.pop();
            vis[idx] = true;
            res.push_back(idx);
            for(auto& neigh: adj[idx]) {
                if(!vis[neigh] && --indeg[neigh] == 0) q.push(neigh);
            }
        }
        return (res.size() == n) ? res: emp;
    }
};