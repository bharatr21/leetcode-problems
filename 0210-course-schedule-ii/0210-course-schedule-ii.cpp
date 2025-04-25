class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, emp;
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        for(vector<int>& e: prerequisites) {
            int a = e[0], b = e[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            res.push_back(c);
            if(vis[c]) continue;
            else {
                vis[c] = true;
                for(auto& neigh: adj[c]) {
                    if(!vis[neigh] && --indeg[neigh] == 0) q.push(neigh);
                }
            }
        }
        return ((res.size() == n) ? res : emp);
    }
};